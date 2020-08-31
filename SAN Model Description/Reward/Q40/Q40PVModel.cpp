#include "Q40PVModel.h"

Q40PVModel::Q40PVModel(bool expandTimeArrays) {
  TheModel=new Q40SAN();
  DefineName("Q40PVModel");
  CreatePVList(4, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* Q40PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new Q40PV0(timeindex);
    break;
  case 1:
    return new Q40PV1(timeindex);
    break;
  case 2:
    return new Q40PV2(timeindex);
    break;
  case 3:
    return new Q40PV3(timeindex);
    break;
  }
  return NULL;
}
