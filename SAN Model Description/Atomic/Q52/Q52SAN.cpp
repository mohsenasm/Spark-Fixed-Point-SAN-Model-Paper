

// This C++ file was created by SanEditor

#include "Atomic/Q52/Q52SAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         Q52SAN Constructor             
******************************************************************/


Q52SAN::Q52SAN(){


  Activity* InitialActionList[13]={
    &activityGenMap, //0
    &activityGetResMap, //1
    &activitySynchMaps, //2
    &activityGetResReduce, //3
    &activitySynchReduce, //4
    &IATake, //5
    &IALastReady, //6
    &activityMap, //7
    &activityReduce, //8
    &activityThink, //9
    &activityActive, //10
    &activityRun, //11
    &activityInactive  // 12
  };

  BaseGroupClass* InitialGroupList[13]={
    (BaseGroupClass*) &(activityMap), 
    (BaseGroupClass*) &(activityReduce), 
    (BaseGroupClass*) &(activityThink), 
    (BaseGroupClass*) &(activityActive), 
    (BaseGroupClass*) &(activityRun), 
    (BaseGroupClass*) &(activityInactive), 
    (BaseGroupClass*) &(activityGenMap), 
    (BaseGroupClass*) &(activityGetResMap), 
    (BaseGroupClass*) &(activitySynchMaps), 
    (BaseGroupClass*) &(activityGetResReduce), 
    (BaseGroupClass*) &(activitySynchReduce), 
    (BaseGroupClass*) &(IATake), 
    (BaseGroupClass*) &(IALastReady)
  };

  placeStart = new Place("placeStart" ,cntUser);
  placeMaps = new Place("placeMaps" ,0);
  placeMapsReady = new Place("placeMapsReady" ,0);
  placeRes = new Place("placeRes" ,NumberOfCores);
  placeMaped = new Place("placeMaped" ,0);
  placeReduces = new Place("placeReduces" ,0);
  placeReducesReady = new Place("placeReducesReady" ,0);
  placeReduced = new Place("placeReduced" ,0);
  placeJobReady = new Place("placeJobReady" ,0);
  PlaceRuning = new Place("PlaceRuning" ,0);
  PlaceActive = new Place("PlaceActive" ,0);
  PlaceInactive = new Place("PlaceInactive" ,1);
  PlaceReduceStart = new Place("PlaceReduceStart" ,0);
  PNextJob = new Place("PNextJob" ,1);
  BaseStateVariableClass* InitialPlaces[14]={
    placeStart,  // 0
    placeMaps,  // 1
    placeMapsReady,  // 2
    placeRes,  // 3
    placeMaped,  // 4
    placeReduces,  // 5
    placeReducesReady,  // 6
    placeReduced,  // 7
    placeJobReady,  // 8
    PlaceRuning,  // 9
    PlaceActive,  // 10
    PlaceInactive,  // 11
    PlaceReduceStart,  // 12
    PNextJob   // 13
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Q52", 14, InitialPlaces, 
                        0, InitialROPlaces, 
                        13, InitialActionList, 13, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[34][2]={ 
    {8,0}, {13,0}, {1,0}, {10,1}, {2,1}, {1,1}, {3,1}, {4,2}, 
    {5,2}, {12,2}, {10,3}, {6,3}, {5,3}, {3,3}, {0,4}, {7,4}, 
    {3,5}, {9,5}, {12,6}, {13,6}, {2,7}, {3,7}, {4,7}, {6,8}, 
    {3,8}, {7,8}, {0,9}, {8,9}, {11,10}, {10,10}, {9,11}, {3,11}, 
    {10,12}, {11,12}
  };
  for(int n=0;n<34;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[25][2]={ 
    {8,0}, {13,0}, {1,1}, {3,1}, {2,1}, {10,1}, {4,2}, {5,3}, 
    {3,3}, {6,3}, {10,3}, {7,4}, {10,5}, {3,5}, {9,5}, {1,5}, 
    {5,5}, {12,6}, {5,6}, {2,7}, {6,8}, {0,9}, {11,10}, {9,11}, 
    {10,12}
  };
  for(int n=0;n<25;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

phases = new short*[numErlangActivities];
phases[0] = &activityMap.phase;
phases[1] = &activityReduce.phase;

  for(int n=0;n<13;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void Q52SAN::CustomInitialization() {

}
Q52SAN::~Q52SAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void Q52SAN::assignPlacesToActivitiesInst(){
  activityGenMap.placeJobReady = (Place*) LocalStateVariables[8];
  activityGenMap.PNextJob = (Place*) LocalStateVariables[13];
  activityGenMap.placeMaps = (Place*) LocalStateVariables[1];
  activityGetResMap.placeMaps = (Place*) LocalStateVariables[1];
  activityGetResMap.placeRes = (Place*) LocalStateVariables[3];
  activityGetResMap.placeMapsReady = (Place*) LocalStateVariables[2];
  activityGetResMap.PlaceActive = (Place*) LocalStateVariables[10];
  activitySynchMaps.placeMaped = (Place*) LocalStateVariables[4];
  activitySynchMaps.placeReduces = (Place*) LocalStateVariables[5];
  activitySynchMaps.PlaceReduceStart = (Place*) LocalStateVariables[12];
  activityGetResReduce.placeReduces = (Place*) LocalStateVariables[5];
  activityGetResReduce.placeRes = (Place*) LocalStateVariables[3];
  activityGetResReduce.placeReducesReady = (Place*) LocalStateVariables[6];
  activityGetResReduce.PlaceActive = (Place*) LocalStateVariables[10];
  activitySynchReduce.placeReduced = (Place*) LocalStateVariables[7];
  activitySynchReduce.placeStart = (Place*) LocalStateVariables[0];
  IATake.PlaceActive = (Place*) LocalStateVariables[10];
  IATake.placeRes = (Place*) LocalStateVariables[3];
  IATake.PlaceRuning = (Place*) LocalStateVariables[9];
  IATake.placeMaps = (Place*) LocalStateVariables[1];
  IATake.placeReduces = (Place*) LocalStateVariables[5];
  IALastReady.PlaceReduceStart = (Place*) LocalStateVariables[12];
  IALastReady.placeReduces = (Place*) LocalStateVariables[5];
  IALastReady.PNextJob = (Place*) LocalStateVariables[13];
}
void Q52SAN::assignPlacesToActivitiesTimed(){
  activityMap.placeMapsReady = (Place*) LocalStateVariables[2];
  activityMap.placeRes = (Place*) LocalStateVariables[3];
  activityMap.placeMaped = (Place*) LocalStateVariables[4];
  activityReduce.placeReducesReady = (Place*) LocalStateVariables[6];
  activityReduce.placeRes = (Place*) LocalStateVariables[3];
  activityReduce.placeReduced = (Place*) LocalStateVariables[7];
  activityThink.placeStart = (Place*) LocalStateVariables[0];
  activityThink.placeJobReady = (Place*) LocalStateVariables[8];
  activityActive.PlaceInactive = (Place*) LocalStateVariables[11];
  activityActive.PlaceActive = (Place*) LocalStateVariables[10];
  activityRun.PlaceRuning = (Place*) LocalStateVariables[9];
  activityRun.placeRes = (Place*) LocalStateVariables[3];
  activityInactive.PlaceActive = (Place*) LocalStateVariables[10];
  activityInactive.PlaceInactive = (Place*) LocalStateVariables[11];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================activityGenMapActivity========================*/


Q52SAN::activityGenMapActivity::activityGenMapActivity(){
  ActivityInitialize("activityGenMap",6,Instantaneous , RaceEnabled, 3,2, false);
}

void Q52SAN::activityGenMapActivity::LinkVariables(){
  placeJobReady->Register(&placeJobReady_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
  placeMaps->Register(&placeMaps_Mobius_Mark);
}

bool Q52SAN::activityGenMapActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(placeJobReady_Mobius_Mark)) >=1)&&((*(PNextJob_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityGenMapActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityGenMapActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityGenMapActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityGenMapActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::activityGenMapActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::activityGenMapActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityGenMapActivity::Fire(){
  (*(placeJobReady_Mobius_Mark))--;
  (*(PNextJob_Mobius_Mark))--;
  placeMaps->Mark()+=NumberOfMaps;
  return this;
}

/*======================activityGetResMapActivity========================*/


Q52SAN::activityGetResMapActivity::activityGetResMapActivity(){
  ActivityInitialize("activityGetResMap",7,Instantaneous , RaceEnabled, 4,4, false);
}

void Q52SAN::activityGetResMapActivity::LinkVariables(){
  placeMaps->Register(&placeMaps_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
  placeMapsReady->Register(&placeMapsReady_Mobius_Mark);
  PlaceActive->Register(&PlaceActive_Mobius_Mark);
}

bool Q52SAN::activityGetResMapActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((placeMaps->Mark()>0) && 
(placeRes->Mark()>0) &&
(
	placeMapsReady->Mark()<(int)(share*NumberOfCores)
	|| 
	PlaceActive->Mark()==0
)));
  return NewEnabled;
}

double Q52SAN::activityGetResMapActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityGetResMapActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityGetResMapActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityGetResMapActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::activityGetResMapActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::activityGetResMapActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityGetResMapActivity::Fire(){
  int reqOtherClass = PlaceActive->Mark();
int permissed = share*NumberOfCores - placeMapsReady->Mark();
int minMarking = placeMaps->Mark();

if (placeRes->Mark() < minMarking)
	minMarking = placeRes->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

placeMaps->Mark() -= minMarking;
placeRes->Mark() -= minMarking;
placeMapsReady->Mark() += minMarking;
  return this;
}

/*======================activitySynchMapsActivity========================*/


Q52SAN::activitySynchMapsActivity::activitySynchMapsActivity(){
  ActivityInitialize("activitySynchMaps",8,Instantaneous , RaceEnabled, 3,1, false);
}

void Q52SAN::activitySynchMapsActivity::LinkVariables(){
  placeMaped->Register(&placeMaped_Mobius_Mark);
  placeReduces->Register(&placeReduces_Mobius_Mark);
  PlaceReduceStart->Register(&PlaceReduceStart_Mobius_Mark);
}

bool Q52SAN::activitySynchMapsActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((placeMaped->Mark() >= NumberOfMaps));
  return NewEnabled;
}

double Q52SAN::activitySynchMapsActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activitySynchMapsActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activitySynchMapsActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activitySynchMapsActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::activitySynchMapsActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::activitySynchMapsActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activitySynchMapsActivity::Fire(){
  placeMaped->Mark() -= NumberOfMaps;
  placeReduces->Mark() += NumberOfReduces;
PlaceReduceStart->Mark() = 1;
  return this;
}

/*======================activityGetResReduceActivity========================*/


Q52SAN::activityGetResReduceActivity::activityGetResReduceActivity(){
  ActivityInitialize("activityGetResReduce",9,Instantaneous , RaceEnabled, 4,4, false);
}

void Q52SAN::activityGetResReduceActivity::LinkVariables(){
  placeReduces->Register(&placeReduces_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
  placeReducesReady->Register(&placeReducesReady_Mobius_Mark);
  PlaceActive->Register(&PlaceActive_Mobius_Mark);
}

bool Q52SAN::activityGetResReduceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((placeReduces->Mark()>0) && 
(placeRes->Mark()>0) &&
(
	placeReducesReady->Mark()<(int)(share*NumberOfCores)
	|| 
	PlaceActive->Mark()==0
)));
  return NewEnabled;
}

double Q52SAN::activityGetResReduceActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityGetResReduceActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityGetResReduceActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityGetResReduceActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::activityGetResReduceActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::activityGetResReduceActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityGetResReduceActivity::Fire(){
  int reqOtherClass = PlaceActive->Mark();
int permissed = share*NumberOfCores - placeReducesReady->Mark();
int minMarking = placeReduces->Mark();

if (placeRes->Mark() < minMarking)
	minMarking = placeRes->Mark();
	
if (reqOtherClass > 0)
{
	if (permissed < minMarking)
		minMarking = permissed;
}

placeReduces->Mark() -= minMarking;
placeRes->Mark() -= minMarking;
placeReducesReady->Mark() += minMarking;
  return this;
}

/*======================activitySynchReduceActivity========================*/


Q52SAN::activitySynchReduceActivity::activitySynchReduceActivity(){
  ActivityInitialize("activitySynchReduce",10,Instantaneous , RaceEnabled, 2,1, false);
}

void Q52SAN::activitySynchReduceActivity::LinkVariables(){
  placeReduced->Register(&placeReduced_Mobius_Mark);
  placeStart->Register(&placeStart_Mobius_Mark);
}

bool Q52SAN::activitySynchReduceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((placeReduced->Mark() >= NumberOfReduces));
  return NewEnabled;
}

double Q52SAN::activitySynchReduceActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activitySynchReduceActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activitySynchReduceActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activitySynchReduceActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::activitySynchReduceActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::activitySynchReduceActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activitySynchReduceActivity::Fire(){
  placeReduced->Mark() -= NumberOfReduces;
  (*(placeStart_Mobius_Mark))++;
  return this;
}

/*======================IATakeActivity========================*/


Q52SAN::IATakeActivity::IATakeActivity(){
  ActivityInitialize("IATake",11,Instantaneous , RaceEnabled, 2,5, false);
}

void Q52SAN::IATakeActivity::LinkVariables(){
  PlaceActive->Register(&PlaceActive_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
  PlaceRuning->Register(&PlaceRuning_Mobius_Mark);
  placeMaps->Register(&placeMaps_Mobius_Mark);
  placeReduces->Register(&placeReduces_Mobius_Mark);
}

bool Q52SAN::IATakeActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((PlaceActive->Mark()>0) && 
(placeRes->Mark()>0) &&
(
	PlaceRuning->Mark()<(int)(shareO*NumberOfCores)
	|| 
	placeMaps->Mark()+placeReduces->Mark()==0
)));
  return NewEnabled;
}

double Q52SAN::IATakeActivity::Weight(){ 
  return 1;
}

bool Q52SAN::IATakeActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::IATakeActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::IATakeActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::IATakeActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::IATakeActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::IATakeActivity::Fire(){
  placeRes->Mark() -= 1;
PlaceRuning->Mark() += 1;
  return this;
}

/*======================IALastReadyActivity========================*/


Q52SAN::IALastReadyActivity::IALastReadyActivity(){
  ActivityInitialize("IALastReady",12,Instantaneous , RaceEnabled, 2,2, false);
}

void Q52SAN::IALastReadyActivity::LinkVariables(){
  PlaceReduceStart->Register(&PlaceReduceStart_Mobius_Mark);
  placeReduces->Register(&placeReduces_Mobius_Mark);
  PNextJob->Register(&PNextJob_Mobius_Mark);
}

bool Q52SAN::IALastReadyActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=((PlaceReduceStart->Mark() > 0 &&
placeReduces->Mark() == 0));
  return NewEnabled;
}

double Q52SAN::IALastReadyActivity::Weight(){ 
  return 1;
}

bool Q52SAN::IALastReadyActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::IALastReadyActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::IALastReadyActivity::SampleDistribution(){
  return 0;
}

double* Q52SAN::IALastReadyActivity::ReturnDistributionParameters(){
    return NULL;
}

int Q52SAN::IALastReadyActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::IALastReadyActivity::Fire(){
  PlaceReduceStart->Mark() = 0;
  PNextJob->Mark() = 1;
  return this;
}

/*======================activityMapActivity========================*/

Q52SAN::activityMapActivity::activityMapActivity(){
  TheDistributionParameters = new double[2];
  ActivityInitialize("activityMap",0,Erlang, RaceEnabled, 3,1, false);
}

Q52SAN::activityMapActivity::~activityMapActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityMapActivity::LinkVariables(){
  placeMapsReady->Register(&placeMapsReady_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
  placeMaped->Register(&placeMaped_Mobius_Mark);
}

bool Q52SAN::activityMapActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(placeMapsReady_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityMapActivity::ErlangParamM(){
  return MapM;
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityMapActivity::ErlangParamBeta(){
  return MapBeta / (double)(placeMapsReady->Mark());
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityMapActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityMapActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityMapActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityMapActivity::SampleDistribution(){
  return TheDistribution->Erlang(MapM, MapBeta / (double)(placeMapsReady->Mark()));
}

double* Q52SAN::activityMapActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = ErlangParamM();
  TheDistributionParameters[1] = ErlangParamBeta();
  return TheDistributionParameters;
}

int Q52SAN::activityMapActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityMapActivity::Fire(){
  (*(placeMapsReady_Mobius_Mark))--;
  (*(placeRes_Mobius_Mark))++;
  (*(placeMaped_Mobius_Mark))++;
  phase = 1;
  return this;
}

/*======================activityReduceActivity========================*/

Q52SAN::activityReduceActivity::activityReduceActivity(){
  TheDistributionParameters = new double[2];
  ActivityInitialize("activityReduce",1,Erlang, RaceEnabled, 3,1, false);
}

Q52SAN::activityReduceActivity::~activityReduceActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityReduceActivity::LinkVariables(){
  placeReducesReady->Register(&placeReducesReady_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
  placeReduced->Register(&placeReduced_Mobius_Mark);
}

bool Q52SAN::activityReduceActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(placeReducesReady_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityReduceActivity::ErlangParamM(){
  return ReduceM;
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityReduceActivity::ErlangParamBeta(){
  return ReduceBeta / (double)(placeReducesReady->Mark());
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityReduceActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityReduceActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityReduceActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityReduceActivity::SampleDistribution(){
  return TheDistribution->Erlang(ReduceM, ReduceBeta / (double)(placeReducesReady->Mark()));
}

double* Q52SAN::activityReduceActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = ErlangParamM();
  TheDistributionParameters[1] = ErlangParamBeta();
  return TheDistributionParameters;
}

int Q52SAN::activityReduceActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityReduceActivity::Fire(){
  (*(placeReducesReady_Mobius_Mark))--;
  (*(placeRes_Mobius_Mark))++;
  (*(placeReduced_Mobius_Mark))++;
  phase = 1;
  return this;
}

/*======================activityThinkActivity========================*/

Q52SAN::activityThinkActivity::activityThinkActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("activityThink",2,Exponential, RaceEnabled, 2,1, false);
}

Q52SAN::activityThinkActivity::~activityThinkActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityThinkActivity::LinkVariables(){
  placeStart->Register(&placeStart_Mobius_Mark);
  placeJobReady->Register(&placeJobReady_Mobius_Mark);
}

bool Q52SAN::activityThinkActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(placeStart_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityThinkActivity::Rate(){
  return ThinkRate * (double)(placeStart->Mark());
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityThinkActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityThinkActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityThinkActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityThinkActivity::SampleDistribution(){
  return TheDistribution->Exponential(ThinkRate * (double)(placeStart->Mark()));
}

double* Q52SAN::activityThinkActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q52SAN::activityThinkActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityThinkActivity::Fire(){
  (*(placeStart_Mobius_Mark))--;
  (*(placeJobReady_Mobius_Mark))++;
  return this;
}

/*======================activityActiveActivity========================*/

Q52SAN::activityActiveActivity::activityActiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("activityActive",3,Exponential, RaceEnabled, 2,1, false);
}

Q52SAN::activityActiveActivity::~activityActiveActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityActiveActivity::LinkVariables(){
  PlaceInactive->Register(&PlaceInactive_Mobius_Mark);
  PlaceActive->Register(&PlaceActive_Mobius_Mark);
}

bool Q52SAN::activityActiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceInactive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityActiveActivity::Rate(){
  return rateActive;
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityActiveActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityActiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityActiveActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityActiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateActive);
}

double* Q52SAN::activityActiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q52SAN::activityActiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityActiveActivity::Fire(){
  (*(PlaceInactive_Mobius_Mark))--;
  (*(PlaceActive_Mobius_Mark))++;
  return this;
}

/*======================activityRunActivity========================*/

Q52SAN::activityRunActivity::activityRunActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("activityRun",4,Exponential, RaceEnabled, 2,1, false);
}

Q52SAN::activityRunActivity::~activityRunActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityRunActivity::LinkVariables(){
  PlaceRuning->Register(&PlaceRuning_Mobius_Mark);
  placeRes->Register(&placeRes_Mobius_Mark);
}

bool Q52SAN::activityRunActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceRuning_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityRunActivity::Rate(){
  return rateReturn;
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityRunActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityRunActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityRunActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityRunActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateReturn);
}

double* Q52SAN::activityRunActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q52SAN::activityRunActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityRunActivity::Fire(){
  (*(PlaceRuning_Mobius_Mark))--;
  (*(placeRes_Mobius_Mark))++;
  return this;
}

/*======================activityInactiveActivity========================*/

Q52SAN::activityInactiveActivity::activityInactiveActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("activityInactive",5,Exponential, RaceEnabled, 2,1, false);
}

Q52SAN::activityInactiveActivity::~activityInactiveActivity(){
  delete[] TheDistributionParameters;
}

void Q52SAN::activityInactiveActivity::LinkVariables(){
  PlaceActive->Register(&PlaceActive_Mobius_Mark);
  PlaceInactive->Register(&PlaceInactive_Mobius_Mark);
}

bool Q52SAN::activityInactiveActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceActive_Mobius_Mark)) >=1));
  return NewEnabled;
}

double Q52SAN::activityInactiveActivity::Rate(){
  return rateInactive;
  return 1.0;  // default rate if none is specified
}

double Q52SAN::activityInactiveActivity::Weight(){ 
  return 1;
}

bool Q52SAN::activityInactiveActivity::ReactivationPredicate(){ 
  return false;
}

bool Q52SAN::activityInactiveActivity::ReactivationFunction(){ 
  return false;
}

double Q52SAN::activityInactiveActivity::SampleDistribution(){
  return TheDistribution->Exponential(rateInactive);
}

double* Q52SAN::activityInactiveActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int Q52SAN::activityInactiveActivity::Rank(){
  return 1;
}

BaseActionClass* Q52SAN::activityInactiveActivity::Fire(){
  (*(PlaceActive_Mobius_Mark))--;
  (*(PlaceInactive_Mobius_Mark))++;
  return this;
}



void Q52SAN::SetState(void* TheState) {
  SANModel::SetState(TheState);

  byte* newmempos = (byte *)TheState;
  // we need this to know the last memory location SANModel::SetState read
  // and get new memory location where phases can begin to be read
  for (int i=0; i < NumStateVariables - NumReadOnlyPlaces; i++)
    if (!LocalStateVariables[i]->getShared())
      newmempos += LocalStateVariables[i]->StateSize();

  for (int i=0; i < numErlangActivities; i++)
    readMemory2<short>(newmempos + i*sizeof(short), phases[i]);
} // end Q52SAN::SetState(void *)

void Q52SAN::CurrentState(void* MemoryLocation) {
  SANModel::CurrentState(MemoryLocation);

  byte* newmempos = (byte *)MemoryLocation;
  // we need this to know the last memory location SANModel::CurrentState wrote
  // and get new memory location where phases can be stored
  for (int i=0; i < NumStateVariables - NumReadOnlyPlaces; i++)
    if (!LocalStateVariables[i]->getShared())
      newmempos += LocalStateVariables[i]->StateSize();

  for (int i=0; i < numErlangActivities; i++)
    writeMemory<short>(*(phases[i]), newmempos + i*sizeof(short));
} // end Q52SAN::CurrentState(void *)

int Q52SAN::StateSize() {
  // use parent class function and add the size of the additional data structure to store phases
  return SANModel::StateSize() + (numErlangActivities * sizeof(short));
} // end Q52SAN::StateSize()

void Q52SAN::printState(ostream *strm) {
  SANModel::printState(strm); // print state variables like any other SAN Model

  (*strm)<<"--------------------------------------"<<endl;

  int erlang_index=0;
  for (int i=0; i<NumActions; i++)
    if ((ActionList[i]->DistributionType) == Erlang) {
      (*strm) << "Phase of " << ActionList[i]->ActionName << ": " << *(phases[erlang_index]) << endl;
      erlang_index++;
    }
  (*strm)<<"--------------------------------------"<<endl;
} // end Q52SAN::printState(ostream*)

bool Q52SAN::CompareState(void* State1, void* State2) {
  if (!SANModel::CompareState(State1, State2))
    return false;

  short offset = sizeof(short)*(NumStateVariables - NumReadOnlyPlaces);

  void* s1 = (void *)((char *)State1 + offset);
  void* s2 = (void *)((char *)State2 + offset);
  return (memcmp(s1, s2,numErlangActivities*sizeof(short)) == 0);
} // end Q52SAN::CompareState(void*, void*)

