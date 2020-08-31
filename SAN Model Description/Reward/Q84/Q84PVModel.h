#ifndef _Q84_PVMODEL_
#define _Q84_PVMODEL_
#include "Q84PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Q84/Q84SAN.h"
class Q84PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  Q84PVModel(bool expandtimepoints);
};

#endif
