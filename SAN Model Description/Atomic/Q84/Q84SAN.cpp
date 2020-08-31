

// This C++ file was created by SanEditor

#include "Atomic/Q84/Q84SAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         Q84SAN Constructor             
******************************************************************/


Q84SAN::Q84SAN(){


  Activity* InitialActionList[15]={
    &IAStart1, //0
    &IAGet1, //1
    &IADone1, //2
    &IAGet3, //3
    &IADone3, //4
    &IAGetO, //5
    &IALastReady, //6
    &IAGet2, //7
    &TAExec1, //8
    &TAExec3, //9
    &TAThink, //10
    &TAActive, //11
    &TAExecO, //12
    &TAInactive, //13
    &TAExec2  // 14
  };

  BaseGroupClass* InitialGroupList[15]={
    (BaseGroupClass*) &(TAExec1), 
    (BaseGroupClass*) &(TAExec3), 
    (BaseGroupClass*) &(TAThink), 
    (BaseGroupClass*) &(TAActive), 
    (BaseGroupClass*) &(TAExecO), 
    (BaseGroupClass*) &(TAInactive), 
    (BaseGroupClass*) &(TAExec2), 
    (BaseGroupClass*) &(IAStart1), 
    (BaseGroupClass*) &(IAGet1), 
    (BaseGroupClass*) &(IADone1), 
    (BaseGroupClass*) &(IAGet3), 
    (BaseGroupClass*) &(IADone3), 
    (BaseGroupClass*) &(IAGetO), 
    (BaseGroupClass*) &(IALastReady), 
    (BaseGroupClass*) &(IAGet2)
  };

  PStart = new Place("PStart" ,cntUser);
  PWaiting1 = new Place("PWaiting1" ,0);
  PRunning1 = new Place("PRunning1" ,0);
  PCores = new Place("PCores" ,cntCores);
  PDone1 = new Place("PDone1" ,0);
  PWaiting3 = new Place("PWaiting3" ,0);
  PRunning3 = new Place("PRunning3" ,0);
  PDone3 = new Place("PDone3" ,0);
  PReadyJobs = new Place("PReadyJobs" ,0);
  PRunningO = new Place("PRunningO" ,0);
  PActive = new Place("PActive" ,0);
  PInactive = new Place("PInactive" ,1);
  PStartLast = new Place("PStartLast" ,0);
  PNextJob = new Place("PNextJob" ,1);
  PWaiting2 = new Place("PWaiting2" ,0);
  PRunning2 = new Place("PRunning2" ,0);
  PDone2 = new Place("PDone2" ,0);
  BaseStateVariableClass* InitialPlaces[17]={
    PStart,  // 0
    PWaiting1,  // 1
    PRunning1,  // 2
    PCores,  // 3
    PDone1,  // 4
    PWaiting3,  // 5
    PRunning3,  // 6
    PDone3,  // 7
    PReadyJobs,  // 8
    PRunningO,  // 9
    PActive,  // 10
    PInactive,  // 11
    PStartLast,  // 12
    PNextJob,  // 13
    PWaiting2,  // 14
    PRunning2,  // 15
    PDone2   // 16
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Q84", 17, InitialPlaces, 
                        0, InitialROPlaces, 
                        15, InitialActionList, 15, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[49][2]={ 
    {8,0}, {13,0}, {1,0}, {14,0}, {10,1}, {2,1}, {15,1}, {6,1}, 
    {1,1}, {3,1}, {4,2}, {16,2}, {5,2}, {12,2}, {10,3}, {2,3}, 
    {15,3}, {6,3}, {5,3}, {3,3}, {0,4}, {7,4}, {3,5}, {9,5}, 
    {12,6}, {13,6}, {10,7}, {2,7}, {15,7}, {6,7}, {14,7}, {3,7}, 
    {2,8}, {3,8}, {4,8}, {6,9}, {3,9}, {7,9}, {0,10}, {8,10}, 
    {11,11}, {10,11}, {9,12}, {3,12}, {10,13}, {11,13}, {15,14}, 
    {3,14}, {16,14}
  };
  for(int n=0;n<49;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[38][2]={ 
    {8,0}, {13,0}, {1,1}, {3,1}, {2,1}, {15,1}, {6,1}, {10,1}, 
    {4,2}, {16,2}, {5,3}, {3,3}, {2,3}, {15,3}, {6,3}, {10,3}, 
    {7,4}, {10,5}, {3,5}, {9,5}, {1,5}, {14,5}, {5,5}, {12,6}, 
    {5,6}, {14,7}, {3,7}, {2,7}, {15,7}, {6,7}, {10,7}, {2,8}, 
    {6,9}, {0,10}, {11,11}, {9,12}, {10,13}, {15,14}
  };
  for(int n=0;n<38;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<15;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void Q84SAN::CustomInitialization() {

}
Q84SAN::~Q84SAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void Q84SAN::assignPlacesToActivitiesInst(){
  IAStart1.PReadyJobs = (Place*) LocalStateVariables[8];
  IAStart1.PNextJob = (Place*) LocalStateVariables[13];
  IAStart1.PWaiting1 = (Place*) LocalStateVariables[1];
  IAStart1.PWaiting2 = (Place*) LocalStateVariables[14];
  IAGet1.PWaiting1 = (Place*) LocalStateVariables[1];
  IAGet1.PCores = (Place*) LocalStateVariables[3];
  IAGet1.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet1.PRunning2 = (Place*) LocalStateVariables[15];
  IAGet1.PRunning3 = (Place*) LocalStateVariables[6];
  IAGet1.PActive = (Place*) LocalStateVariables[10];
  IADone1.PDone1 = (Place*) LocalStateVariables[4];
  IADone1.PDone2 = (Place*) LocalStateVariables[16];
  IADone1.PWaiting3 = (Place*) LocalStateVariables[5];
  IADone1.PStartLast = (Place*) LocalStateVariables[12];
  IAGet3.PWaiting3 = (Place*) LocalStateVariables[5];
  IAGet3.PCores = (Place*) LocalStateVariables[3];
  IAGet3.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet3.PRunning2 = (Place*) LocalStateVariables[15];
  IAGet3.PRunning3 = (Place*) LocalStateVariables[6];
  IAGet3.PActive = (Place*) LocalStateVariables[10];
  IADone3.PDone3 = (Place*) LocalStateVariables[7];
  IADone3.PStart = (Place*) LocalStateVariables[0];
  IAGetO.PActive = (Place*) LocalStateVariables[10];
  IAGetO.PCores = (Place*) LocalStateVariables[3];
  IAGetO.PRunningO = (Place*) LocalStateVariables[9];
  IAGetO.PWaiting1 = (Place*) LocalStateVariables[1];
  IAGetO.PWaiting2 = (Place*) LocalStateVariables[14];
  IAGetO.PWaiting3 = (Place*) LocalStateVariables[5];
  IALastReady.PStartLast = (Place*) LocalStateVariables[12];
  IALastReady.PWaiting3 = (Place*) LocalStateVariables[5];
  IALastReady.PNextJob = (Place*) LocalStateVariables[13];
  IAGet2.PWaiting2 = (Place*) LocalStateVariables[14];
  IAGet2.PCores = (Place*) LocalStateVariables[3];
  IAGet2.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet2.PRunning2 = (Place*) LocalStateVariables[15];
  IAGet2.PRunning3 = (Place*) LocalStateVariables[6];
  IAGet2.PActive = (Place*) LocalStateVariables[10];
}
void Q84SAN::assignPlacesToActivitiesTimed(){
  TAExec1.PRunning1 = (Place*) LocalStateVariables[2];
  TAExec1.PCores = (Place*) LocalStateVariables[3];
  TAExec1.PDone1 = (Place*) LocalStateVariables[4];
  TAExec3.PRunning3 = (Place*) LocalStateVariables[6];
  TAExec3.PCores = (Place*) LocalStateVariables[3];
  TAExec3.PDone3 = (Place*) LocalStateVariables[7];
  TAThink.PStart = (Place*) LocalStateVariables[0];
  TAThink.PReadyJobs = (Place*) LocalStateVariables[8];
  TAActive.PInactive = (Place*) LocalStateVariables[11];
  TAActive.PActive = (Place*) LocalStateVariables[10];
  TAExecO.PRunningO = (Place*) LocalStateVariables[9];
  TAExecO.PCores = (Place*) LocalStateVariables[3];
  TAInactive.PActive = (Place*) LocalStateVariables[10];
  TAInactive.PInactive = (Place*) LocalStateVariables[11];
  TAExec2.PRunning2 = (Place*) LocalStateVariables[15];
  TAExec2.PCores = (Place*) LocalStateVariables[3];
  TAExec2.PDone2 = (Place*) LocalStateVariables[16];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================IAStart1Activity========================*/


Q84SAN::IAStart1Activity::IAStart1Activity(){
  ActivityInitialize("IAStart1",7,Instantaneous , RaceEnabled, 4,2, false);
}

void Q84SAN::IAStart1Activity::LinkVariables(){
  PReadyJobs->Register(&PReadyJobs_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
}

bool Q84SAN::IAStart1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PReadyJobs_Mobius_Mark)) >=1)&&((*(PNextJob_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::IAStart1Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IAStart1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IAStart1Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IAStart1Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IAStart1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IAStart1Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IAStart1Activity::Fire(){
  (*(PReadyJobs_Mobius_Mark))--;
  (*(PNextJob_Mobius_Mark))--;
  PWaiting1->Mark()+= cnt1;
PWaiting2->Mark() += cnt2;
  return this;
}

/*======================IAGet1Activity========================*/


Q84SAN::IAGet1Activity::IAGet1Activity(){
  ActivityInitialize("IAGet1",8,Instantaneous , RaceEnabled, 6,6, false);
}

void Q84SAN::IAGet1Activity::LinkVariables(){
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q84SAN::IAGet1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting1->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q84SAN::IAGet1Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IAGet1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IAGet1Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IAGet1Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IAGet1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IAGet1Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IAGet1Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark());
int minMarking = PWaiting1->Mark();

if (PCores->Mark() < minMarking)
	minMarking = PCores->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

PWaiting1->Mark() -= minMarking;
PCores->Mark() -= minMarking;
PRunning1->Mark() += minMarking;
  return this;
}

/*======================IADone1Activity========================*/


Q84SAN::IADone1Activity::IADone1Activity(){
  ActivityInitialize("IADone1",9,Instantaneous , RaceEnabled, 4,2, false);
}

void Q84SAN::IADone1Activity::LinkVariables(){
  PDone1->Register(&PDone1_Mobius_Mark);
  PDone2->Register(&PDone2_Mobius_Mark);
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
  PStartLast->Register(&PStartLast_Mobius_Mark);
}

bool Q84SAN::IADone1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PDone1->Mark() >= cnt1 && PDone2->Mark() >= cnt2));
  return NewEnabled;
}

double Q84SAN::IADone1Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IADone1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IADone1Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IADone1Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IADone1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IADone1Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IADone1Activity::Fire(){
  PDone1->Mark() -= cnt1;
PDone2->Mark() -= cnt2;
  PWaiting3->Mark() += cnt3;
PStartLast->Mark() = 1;
  return this;
}

/*======================IAGet3Activity========================*/


Q84SAN::IAGet3Activity::IAGet3Activity(){
  ActivityInitialize("IAGet3",10,Instantaneous , RaceEnabled, 6,6, false);
}

void Q84SAN::IAGet3Activity::LinkVariables(){
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q84SAN::IAGet3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting3->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q84SAN::IAGet3Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IAGet3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IAGet3Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IAGet3Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IAGet3Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IAGet3Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IAGet3Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark());
int minMarking = PWaiting3->Mark();

if (PCores->Mark() < minMarking)
	minMarking = PCores->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

PWaiting3->Mark() -= minMarking;
PCores->Mark() -= minMarking;
PRunning3->Mark() += minMarking;
  return this;
}

/*======================IADone3Activity========================*/


Q84SAN::IADone3Activity::IADone3Activity(){
  ActivityInitialize("IADone3",11,Instantaneous , RaceEnabled, 2,1, false);
}

void Q84SAN::IADone3Activity::LinkVariables(){
  PDone3->Register(&PDone3_Mobius_Mark);
  PStart->Register(&PStart_Mobius_Mark);
}

bool Q84SAN::IADone3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PDone3->Mark() >= cnt3));
  return NewEnabled;
}

double Q84SAN::IADone3Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IADone3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IADone3Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IADone3Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IADone3Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IADone3Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IADone3Activity::Fire(){
  PDone3->Mark() -= cnt3;
  (*(PStart_Mobius_Mark))++;
  return this;
}

/*======================IAGetOActivity========================*/


Q84SAN::IAGetOActivity::IAGetOActivity(){
  ActivityInitialize("IAGetO",12,Instantaneous , RaceEnabled, 2,6, false);
}

void Q84SAN::IAGetOActivity::LinkVariables(){
  PActive->Register(&PActive_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunningO->Register(&PRunningO_Mobius_Mark);
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
}

bool Q84SAN::IAGetOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PActive->Mark()>0) && 
(PCores->Mark()>0) &&
(
	PRunningO->Mark()<(int)(shareO*cntCores)
	|| 
	(PWaiting1->Mark()+PWaiting2->Mark()+PWaiting3->Mark())==0
)));
  return NewEnabled;
}

double Q84SAN::IAGetOActivity::Weight(){ 
  return 1;
}

bool Q84SAN::IAGetOActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IAGetOActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IAGetOActivity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IAGetOActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IAGetOActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IAGetOActivity::Fire(){
  PCores->Mark() -= 1;
PRunningO->Mark() += 1;
  return this;
}

/*======================IALastReadyActivity========================*/


Q84SAN::IALastReadyActivity::IALastReadyActivity(){
  ActivityInitialize("IALastReady",13,Instantaneous , RaceEnabled, 2,2, false);
}

void Q84SAN::IALastReadyActivity::LinkVariables(){
  PStartLast->Register(&PStartLast_Mobius_Mark);
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
}

bool Q84SAN::IALastReadyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PStartLast->Mark() > 0 &&
PWaiting3->Mark() == 0));
  return NewEnabled;
}

double Q84SAN::IALastReadyActivity::Weight(){ 
  return 1;
}

bool Q84SAN::IALastReadyActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IALastReadyActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IALastReadyActivity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IALastReadyActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IALastReadyActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IALastReadyActivity::Fire(){
  PStartLast->Mark() = 0;
  PNextJob->Mark() = 1;
  return this;
}

/*======================IAGet2Activity========================*/


Q84SAN::IAGet2Activity::IAGet2Activity(){
  ActivityInitialize("IAGet2",14,Instantaneous , RaceEnabled, 6,6, false);
}

void Q84SAN::IAGet2Activity::LinkVariables(){
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q84SAN::IAGet2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting2->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q84SAN::IAGet2Activity::Weight(){ 
  return 1;
}

bool Q84SAN::IAGet2Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::IAGet2Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::IAGet2Activity::SampleDistribution(){
  return 0;
}

double* Q84SAN::IAGet2Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q84SAN::IAGet2Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::IAGet2Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark());
int minMarking = PWaiting2->Mark();

if (PCores->Mark() < minMarking)
	minMarking = PCores->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

PWaiting2->Mark() -= minMarking;
PCores->Mark() -= minMarking;
PRunning2->Mark() += minMarking;
  return this;
}

/*======================TAExec1Activity========================*/

Q84SAN::TAExec1Activity::TAExec1Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec1",0,Exponential, RaceEnabled, 3,1, false);
}

Q84SAN::TAExec1Activity::~TAExec1Activity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAExec1Activity::LinkVariables(){
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone1->Register(&PDone1_Mobius_Mark);
}

bool Q84SAN::TAExec1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAExec1Activity::Rate(){
  return (1.0/avg1)*(double)(PRunning1->Mark());
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAExec1Activity::Weight(){ 
  return 1;
}

bool Q84SAN::TAExec1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAExec1Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAExec1Activity::SampleDistribution(){
  return TheDistribution->Exponential((1.0/avg1)*(double)(PRunning1->Mark()));
}

double* Q84SAN::TAExec1Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAExec1Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAExec1Activity::Fire(){
  (*(PRunning1_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone1_Mobius_Mark))++;
  return this;
}

/*======================TAExec3Activity========================*/

Q84SAN::TAExec3Activity::TAExec3Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec3",1,Exponential, RaceEnabled, 3,1, false);
}

Q84SAN::TAExec3Activity::~TAExec3Activity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAExec3Activity::LinkVariables(){
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone3->Register(&PDone3_Mobius_Mark);
}

bool Q84SAN::TAExec3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning3_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAExec3Activity::Rate(){
  return (1.0/avg3)*(double)(PRunning3->Mark());
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAExec3Activity::Weight(){ 
  return 1;
}

bool Q84SAN::TAExec3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAExec3Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAExec3Activity::SampleDistribution(){
  return TheDistribution->Exponential((1.0/avg3)*(double)(PRunning3->Mark()));
}

double* Q84SAN::TAExec3Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAExec3Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAExec3Activity::Fire(){
  (*(PRunning3_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone3_Mobius_Mark))++;
  return this;
}

/*======================TAThinkActivity========================*/

Q84SAN::TAThinkActivity::TAThinkActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAThink",2,Exponential, RaceEnabled, 2,1, false);
}

Q84SAN::TAThinkActivity::~TAThinkActivity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAThinkActivity::LinkVariables(){
  PStart->Register(&PStart_Mobius_Mark);
  PReadyJobs->Register(&PReadyJobs_Mobius_Mark);
}

bool Q84SAN::TAThinkActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PStart_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAThinkActivity::Rate(){
  return rateThink * (double)(PStart->Mark());
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAThinkActivity::Weight(){ 
  return 1;
}

bool Q84SAN::TAThinkActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAThinkActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAThinkActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateThink * (double)(PStart->Mark()));
}

double* Q84SAN::TAThinkActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAThinkActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAThinkActivity::Fire(){
  (*(PStart_Mobius_Mark))--;
  (*(PReadyJobs_Mobius_Mark))++;
  return this;
}

/*======================TAActiveActivity========================*/

Q84SAN::TAActiveActivity::TAActiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAActive",3,Exponential, RaceEnabled, 2,1, false);
}

Q84SAN::TAActiveActivity::~TAActiveActivity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAActiveActivity::LinkVariables(){
  PInactive->Register(&PInactive_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q84SAN::TAActiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PInactive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAActiveActivity::Rate(){
  return rateActive;
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAActiveActivity::Weight(){ 
  return 1;
}

bool Q84SAN::TAActiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAActiveActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAActiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateActive);
}

double* Q84SAN::TAActiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAActiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAActiveActivity::Fire(){
  (*(PInactive_Mobius_Mark))--;
  (*(PActive_Mobius_Mark))++;
  return this;
}

/*======================TAExecOActivity========================*/

Q84SAN::TAExecOActivity::TAExecOActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExecO",4,Exponential, RaceEnabled, 2,1, false);
}

Q84SAN::TAExecOActivity::~TAExecOActivity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAExecOActivity::LinkVariables(){
  PRunningO->Register(&PRunningO_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
}

bool Q84SAN::TAExecOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunningO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAExecOActivity::Rate(){
  return rateReturn;
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAExecOActivity::Weight(){ 
  return 1;
}

bool Q84SAN::TAExecOActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAExecOActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAExecOActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateReturn);
}

double* Q84SAN::TAExecOActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAExecOActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAExecOActivity::Fire(){
  (*(PRunningO_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  return this;
}

/*======================TAInactiveActivity========================*/

Q84SAN::TAInactiveActivity::TAInactiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAInactive",5,Exponential, RaceEnabled, 2,1, false);
}

Q84SAN::TAInactiveActivity::~TAInactiveActivity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAInactiveActivity::LinkVariables(){
  PActive->Register(&PActive_Mobius_Mark);
  PInactive->Register(&PInactive_Mobius_Mark);
}

bool Q84SAN::TAInactiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PActive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAInactiveActivity::Rate(){
  return rateInactive;
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAInactiveActivity::Weight(){ 
  return 1;
}

bool Q84SAN::TAInactiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAInactiveActivity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAInactiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateInactive);
}

double* Q84SAN::TAInactiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAInactiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAInactiveActivity::Fire(){
  (*(PActive_Mobius_Mark))--;
  (*(PInactive_Mobius_Mark))++;
  return this;
}

/*======================TAExec2Activity========================*/

Q84SAN::TAExec2Activity::TAExec2Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec2",6,Exponential, RaceEnabled, 3,1, false);
}

Q84SAN::TAExec2Activity::~TAExec2Activity(){
  delete[] TheDistributionParameters;
}

void Q84SAN::TAExec2Activity::LinkVariables(){
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone2->Register(&PDone2_Mobius_Mark);
}

bool Q84SAN::TAExec2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q84SAN::TAExec2Activity::Rate(){
  return (1.0/avg2)*(double)(PRunning2->Mark());
  return 1.0;  // default rate if none is specified
}

double Q84SAN::TAExec2Activity::Weight(){ 
  return 1;
}

bool Q84SAN::TAExec2Activity::ReactivationPredicate(){ 
  return false;
}

bool Q84SAN::TAExec2Activity::ReactivationFunction(){ 
  return false;
}

double Q84SAN::TAExec2Activity::SampleDistribution(){
  return TheDistribution->Exponential((1.0/avg2)*(double)(PRunning2->Mark()));
}

double* Q84SAN::TAExec2Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q84SAN::TAExec2Activity::Rank(){
  return 1;
}

BaseActionClass* Q84SAN::TAExec2Activity::Fire(){
  (*(PRunning2_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone2_Mobius_Mark))++;
  return this;
}

