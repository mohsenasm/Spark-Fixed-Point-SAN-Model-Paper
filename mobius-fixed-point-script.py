#!/usr/bin/env python3
import fileinput
import re
import subprocess
import os

print("The Fixed-point script for three YARN queues")
licCode = "licence goes here"
homeAddress = "address of the mobius project"
queries = [52, 20, 84]
lpInactive = [0.01] * len(queries)  # last probability of the queue in idle state
lRateReturn = [0.005] * len(queries)  # last rate for task accomplishment in the queue
lRateActive = [0.00001] * len(queries)  # last rate for queue transition from idle state to active state
lThroughput = [0.6] * len(queries)  # last value for the queue's throughput
pThroughput = [0.1] * len(queries)  # previous value for the queue's throughput
converge = False
delta = 0.01  # convergence threshold
iteration_number = 1

devnull = open(os.devnull, 'w')


def make_study(queue_number):
    subprocess.run(
        ["make", "-C", homeAddress + "/Study/Q{}".format(queries[queue_number]), "PLATFORM=u1604", "debug",
         "FORCE_ARCH=-m64"],
        stdout=devnull, stderr=devnull, check=True)


def make_transformer(queue_number):
    subprocess.run(
        ["make", "-C", homeAddress + "/Transformer/Q{}".format(queries[queue_number]), "PLATFORM=u1604", "opt",
         "FORCE_ARCH=-m64"],
        stdout=devnull, stderr=devnull, check=True)
    subprocess.run(
        [homeAddress + "/Transformer/Q{}/Q{}Gen_linux".format(queries[queue_number], queries[queue_number]),
         "-B0", "-P", homeAddress + "/Transformer/Q{}/".format(queries[queue_number]),
         "-NExperiment_1", "-L", "/tmp/" + licCode, "-h0.5", "-F1"],
        stdout=devnull, stderr=devnull, check=True)


def solve(queue_number):
    subprocess.run(["make", "-C", homeAddress + "/Solver/Q{}".format(queries[queue_number]), "PLATFORM=u1604", "opt"],
                   stdout=devnull, stderr=devnull, check=True)
    subprocess.run(
        [homeAddress + "/Solver/Q{}/Q{}_linux".format(queries[queue_number], queries[queue_number]), "-s",
         homeAddress + "/Solver/Q{}/".format(queries[queue_number]), "-P", "FixedPointMR", "-G",
         homeAddress + "/Transformer/Q{}/".format(queries[queue_number]), "-S", "Q{}".format(queries[queue_number]),
         "-E", "Experiment_1", "-v9", "-o",
         homeAddress + "/Solver/Q{}/Q{}_Experiment_1.txt".format(queries[queue_number], queries[queue_number]),
         "-a", "9", "-w", "1.0", "-m", "300000"],
        stdout=devnull, stderr=devnull, check=True)


def sum_all_but(array, index):
    sum = 0
    for j in range(len(array)):
        if j != index:
            sum += array[j]
    return sum


def multiply_all_but(array, index):
    mult = 1
    for j in range(len(array)):
        if j != index:
            mult *= array[j]
    return mult


def update_queue(queue_number):
    current_rate_active = sum_all_but(lRateActive, queue_number)
    current_rate_return = sum_all_but(lRateReturn, queue_number)
    current_rate_inactive = (multiply_all_but(lpInactive, queue_number) * current_rate_active) / (
            1.0 - multiply_all_but(lpInactive, queue_number))
    with fileinput.FileInput(
            homeAddress + "/Study/Q{}/Q{}SetStudy.cpp".format(queries[queue_number], queries[queue_number]),
            inplace=True, backup='.bak') as file:
        for line in file:
            temp_line = re.sub("rateActiveValues\[0\]\s=\s.*;",
                               r"rateActiveValues[0] = " + str(current_rate_active) + ";", line)
            temp_line = re.sub("rateReturnValues\[0\]\s=\s.*;",
                               r"rateReturnValues[0] = " + str(current_rate_return) + ";", temp_line)
            temp_line = re.sub("rateInactiveValues\[0\]\s=\s.*;",
                               r"rateInactiveValues[0] = " + str(current_rate_inactive) + ";", temp_line)
            print(temp_line, end='')
    with fileinput.FileInput(homeAddress + "/Study/Q{}/Q{}.ssd".format(queries[queue_number], queries[queue_number]),
                             inplace=True, backup='.bak') as file:
        for line in file:
            temp_line = re.sub("<string id=\"9\">\d+(\.\d*)?</string>",
                               "<string id=\"9\">" + str(current_rate_active) + "</string>", line)
            temp_line = re.sub("<string id=\"11\">\d+(\.\d*)?</string>",
                               "<string id=\"11\">" + str(current_rate_return) + "</string>", temp_line)
            temp_line = re.sub("<string id=\"10\">\d+(\.\d*)?</string>",
                               "<string id=\"10\">" + str(current_rate_inactive) + "</string>", temp_line)
            print(temp_line, end='')


def update_parameters_from_queue(queue_number):
    global lThroughput, lRateActive, lpInactive, lRateReturn
    with open(homeAddress + "/Solver/Q{}/Q{}_Experiment_1.txt".format(queries[queue_number], queries[queue_number]),
              "r") as input:
        lines = input.readlines()
        for index in range(len(lines)):
            line = lines[index]
            next_line = lines[index + 1] if index + 1 < len(lines) else ""
            if line.startswith("Performance variable :  throughput"):
                lThroughput[queue_number] = float(next_line.split(":")[1])
            elif line.startswith("Performance variable :  rateActive"):
                lRateActive[queue_number] = float(next_line.split(":")[1])
            elif line.startswith("Performance variable :  pInactive"):
                lpInactive[queue_number] = float(next_line.split(":")[1])
            elif line.startswith("Performance variable :  rateReturn"):
                lRateReturn[queue_number] = float(next_line.split(":")[1])


while not converge:
    print("Iteration {}:".format(iteration_number))
    converge = True
    for i in range(len(queries)):
        update_queue(i)
        make_study(i)
        make_transformer(i)
        solve(i)
        update_parameters_from_queue(i)
        print("Queue{} throughput: {}".format(i, lThroughput[i]))
        print("Queue{} rateActive: {}".format(i, lRateActive[i]))
        print("Queue{} rateReturn: {}".format(i, lRateReturn[i]))
        print("Queue{} pInactive: {}".format(i, lpInactive[i]))
        if abs(lThroughput[i] - pThroughput[i]) / pThroughput[i] >= delta:
            converge = False
        pThroughput[i] = lThroughput[i]
    iteration_number += 1
