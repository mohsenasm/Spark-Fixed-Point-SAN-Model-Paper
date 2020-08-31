#ifndef _Q20_PVMODEL_
#define _Q20_PVMODEL_
#include "Q20PVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Q20/Q20SAN.h"
class Q20PVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  Q20PVModel(bool expandtimepoints);
};

#endif
