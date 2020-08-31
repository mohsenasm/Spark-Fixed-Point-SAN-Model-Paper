#include "Q84PVNodes.h"

Q84PV0Worker::Q84PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q84);
}

Q84PV0Worker::~Q84PV0Worker() {
  delete [] TheModelPtr;
}

double Q84PV0Worker::Reward_Function(void) {

if ( 
	(Q84->PDone3->Mark() == (cnt3-1)) && 
	(Q84->PRunning3->Mark() > 0)
)
	return (1.0 / avg3)*(double)(Q84->PRunning3->Mark());
else
	return 0.0;

return (0);



}

Q84PV0::Q84PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ84SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("throughput",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PDone3","Q84");
  AddVariableDependency("PRunning3","Q84");
}

Q84PV0::~Q84PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q84PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q84PV0Worker;
}
Q84PV1Worker::Q84PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q84);
}

Q84PV1Worker::~Q84PV1Worker() {
  delete [] TheModelPtr;
}

double Q84PV1Worker::Reward_Function(void) {

return (double)(Q84->PRunning1->Mark())*(1.0/avg1) 
	 + (double)(Q84->PRunning2->Mark())*(1.0/avg2)
	 + (double)(Q84->PRunning3->Mark())*(1.0/avg3);

return (0);



}

Q84PV1::Q84PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ84SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateReturn",(RewardType)3,1, startpts, stoppts, timeindex, 0,3, 3);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q84");
  AddVariableDependency("PRunning2","Q84");
  AddVariableDependency("PRunning3","Q84");
}

Q84PV1::~Q84PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q84PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q84PV1Worker;
}
Q84PV2Worker::Q84PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q84);
}

Q84PV2Worker::~Q84PV2Worker() {
  delete [] TheModelPtr;
}

double Q84PV2Worker::Reward_Function(void) {

if (
	(Q84->PRunning1->Mark()+Q84->PDone1->Mark() == cnt1 && Q84->PRunning2->Mark()+Q84->PDone2->Mark() == cnt2) ||
	Q84->PRunning3->Mark()+Q84->PDone3->Mark() == cnt3 ||
	Q84->PStart->Mark() >= cntUser
) 
	return 1; 
else 
	return 0;

return (0);



}

Q84PV2::Q84PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ84SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("pInactive",(RewardType)3,1, startpts, stoppts, timeindex, 0,7, 7);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q84");
  AddVariableDependency("PDone1","Q84");
  AddVariableDependency("PRunning2","Q84");
  AddVariableDependency("PDone2","Q84");
  AddVariableDependency("PRunning3","Q84");
  AddVariableDependency("PDone3","Q84");
  AddVariableDependency("PStart","Q84");
}

Q84PV2::~Q84PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q84PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q84PV2Worker;
}
Q84PV3Worker::Q84PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q84);
}

Q84PV3Worker::~Q84PV3Worker() {
  delete [] TheModelPtr;
}

double Q84PV3Worker::Reward_Function(void) {

if (Q84->PDone1->Mark() == cnt1 - 1)
	return 0.1/avg1;
if (Q84->PDone2->Mark() == cnt2 - 1)
	return 0.1/avg2;
if (Q84->PStart->Mark() > 0)
	return rateThink*(double)(Q84->PStart->Mark());
else
	return 0;

return (0);



}

Q84PV3::Q84PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ84SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateActive",(RewardType)3,1, startpts, stoppts, timeindex, 0,3, 3);
  Type = steady_state;
  AddVariableDependency("PDone1","Q84");
  AddVariableDependency("PDone2","Q84");
  AddVariableDependency("PStart","Q84");
}

Q84PV3::~Q84PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q84PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q84PV3Worker;
}
