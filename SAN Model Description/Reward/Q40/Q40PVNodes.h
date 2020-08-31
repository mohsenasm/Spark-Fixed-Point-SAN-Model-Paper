#ifndef _Q40_PVS_
#define _Q40_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Q40/Q40SAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"


class Q40PV0Worker:public SteadyState
{
 public:
  Q40SAN *Q40;
  
  Q40PV0Worker();
  ~Q40PV0Worker();
  double Reward_Function();
};

class Q40PV0:public PerformanceVariableNode
{
 public:
  Q40SAN *TheQ40SAN;

  Q40PV0Worker *Q40PV0WorkerList;

  Q40PV0(int timeindex=0);
  ~Q40PV0();
  void CreateWorkerList(void);
};

class Q40PV1Worker:public SteadyState
{
 public:
  Q40SAN *Q40;
  
  Q40PV1Worker();
  ~Q40PV1Worker();
  double Reward_Function();
};

class Q40PV1:public PerformanceVariableNode
{
 public:
  Q40SAN *TheQ40SAN;

  Q40PV1Worker *Q40PV1WorkerList;

  Q40PV1(int timeindex=0);
  ~Q40PV1();
  void CreateWorkerList(void);
};

class Q40PV2Worker:public SteadyState
{
 public:
  Q40SAN *Q40;
  
  Q40PV2Worker();
  ~Q40PV2Worker();
  double Reward_Function();
};

class Q40PV2:public PerformanceVariableNode
{
 public:
  Q40SAN *TheQ40SAN;

  Q40PV2Worker *Q40PV2WorkerList;

  Q40PV2(int timeindex=0);
  ~Q40PV2();
  void CreateWorkerList(void);
};

class Q40PV3Worker:public SteadyState
{
 public:
  Q40SAN *Q40;
  
  Q40PV3Worker();
  ~Q40PV3Worker();
  double Reward_Function();
};

class Q40PV3:public PerformanceVariableNode
{
 public:
  Q40SAN *TheQ40SAN;

  Q40PV3Worker *Q40PV3WorkerList;

  Q40PV3(int timeindex=0);
  ~Q40PV3();
  void CreateWorkerList(void);
};

#endif
