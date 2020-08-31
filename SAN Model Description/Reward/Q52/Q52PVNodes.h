#ifndef _Q52_PVS_
#define _Q52_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Q52/Q52SAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class Q52PV0Worker:public SteadyState
{
 public:
  Q52SAN *Q52;
  
  Q52PV0Worker();
  ~Q52PV0Worker();
  double Reward_Function();
};

class Q52PV0:public PerformanceVariableNode
{
 public:
  Q52SAN *TheQ52SAN;

  Q52PV0Worker *Q52PV0WorkerList;

  Q52PV0(int timeindex=0);
  ~Q52PV0();
  void CreateWorkerList(void);
};

class Q52PV1Worker:public SteadyState
{
 public:
  Q52SAN *Q52;
  
  Q52PV1Worker();
  ~Q52PV1Worker();
  double Reward_Function();
};

class Q52PV1:public PerformanceVariableNode
{
 public:
  Q52SAN *TheQ52SAN;

  Q52PV1Worker *Q52PV1WorkerList;

  Q52PV1(int timeindex=0);
  ~Q52PV1();
  void CreateWorkerList(void);
};

class Q52PV2Worker:public SteadyState
{
 public:
  Q52SAN *Q52;
  
  Q52PV2Worker();
  ~Q52PV2Worker();
  double Reward_Function();
};

class Q52PV2:public PerformanceVariableNode
{
 public:
  Q52SAN *TheQ52SAN;

  Q52PV2Worker *Q52PV2WorkerList;

  Q52PV2(int timeindex=0);
  ~Q52PV2();
  void CreateWorkerList(void);
};

class Q52PV3Worker:public SteadyState
{
 public:
  Q52SAN *Q52;
  
  Q52PV3Worker();
  ~Q52PV3Worker();
  double Reward_Function();
};

class Q52PV3:public PerformanceVariableNode
{
 public:
  Q52SAN *TheQ52SAN;

  Q52PV3Worker *Q52PV3WorkerList;

  Q52PV3(int timeindex=0);
  ~Q52PV3();
  void CreateWorkerList(void);
};

#endif
