

// This C++ file was created by SanEditor

#include "Atomic/Q40/Q40SAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         Q40SAN Constructor             
******************************************************************/


Q40SAN::Q40SAN(){


  Activity* InitialActionList[18]={
    &IAStart1, //0
    &IAGet1, //1
    &IADone1, //2
    &IAGet4, //3
    &IADone4, //4
    &IAGetO, //5
    &IALastReady, //6
    &IAGet3, //7
    &IADone3, //8
    &IAGet2, //9
    &TAExec1, //10
    &TAExec4, //11
    &TAThink, //12
    &TAActive, //13
    &TAExecO, //14
    &TAInactive, //15
    &TAExec3, //16
    &TAExec2  // 17
  };

  BaseGroupClass* InitialGroupList[18]={
    (BaseGroupClass*) &(TAExec1), 
    (BaseGroupClass*) &(TAExec4), 
    (BaseGroupClass*) &(TAThink), 
    (BaseGroupClass*) &(TAActive), 
    (BaseGroupClass*) &(TAExecO), 
    (BaseGroupClass*) &(TAInactive), 
    (BaseGroupClass*) &(TAExec3), 
    (BaseGroupClass*) &(TAExec2), 
    (BaseGroupClass*) &(IAStart1), 
    (BaseGroupClass*) &(IAGet1), 
    (BaseGroupClass*) &(IADone1), 
    (BaseGroupClass*) &(IAGet4), 
    (BaseGroupClass*) &(IADone4), 
    (BaseGroupClass*) &(IAGetO), 
    (BaseGroupClass*) &(IALastReady), 
    (BaseGroupClass*) &(IAGet3), 
    (BaseGroupClass*) &(IADone3), 
    (BaseGroupClass*) &(IAGet2)
  };

  PStart = new Place("PStart" ,cntUser);
  PWaiting1 = new Place("PWaiting1" ,0);
  PRunning1 = new Place("PRunning1" ,0);
  PCores = new Place("PCores" ,cntCores);
  PDone1 = new Place("PDone1" ,0);
  PWaiting4 = new Place("PWaiting4" ,0);
  PRunning4 = new Place("PRunning4" ,0);
  PDone4 = new Place("PDone4" ,0);
  PReadyJobs = new Place("PReadyJobs" ,0);
  PRunningO = new Place("PRunningO" ,0);
  PActive = new Place("PActive" ,0);
  PInactive = new Place("PInactive" ,1);
  PStartLast = new Place("PStartLast" ,0);
  PNextJob = new Place("PNextJob" ,1);
  PWaiting3 = new Place("PWaiting3" ,0);
  PRunning3 = new Place("PRunning3" ,0);
  PDone3 = new Place("PDone3" ,0);
  PWaiting2 = new Place("PWaiting2" ,0);
  PRunning2 = new Place("PRunning2" ,0);
  PDone2 = new Place("PDone2" ,0);
  BaseStateVariableClass* InitialPlaces[20]={
    PStart,  // 0
    PWaiting1,  // 1
    PRunning1,  // 2
    PCores,  // 3
    PDone1,  // 4
    PWaiting4,  // 5
    PRunning4,  // 6
    PDone4,  // 7
    PReadyJobs,  // 8
    PRunningO,  // 9
    PActive,  // 10
    PInactive,  // 11
    PStartLast,  // 12
    PNextJob,  // 13
    PWaiting3,  // 14
    PRunning3,  // 15
    PDone3,  // 16
    PWaiting2,  // 17
    PRunning2,  // 18
    PDone2   // 19
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Q40", 20, InitialPlaces, 
                        0, InitialROPlaces, 
                        18, InitialActionList, 18, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[64][2]={ 
    {8,0}, {13,0}, {1,0}, {17,0}, {10,1}, {2,1}, {18,1}, {15,1}, 
    {6,1}, {1,1}, {3,1}, {4,2}, {19,2}, {14,2}, {10,3}, {2,3}, 
    {18,3}, {15,3}, {6,3}, {5,3}, {3,3}, {0,4}, {7,4}, {3,5}, 
    {9,5}, {12,6}, {13,6}, {10,7}, {2,7}, {18,7}, {15,7}, {6,7}, 
    {14,7}, {3,7}, {16,8}, {5,8}, {12,8}, {10,9}, {2,9}, {18,9}, 
    {15,9}, {6,9}, {17,9}, {3,9}, {2,10}, {3,10}, {4,10}, {6,11}, 
    {3,11}, {7,11}, {0,12}, {8,12}, {11,13}, {10,13}, {9,14}, 
    {3,14}, {10,15}, {11,15}, {15,16}, {3,16}, {16,16}, {18,17}, 
    {3,17}, {19,17}
  };
  for(int n=0;n<64;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[51][2]={ 
    {8,0}, {13,0}, {1,1}, {3,1}, {2,1}, {18,1}, {15,1}, {6,1}, 
    {10,1}, {4,2}, {19,2}, {5,3}, {3,3}, {2,3}, {18,3}, {15,3}, 
    {6,3}, {10,3}, {7,4}, {10,5}, {3,5}, {9,5}, {1,5}, {17,5}, 
    {14,5}, {5,5}, {12,6}, {5,6}, {14,7}, {3,7}, {2,7}, {18,7}, 
    {15,7}, {6,7}, {10,7}, {16,8}, {17,9}, {3,9}, {2,9}, {18,9}, 
    {15,9}, {6,9}, {10,9}, {2,10}, {6,11}, {0,12}, {11,13}, {9,14}, 
    {10,15}, {15,16}, {18,17}
  };
  for(int n=0;n<51;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<18;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void Q40SAN::CustomInitialization() {

}
Q40SAN::~Q40SAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void Q40SAN::assignPlacesToActivitiesInst(){
  IAStart1.PReadyJobs = (Place*) LocalStateVariables[8];
  IAStart1.PNextJob = (Place*) LocalStateVariables[13];
  IAStart1.PWaiting1 = (Place*) LocalStateVariables[1];
  IAStart1.PWaiting2 = (Place*) LocalStateVariables[17];
  IAGet1.PWaiting1 = (Place*) LocalStateVariables[1];
  IAGet1.PCores = (Place*) LocalStateVariables[3];
  IAGet1.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet1.PRunning2 = (Place*) LocalStateVariables[18];
  IAGet1.PRunning3 = (Place*) LocalStateVariables[15];
  IAGet1.PRunning4 = (Place*) LocalStateVariables[6];
  IAGet1.PActive = (Place*) LocalStateVariables[10];
  IADone1.PDone1 = (Place*) LocalStateVariables[4];
  IADone1.PDone2 = (Place*) LocalStateVariables[19];
  IADone1.PWaiting3 = (Place*) LocalStateVariables[14];
  IAGet4.PWaiting4 = (Place*) LocalStateVariables[5];
  IAGet4.PCores = (Place*) LocalStateVariables[3];
  IAGet4.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet4.PRunning2 = (Place*) LocalStateVariables[18];
  IAGet4.PRunning3 = (Place*) LocalStateVariables[15];
  IAGet4.PRunning4 = (Place*) LocalStateVariables[6];
  IAGet4.PActive = (Place*) LocalStateVariables[10];
  IADone4.PDone4 = (Place*) LocalStateVariables[7];
  IADone4.PStart = (Place*) LocalStateVariables[0];
  IAGetO.PActive = (Place*) LocalStateVariables[10];
  IAGetO.PCores = (Place*) LocalStateVariables[3];
  IAGetO.PRunningO = (Place*) LocalStateVariables[9];
  IAGetO.PWaiting1 = (Place*) LocalStateVariables[1];
  IAGetO.PWaiting2 = (Place*) LocalStateVariables[17];
  IAGetO.PWaiting3 = (Place*) LocalStateVariables[14];
  IAGetO.PWaiting4 = (Place*) LocalStateVariables[5];
  IALastReady.PStartLast = (Place*) LocalStateVariables[12];
  IALastReady.PWaiting4 = (Place*) LocalStateVariables[5];
  IALastReady.PNextJob = (Place*) LocalStateVariables[13];
  IAGet3.PWaiting3 = (Place*) LocalStateVariables[14];
  IAGet3.PCores = (Place*) LocalStateVariables[3];
  IAGet3.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet3.PRunning2 = (Place*) LocalStateVariables[18];
  IAGet3.PRunning3 = (Place*) LocalStateVariables[15];
  IAGet3.PRunning4 = (Place*) LocalStateVariables[6];
  IAGet3.PActive = (Place*) LocalStateVariables[10];
  IADone3.PDone3 = (Place*) LocalStateVariables[16];
  IADone3.PWaiting4 = (Place*) LocalStateVariables[5];
  IADone3.PStartLast = (Place*) LocalStateVariables[12];
  IAGet2.PWaiting2 = (Place*) LocalStateVariables[17];
  IAGet2.PCores = (Place*) LocalStateVariables[3];
  IAGet2.PRunning1 = (Place*) LocalStateVariables[2];
  IAGet2.PRunning2 = (Place*) LocalStateVariables[18];
  IAGet2.PRunning3 = (Place*) LocalStateVariables[15];
  IAGet2.PRunning4 = (Place*) LocalStateVariables[6];
  IAGet2.PActive = (Place*) LocalStateVariables[10];
}
void Q40SAN::assignPlacesToActivitiesTimed(){
  TAExec1.PRunning1 = (Place*) LocalStateVariables[2];
  TAExec1.PCores = (Place*) LocalStateVariables[3];
  TAExec1.PDone1 = (Place*) LocalStateVariables[4];
  TAExec4.PRunning4 = (Place*) LocalStateVariables[6];
  TAExec4.PCores = (Place*) LocalStateVariables[3];
  TAExec4.PDone4 = (Place*) LocalStateVariables[7];
  TAThink.PStart = (Place*) LocalStateVariables[0];
  TAThink.PReadyJobs = (Place*) LocalStateVariables[8];
  TAActive.PInactive = (Place*) LocalStateVariables[11];
  TAActive.PActive = (Place*) LocalStateVariables[10];
  TAExecO.PRunningO = (Place*) LocalStateVariables[9];
  TAExecO.PCores = (Place*) LocalStateVariables[3];
  TAInactive.PActive = (Place*) LocalStateVariables[10];
  TAInactive.PInactive = (Place*) LocalStateVariables[11];
  TAExec3.PRunning3 = (Place*) LocalStateVariables[15];
  TAExec3.PCores = (Place*) LocalStateVariables[3];
  TAExec3.PDone3 = (Place*) LocalStateVariables[16];
  TAExec2.PRunning2 = (Place*) LocalStateVariables[18];
  TAExec2.PCores = (Place*) LocalStateVariables[3];
  TAExec2.PDone2 = (Place*) LocalStateVariables[19];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================IAStart1Activity========================*/


Q40SAN::IAStart1Activity::IAStart1Activity(){
  ActivityInitialize("IAStart1",8,Instantaneous , RaceEnabled, 4,2, false);
}

void Q40SAN::IAStart1Activity::LinkVariables(){
  PReadyJobs->Register(&PReadyJobs_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
}

bool Q40SAN::IAStart1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PReadyJobs_Mobius_Mark)) >=1)&&((*(PNextJob_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::IAStart1Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IAStart1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAStart1Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAStart1Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAStart1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAStart1Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAStart1Activity::Fire(){
  (*(PReadyJobs_Mobius_Mark))--;
  (*(PNextJob_Mobius_Mark))--;
  PWaiting1->Mark()+= cnt1;
PWaiting2->Mark() += cnt2;
  return this;
}

/*======================IAGet1Activity========================*/


Q40SAN::IAGet1Activity::IAGet1Activity(){
  ActivityInitialize("IAGet1",9,Instantaneous , RaceEnabled, 7,7, false);
}

void Q40SAN::IAGet1Activity::LinkVariables(){
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PRunning4->Register(&PRunning4_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q40SAN::IAGet1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting1->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q40SAN::IAGet1Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IAGet1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAGet1Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAGet1Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAGet1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAGet1Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAGet1Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark());
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


Q40SAN::IADone1Activity::IADone1Activity(){
  ActivityInitialize("IADone1",10,Instantaneous , RaceEnabled, 3,2, false);
}

void Q40SAN::IADone1Activity::LinkVariables(){
  PDone1->Register(&PDone1_Mobius_Mark);
  PDone2->Register(&PDone2_Mobius_Mark);
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
}

bool Q40SAN::IADone1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PDone1->Mark() >= cnt1 && PDone2->Mark() >= cnt2));
  return NewEnabled;
}

double Q40SAN::IADone1Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IADone1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IADone1Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IADone1Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IADone1Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IADone1Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IADone1Activity::Fire(){
  PDone1->Mark() -= cnt1;
PDone2->Mark() -= cnt2;
  PWaiting3->Mark() += cnt3;
  return this;
}

/*======================IAGet4Activity========================*/


Q40SAN::IAGet4Activity::IAGet4Activity(){
  ActivityInitialize("IAGet4",11,Instantaneous , RaceEnabled, 7,7, false);
}

void Q40SAN::IAGet4Activity::LinkVariables(){
  PWaiting4->Register(&PWaiting4_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PRunning4->Register(&PRunning4_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q40SAN::IAGet4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting4->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q40SAN::IAGet4Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IAGet4Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAGet4Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAGet4Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAGet4Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAGet4Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAGet4Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark());
int minMarking = PWaiting4->Mark();

if (PCores->Mark() < minMarking)
	minMarking = PCores->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

PWaiting4->Mark() -= minMarking;
PCores->Mark() -= minMarking;
PRunning4->Mark() += minMarking;
  return this;
}

/*======================IADone4Activity========================*/


Q40SAN::IADone4Activity::IADone4Activity(){
  ActivityInitialize("IADone4",12,Instantaneous , RaceEnabled, 2,1, false);
}

void Q40SAN::IADone4Activity::LinkVariables(){
  PDone4->Register(&PDone4_Mobius_Mark);
  PStart->Register(&PStart_Mobius_Mark);
}

bool Q40SAN::IADone4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PDone4->Mark() >= cnt4));
  return NewEnabled;
}

double Q40SAN::IADone4Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IADone4Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IADone4Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IADone4Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IADone4Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IADone4Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IADone4Activity::Fire(){
  PDone4->Mark() -= cnt4;
  (*(PStart_Mobius_Mark))++;
  return this;
}

/*======================IAGetOActivity========================*/


Q40SAN::IAGetOActivity::IAGetOActivity(){
  ActivityInitialize("IAGetO",13,Instantaneous , RaceEnabled, 2,7, false);
}

void Q40SAN::IAGetOActivity::LinkVariables(){
  PActive->Register(&PActive_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunningO->Register(&PRunningO_Mobius_Mark);
  PWaiting1->Register(&PWaiting1_Mobius_Mark);
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
  PWaiting4->Register(&PWaiting4_Mobius_Mark);
}

bool Q40SAN::IAGetOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PActive->Mark()>0) && 
(PCores->Mark()>0) &&
(
	PRunningO->Mark()<(int)(shareO*cntCores)
	|| 
	(PWaiting1->Mark()+PWaiting2->Mark()+PWaiting3->Mark()+PWaiting4->Mark())==0
)));
  return NewEnabled;
}

double Q40SAN::IAGetOActivity::Weight(){ 
  return 1;
}

bool Q40SAN::IAGetOActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAGetOActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAGetOActivity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAGetOActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAGetOActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAGetOActivity::Fire(){
  PCores->Mark() -= 1;
PRunningO->Mark() += 1;
  return this;
}

/*======================IALastReadyActivity========================*/


Q40SAN::IALastReadyActivity::IALastReadyActivity(){
  ActivityInitialize("IALastReady",14,Instantaneous , RaceEnabled, 2,2, false);
}

void Q40SAN::IALastReadyActivity::LinkVariables(){
  PStartLast->Register(&PStartLast_Mobius_Mark);
  PWaiting4->Register(&PWaiting4_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
}

bool Q40SAN::IALastReadyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PStartLast->Mark() > 0 &&
PWaiting4->Mark() == 0));
  return NewEnabled;
}

double Q40SAN::IALastReadyActivity::Weight(){ 
  return 1;
}

bool Q40SAN::IALastReadyActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IALastReadyActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IALastReadyActivity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IALastReadyActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IALastReadyActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IALastReadyActivity::Fire(){
  PStartLast->Mark() = 0;
  PNextJob->Mark() = 1;
  return this;
}

/*======================IAGet3Activity========================*/


Q40SAN::IAGet3Activity::IAGet3Activity(){
  ActivityInitialize("IAGet3",15,Instantaneous , RaceEnabled, 7,7, false);
}

void Q40SAN::IAGet3Activity::LinkVariables(){
  PWaiting3->Register(&PWaiting3_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PRunning4->Register(&PRunning4_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q40SAN::IAGet3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting3->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q40SAN::IAGet3Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IAGet3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAGet3Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAGet3Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAGet3Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAGet3Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAGet3Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark());
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


Q40SAN::IADone3Activity::IADone3Activity(){
  ActivityInitialize("IADone3",16,Instantaneous , RaceEnabled, 3,1, false);
}

void Q40SAN::IADone3Activity::LinkVariables(){
  PDone3->Register(&PDone3_Mobius_Mark);
  PWaiting4->Register(&PWaiting4_Mobius_Mark);
  PStartLast->Register(&PStartLast_Mobius_Mark);
}

bool Q40SAN::IADone3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PDone3->Mark() >= cnt3));
  return NewEnabled;
}

double Q40SAN::IADone3Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IADone3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IADone3Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IADone3Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IADone3Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IADone3Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IADone3Activity::Fire(){
  PDone3->Mark() -= cnt3;
  PWaiting4->Mark() += cnt4;
PStartLast->Mark() = 1;
  return this;
}

/*======================IAGet2Activity========================*/


Q40SAN::IAGet2Activity::IAGet2Activity(){
  ActivityInitialize("IAGet2",17,Instantaneous , RaceEnabled, 7,7, false);
}

void Q40SAN::IAGet2Activity::LinkVariables(){
  PWaiting2->Register(&PWaiting2_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PRunning4->Register(&PRunning4_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q40SAN::IAGet2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PWaiting2->Mark()>0) && 
(PCores->Mark()>0) &&
(
	(PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark())<(int)(share*cntCores)
	|| 
	PActive->Mark()==0
)));
  return NewEnabled;
}

double Q40SAN::IAGet2Activity::Weight(){ 
  return 1;
}

bool Q40SAN::IAGet2Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::IAGet2Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::IAGet2Activity::SampleDistribution(){
  return 0;
}

double* Q40SAN::IAGet2Activity::ReturnDistributionParameters(){
    return NULL;
}

int Q40SAN::IAGet2Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::IAGet2Activity::Fire(){
  int reqOtherClass = PActive->Mark();
int permissed = share*cntCores - (PRunning1->Mark()+PRunning2->Mark()+PRunning3->Mark()+PRunning4->Mark());
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

Q40SAN::TAExec1Activity::TAExec1Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec1",0,Exponential, RaceEnabled, 3,1, false);
}

Q40SAN::TAExec1Activity::~TAExec1Activity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAExec1Activity::LinkVariables(){
  PRunning1->Register(&PRunning1_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone1->Register(&PDone1_Mobius_Mark);
}

bool Q40SAN::TAExec1Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning1_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAExec1Activity::Rate(){
  return 1.0/avg1;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAExec1Activity::Weight(){ 
  return 1;
}

bool Q40SAN::TAExec1Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAExec1Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAExec1Activity::SampleDistribution(){
  return TheDistribution->Exponential(1.0/avg1);
}

double* Q40SAN::TAExec1Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAExec1Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAExec1Activity::Fire(){
  (*(PRunning1_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone1_Mobius_Mark))++;
  return this;
}

/*======================TAExec4Activity========================*/

Q40SAN::TAExec4Activity::TAExec4Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec4",1,Exponential, RaceEnabled, 3,1, false);
}

Q40SAN::TAExec4Activity::~TAExec4Activity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAExec4Activity::LinkVariables(){
  PRunning4->Register(&PRunning4_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone4->Register(&PDone4_Mobius_Mark);
}

bool Q40SAN::TAExec4Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning4_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAExec4Activity::Rate(){
  return 1.0/avg4;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAExec4Activity::Weight(){ 
  return 1;
}

bool Q40SAN::TAExec4Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAExec4Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAExec4Activity::SampleDistribution(){
  return TheDistribution->Exponential(1.0/avg4);
}

double* Q40SAN::TAExec4Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAExec4Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAExec4Activity::Fire(){
  (*(PRunning4_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone4_Mobius_Mark))++;
  return this;
}

/*======================TAThinkActivity========================*/

Q40SAN::TAThinkActivity::TAThinkActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAThink",2,Exponential, RaceEnabled, 2,1, false);
}

Q40SAN::TAThinkActivity::~TAThinkActivity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAThinkActivity::LinkVariables(){
  PStart->Register(&PStart_Mobius_Mark);
  PReadyJobs->Register(&PReadyJobs_Mobius_Mark);
}

bool Q40SAN::TAThinkActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PStart_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAThinkActivity::Rate(){
  return rateThink * (double)(PStart->Mark());
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAThinkActivity::Weight(){ 
  return 1;
}

bool Q40SAN::TAThinkActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAThinkActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAThinkActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateThink * (double)(PStart->Mark()));
}

double* Q40SAN::TAThinkActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAThinkActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAThinkActivity::Fire(){
  (*(PStart_Mobius_Mark))--;
  (*(PReadyJobs_Mobius_Mark))++;
  return this;
}

/*======================TAActiveActivity========================*/

Q40SAN::TAActiveActivity::TAActiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAActive",3,Exponential, RaceEnabled, 2,1, false);
}

Q40SAN::TAActiveActivity::~TAActiveActivity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAActiveActivity::LinkVariables(){
  PInactive->Register(&PInactive_Mobius_Mark);
  PActive->Register(&PActive_Mobius_Mark);
}

bool Q40SAN::TAActiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PInactive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAActiveActivity::Rate(){
  return rateActive;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAActiveActivity::Weight(){ 
  return 1;
}

bool Q40SAN::TAActiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAActiveActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAActiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateActive);
}

double* Q40SAN::TAActiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAActiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAActiveActivity::Fire(){
  (*(PInactive_Mobius_Mark))--;
  (*(PActive_Mobius_Mark))++;
  return this;
}

/*======================TAExecOActivity========================*/

Q40SAN::TAExecOActivity::TAExecOActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExecO",4,Exponential, RaceEnabled, 2,1, false);
}

Q40SAN::TAExecOActivity::~TAExecOActivity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAExecOActivity::LinkVariables(){
  PRunningO->Register(&PRunningO_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
}

bool Q40SAN::TAExecOActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunningO_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAExecOActivity::Rate(){
  return rateReturn;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAExecOActivity::Weight(){ 
  return 1;
}

bool Q40SAN::TAExecOActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAExecOActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAExecOActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateReturn);
}

double* Q40SAN::TAExecOActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAExecOActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAExecOActivity::Fire(){
  (*(PRunningO_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  return this;
}

/*======================TAInactiveActivity========================*/

Q40SAN::TAInactiveActivity::TAInactiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAInactive",5,Exponential, RaceEnabled, 2,1, false);
}

Q40SAN::TAInactiveActivity::~TAInactiveActivity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAInactiveActivity::LinkVariables(){
  PActive->Register(&PActive_Mobius_Mark);
  PInactive->Register(&PInactive_Mobius_Mark);
}

bool Q40SAN::TAInactiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PActive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAInactiveActivity::Rate(){
  return rateInactive;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAInactiveActivity::Weight(){ 
  return 1;
}

bool Q40SAN::TAInactiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAInactiveActivity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAInactiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateInactive);
}

double* Q40SAN::TAInactiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAInactiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAInactiveActivity::Fire(){
  (*(PActive_Mobius_Mark))--;
  (*(PInactive_Mobius_Mark))++;
  return this;
}

/*======================TAExec3Activity========================*/

Q40SAN::TAExec3Activity::TAExec3Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec3",6,Exponential, RaceEnabled, 3,1, false);
}

Q40SAN::TAExec3Activity::~TAExec3Activity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAExec3Activity::LinkVariables(){
  PRunning3->Register(&PRunning3_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone3->Register(&PDone3_Mobius_Mark);
}

bool Q40SAN::TAExec3Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning3_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAExec3Activity::Rate(){
  return 1.0/avg3;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAExec3Activity::Weight(){ 
  return 1;
}

bool Q40SAN::TAExec3Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAExec3Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAExec3Activity::SampleDistribution(){
  return TheDistribution->Exponential(1.0/avg3);
}

double* Q40SAN::TAExec3Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAExec3Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAExec3Activity::Fire(){
  (*(PRunning3_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone3_Mobius_Mark))++;
  return this;
}

/*======================TAExec2Activity========================*/

Q40SAN::TAExec2Activity::TAExec2Activity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("TAExec2",7,Exponential, RaceEnabled, 3,1, false);
}

Q40SAN::TAExec2Activity::~TAExec2Activity(){
  delete[] TheDistributionParameters;
}

void Q40SAN::TAExec2Activity::LinkVariables(){
  PRunning2->Register(&PRunning2_Mobius_Mark);
  PCores->Register(&PCores_Mobius_Mark);
  PDone2->Register(&PDone2_Mobius_Mark);
}

bool Q40SAN::TAExec2Activity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PRunning2_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q40SAN::TAExec2Activity::Rate(){
  return 1.0/avg2;
  return 1.0;  // default rate if none is specified
}

double Q40SAN::TAExec2Activity::Weight(){ 
  return 1;
}

bool Q40SAN::TAExec2Activity::ReactivationPredicate(){ 
  return false;
}

bool Q40SAN::TAExec2Activity::ReactivationFunction(){ 
  return false;
}

double Q40SAN::TAExec2Activity::SampleDistribution(){
  return TheDistribution->Exponential(1.0/avg2);
}

double* Q40SAN::TAExec2Activity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q40SAN::TAExec2Activity::Rank(){
  return 1;
}

BaseActionClass* Q40SAN::TAExec2Activity::Fire(){
  (*(PRunning2_Mobius_Mark))--;
  (*(PCores_Mobius_Mark))++;
  (*(PDone2_Mobius_Mark))++;
  return this;
}

