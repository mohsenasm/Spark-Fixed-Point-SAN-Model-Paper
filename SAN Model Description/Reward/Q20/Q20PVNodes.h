#ifndef _Q20_PVS_
#define _Q20_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Q20/Q20SAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class Q20PV0Worker:public SteadyState
{
 public:
  Q20SAN *Q20;
  
  Q20PV0Worker();
  ~Q20PV0Worker();
  double Reward_Function();
};

class Q20PV0:public PerformanceVariableNode
{
 public:
  Q20SAN *TheQ20SAN;

  Q20PV0Worker *Q20PV0WorkerList;

  Q20PV0(int timeindex=0);
  ~Q20PV0();
  void CreateWorkerList(void);
};

class Q20PV1Worker:public SteadyState
{
 public:
  Q20SAN *Q20;
  
  Q20PV1Worker();
  ~Q20PV1Worker();
  double Reward_Function();
};

class Q20PV1:public PerformanceVariableNode
{
 public:
  Q20SAN *TheQ20SAN;

  Q20PV1Worker *Q20PV1WorkerList;

  Q20PV1(int timeindex=0);
  ~Q20PV1();
  void CreateWorkerList(void);
};

class Q20PV2Worker:public SteadyState
{
 public:
  Q20SAN *Q20;
  
  Q20PV2Worker();
  ~Q20PV2Worker();
  double Reward_Function();
};

class Q20PV2:public PerformanceVariableNode
{
 public:
  Q20SAN *TheQ20SAN;

  Q20PV2Worker *Q20PV2WorkerList;

  Q20PV2(int timeindex=0);
  ~Q20PV2();
  void CreateWorkerList(void);
};

class Q20PV3Worker:public SteadyState
{
 public:
  Q20SAN *Q20;
  
  Q20PV3Worker();
  ~Q20PV3Worker();
  double Reward_Function();
};

class Q20PV3:public PerformanceVariableNode
{
 public:
  Q20SAN *TheQ20SAN;

  Q20PV3Worker *Q20PV3WorkerList;

  Q20PV3(int timeindex=0);
  ~Q20PV3();
  void CreateWorkerList(void);
};

#endif
