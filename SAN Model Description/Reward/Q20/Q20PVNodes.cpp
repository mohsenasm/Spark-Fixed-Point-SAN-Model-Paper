#include "Q20PVNodes.h"

Q20PV0Worker::Q20PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q20);
}

Q20PV0Worker::~Q20PV0Worker() {
  delete [] TheModelPtr;
}

double Q20PV0Worker::Reward_Function(void) {

if ( 
	(Q20->PDone3->Mark() == (cnt3-1)) && 
	(Q20->PRunning3->Mark() > 0)
)
	return (1.0 / avg3)*(double)(Q20->PRunning3->Mark());
else
	return 0.0;

return (0);



}

Q20PV0::Q20PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ20SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("throughput",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PDone3","Q20");
  AddVariableDependency("PRunning3","Q20");
}

Q20PV0::~Q20PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q20PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q20PV0Worker;
}
Q20PV1Worker::Q20PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q20);
}

Q20PV1Worker::~Q20PV1Worker() {
  delete [] TheModelPtr;
}

double Q20PV1Worker::Reward_Function(void) {

return (double)(Q20->PRunning1->Mark())*(1.0/avg1) 
	 + (double)(Q20->PRunning2->Mark())*(1.0/avg2)
	 + (double)(Q20->PRunning3->Mark())*(1.0/avg3);

return (0);



}

Q20PV1::Q20PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ20SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateReturn",(RewardType)3,1, startpts, stoppts, timeindex, 0,3, 3);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q20");
  AddVariableDependency("PRunning2","Q20");
  AddVariableDependency("PRunning3","Q20");
}

Q20PV1::~Q20PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q20PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q20PV1Worker;
}
Q20PV2Worker::Q20PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q20);
}

Q20PV2Worker::~Q20PV2Worker() {
  delete [] TheModelPtr;
}

double Q20PV2Worker::Reward_Function(void) {

if (
	Q20->PRunning1->Mark()+Q20->PDone1->Mark() == cnt1 ||
	Q20->PRunning2->Mark()+Q20->PDone2->Mark() == cnt2 ||
	Q20->PRunning3->Mark()+Q20->PDone3->Mark() == cnt3 ||
	Q20->PStart->Mark() >= cntUser
) 
	return 1; 
else 
	return 0;

return (0);



}

Q20PV2::Q20PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ20SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("pInactive",(RewardType)3,1, startpts, stoppts, timeindex, 0,7, 7);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q20");
  AddVariableDependency("PDone1","Q20");
  AddVariableDependency("PRunning2","Q20");
  AddVariableDependency("PDone2","Q20");
  AddVariableDependency("PRunning3","Q20");
  AddVariableDependency("PDone3","Q20");
  AddVariableDependency("PStart","Q20");
}

Q20PV2::~Q20PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q20PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q20PV2Worker;
}
Q20PV3Worker::Q20PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q20);
}

Q20PV3Worker::~Q20PV3Worker() {
  delete [] TheModelPtr;
}

double Q20PV3Worker::Reward_Function(void) {

if (Q20->PDone1->Mark() == cnt1 - 1)
	return 0.1/avg1;
if (Q20->PDone2->Mark() == cnt2 - 1)
	return 0.1/avg2;
if (Q20->PStart->Mark() > 0)
	return rateThink*(double)(Q20->PStart->Mark());
else
	return 0;

return (0);



}

Q20PV3::Q20PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ20SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateActive",(RewardType)3,1, startpts, stoppts, timeindex, 0,3, 3);
  Type = steady_state;
  AddVariableDependency("PDone1","Q20");
  AddVariableDependency("PDone2","Q20");
  AddVariableDependency("PStart","Q20");
}

Q20PV3::~Q20PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q20PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q20PV3Worker;
}
