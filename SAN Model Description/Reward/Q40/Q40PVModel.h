#ifndef _Q40_PVMODEL_
#define _Q40_PVMODEL_
#include "Q40PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Q40/Q40SAN.h"
class Q40PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  Q40PVModel(bool expandtimepoints);
};

#endif
