#include "Q40PVNodes.h"

Q40PV0Worker::Q40PV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q40);
}

Q40PV0Worker::~Q40PV0Worker() {
  delete [] TheModelPtr;
}

double Q40PV0Worker::Reward_Function(void) {

if ( 
	(Q40->PDone4->Mark() == (cnt4-1)) && 
	(Q40->PRunning4->Mark() > 0)
)
	return (1.0 / avg4)*(double)(Q40->PRunning4->Mark());
else
	return 0.0;

return (0);



}

Q40PV0::Q40PV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ40SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("throughput",(RewardType)3,1, startpts, stoppts, timeindex, 0,2, 2);
  Type = steady_state;
  AddVariableDependency("PDone4","Q40");
  AddVariableDependency("PRunning4","Q40");
}

Q40PV0::~Q40PV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q40PV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q40PV0Worker;
}
Q40PV1Worker::Q40PV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q40);
}

Q40PV1Worker::~Q40PV1Worker() {
  delete [] TheModelPtr;
}

double Q40PV1Worker::Reward_Function(void) {

return (double)(Q40->PRunning1->Mark())*(1.0/avg1) 
	 + (double)(Q40->PRunning2->Mark())*(1.0/avg2)
	 + (double)(Q40->PRunning3->Mark())*(1.0/avg3)
	 + (double)(Q40->PRunning4->Mark())*(1.0/avg4);

return (0);



}

Q40PV1::Q40PV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ40SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateReturn",(RewardType)3,1, startpts, stoppts, timeindex, 0,4, 4);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q40");
  AddVariableDependency("PRunning2","Q40");
  AddVariableDependency("PRunning3","Q40");
  AddVariableDependency("PRunning4","Q40");
}

Q40PV1::~Q40PV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q40PV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q40PV1Worker;
}
Q40PV2Worker::Q40PV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q40);
}

Q40PV2Worker::~Q40PV2Worker() {
  delete [] TheModelPtr;
}

double Q40PV2Worker::Reward_Function(void) {

if (
	(Q40->PRunning1->Mark()+Q40->PDone1->Mark() == cnt1 && Q40->PRunning2->Mark()+Q40->PDone2->Mark() == cnt2) ||
	Q40->PRunning3->Mark()+Q40->PDone3->Mark() == cnt3 ||
	Q40->PRunning4->Mark()+Q40->PDone4->Mark() == cnt4 ||
	Q40->PStart->Mark() >= cntUser
) 
	return 1; 
else 
	return 0;

return (0);



}

Q40PV2::Q40PV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ40SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("pInactive",(RewardType)3,1, startpts, stoppts, timeindex, 0,9, 9);
  Type = steady_state;
  AddVariableDependency("PRunning1","Q40");
  AddVariableDependency("PDone1","Q40");
  AddVariableDependency("PRunning2","Q40");
  AddVariableDependency("PDone2","Q40");
  AddVariableDependency("PRunning3","Q40");
  AddVariableDependency("PDone3","Q40");
  AddVariableDependency("PRunning4","Q40");
  AddVariableDependency("PDone4","Q40");
  AddVariableDependency("PStart","Q40");
}

Q40PV2::~Q40PV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q40PV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q40PV2Worker;
}
Q40PV3Worker::Q40PV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Q40);
}

Q40PV3Worker::~Q40PV3Worker() {
  delete [] TheModelPtr;
}

double Q40PV3Worker::Reward_Function(void) {

if (Q40->PDone1->Mark() == cnt1 - 1)
	return 0.1/avg1;
if (Q40->PDone2->Mark() == cnt2 - 1)
	return 0.1/avg2;
if (Q40->PDone3->Mark() == cnt3 - 1)
	return 0.1/avg3;
if (Q40->PStart->Mark() > 0)
	return rateThink*(double)(Q40->PStart->Mark());
else
	return 0;

return (0);



}

Q40PV3::Q40PV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheQ40SAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("rateActive",(RewardType)3,1, startpts, stoppts, timeindex, 0,4, 4);
  Type = steady_state;
  AddVariableDependency("PDone1","Q40");
  AddVariableDependency("PDone2","Q40");
  AddVariableDependency("PDone3","Q40");
  AddVariableDependency("PStart","Q40");
}

Q40PV3::~Q40PV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void Q40PV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new Q40PV3Worker;
}
