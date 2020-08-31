#include "Q52PVNodes.h"

Q52PV0Worker::Q52PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q52);
}

Q52PV0Worker::~Q52PV0Worker() {
  delete [] TheModelPtr;
}

double Q52PV0Worker::Reward_Function(void) {

if ( 
	(Q52->placeReduced->Mark() == (NumberOfReduces-1)) && 
	(Q52->placeReducesReady->Mark() > 0)
)
	return (1.0 / ReduceBeta)*(double)(Q52->placeReducesReady->Mark());
else
	return 0.0;

return (0);



}

Q52PV0::Q52PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ52SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("throughput",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("placeReduced","Q52");
  AddVariableDependency("placeReducesReady","Q52");
}

Q52PV0::~Q52PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q52PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q52PV0Worker;
}
Q52PV1Worker::Q52PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q52);
}

Q52PV1Worker::~Q52PV1Worker() {
  delete [] TheModelPtr;
}

double Q52PV1Worker::Reward_Function(void) {

return (double)(Q52->placeMapsReady->Mark())*(1.0/(MapM*MapBeta)) + 
	(double)(Q52->placeReducesReady->Mark())*(1.0/(ReduceM*ReduceBeta));

return (0);



}

Q52PV1::Q52PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ52SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateReturn",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("placeMapsReady","Q52");
  AddVariableDependency("placeReducesReady","Q52");
}

Q52PV1::~Q52PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q52PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q52PV1Worker;
}
Q52PV2Worker::Q52PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q52);
}

Q52PV2Worker::~Q52PV2Worker() {
  delete [] TheModelPtr;
}

double Q52PV2Worker::Reward_Function(void) {

if (
Q52->placeMapsReady->Mark()+Q52->placeMaped->Mark() == NumberOfMaps ||
Q52->placeReducesReady->Mark()+Q52->placeReduced->Mark() == NumberOfReduces ||
Q52->placeStart->Mark() > 0
) 
	return 1; 
else 
	return 0;

return (0);



}

Q52PV2::Q52PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ52SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("pInactive",(RewardType)3,1, startpts, stoppts, timeindex, 0,5, 5);
  Type = steady_state;
  AddVariableDependency("placeMapsReady","Q52");
  AddVariableDependency("placeMaped","Q52");
  AddVariableDependency("placeReducesReady","Q52");
  AddVariableDependency("placeReduced","Q52");
  AddVariableDependency("placeStart","Q52");
}

Q52PV2::~Q52PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q52PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q52PV2Worker;
}
Q52PV3Worker::Q52PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q52);
}

Q52PV3Worker::~Q52PV3Worker() {
  delete [] TheModelPtr;
}

double Q52PV3Worker::Reward_Function(void) {

if (Q52->placeMaped->Mark() == NumberOfMaps - 1)
	return 0.1/MapBeta;
if (Q52->placeStart->Mark() > 0)
	return ThinkRate;
else
	return 0;

return (0);



}

Q52PV3::Q52PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ52SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateActive",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("placeMaped","Q52");
  AddVariableDependency("placeStart","Q52");
}

Q52PV3::~Q52PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q52PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q52PV3Worker;
}
