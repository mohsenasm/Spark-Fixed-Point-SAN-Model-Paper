#ifndef _Q84_PVS_
#define _Q84_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Q84/Q84SAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class Q84PV0Worker:public SteadyState
{
 public:
  Q84SAN *Q84;
  
  Q84PV0Worker();
  ~Q84PV0Worker();
  double Reward_Function();
};

class Q84PV0:public PerformanceVariableNode
{
 public:
  Q84SAN *TheQ84SAN;

  Q84PV0Worker *Q84PV0WorkerList;

  Q84PV0(int timeindex=0);
  ~Q84PV0();
  void CreateWorkerList(void);
};

class Q84PV1Worker:public SteadyState
{
 public:
  Q84SAN *Q84;
  
  Q84PV1Worker();
  ~Q84PV1Worker();
  double Reward_Function();
};

class Q84PV1:public PerformanceVariableNode
{
 public:
  Q84SAN *TheQ84SAN;

  Q84PV1Worker *Q84PV1WorkerList;

  Q84PV1(int timeindex=0);
  ~Q84PV1();
  void CreateWorkerList(void);
};

class Q84PV2Worker:public SteadyState
{
 public:
  Q84SAN *Q84;
  
  Q84PV2Worker();
  ~Q84PV2Worker();
  double Reward_Function();
};

class Q84PV2:public PerformanceVariableNode
{
 public:
  Q84SAN *TheQ84SAN;

  Q84PV2Worker *Q84PV2WorkerList;

  Q84PV2(int timeindex=0);
  ~Q84PV2();
  void CreateWorkerList(void);
};

class Q84PV3Worker:public SteadyState
{
 public:
  Q84SAN *Q84;
  
  Q84PV3Worker();
  ~Q84PV3Worker();
  double Reward_Function();
};

class Q84PV3:public PerformanceVariableNode
{
 public:
  Q84SAN *TheQ84SAN;

  Q84PV3Worker *Q84PV3WorkerList;

  Q84PV3(int timeindex=0);
  ~Q84PV3();
  void CreateWorkerList(void);
};

#endif
