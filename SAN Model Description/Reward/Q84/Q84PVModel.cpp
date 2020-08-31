#include "Q84PVModel.h"

Q84PVModel::Q84PVModel(bool expandTimeArrays) {
  TheModel=new Q84SAN();
  DefineName("Q84PVModel");
  CreatePVList(4, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* Q84PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new Q84PV0(timeindex);
    break;
  case 1:
    return new Q84PV1(timeindex);
    break;
  case 2:
    return new Q84PV2(timeindex);
    break;
  case 3:
    return new Q84PV3(timeindex);
    break;
  }
  return NULL;
}
