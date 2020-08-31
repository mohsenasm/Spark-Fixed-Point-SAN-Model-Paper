#include "Q52PVModel.h"

Q52PVModel::Q52PVModel(bool expandTimeArrays) {
  TheModel=new Q52SAN();
  DefineName("Q52PVModel");
  CreatePVList(4, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* Q52PVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new Q52PV0(timeindex);
    break;
  case 1:
    return new Q52PV1(timeindex);
    break;
  case 2:
    return new Q52PV2(timeindex);
    break;
  case 3:
    return new Q52PV3(timeindex);
    break;
  }
  return NULL;
}
