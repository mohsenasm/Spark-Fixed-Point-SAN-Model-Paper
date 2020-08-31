#include "Q20PVModel.h"

Q20PVModel::Q20PVModel(bool expandTimeArrays) {
  TheModel=new Q20SAN();
  DefineName("Q20PVModel");
  CreatePVList(4, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* Q20PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new Q20PV0(timeindex);
    break;
  case 1:
    return new Q20PV1(timeindex);
    break;
  case 2:
    return new Q20PV2(timeindex);
    break;
  case 3:
    return new Q20PV3(timeindex);
    break;
  }
  return NULL;
}
