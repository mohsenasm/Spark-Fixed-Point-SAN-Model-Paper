#ifndef _Q52_PVMODEL_
#define _Q52_PVMODEL_
#include "Q52PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Q52/Q52SAN.h"
class Q52PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  Q52PVModel(bool expandtimepoints);
};

#endif
