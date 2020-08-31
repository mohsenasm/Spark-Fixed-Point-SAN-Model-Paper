#ifndef Q52SAN_H_
#define Q52SAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Int NumberOfCores;
extern Int NumberOfMaps;
extern Int NumberOfReduces;
extern Double MapM;
extern Double MapBeta;
extern Double ThinkRate;
extern Double ReduceBeta;
extern Double ReduceM;
extern Double share;
extern Double shareO;
extern Double rateActive;
extern Double rateInactive;
extern Double rateReturn;
extern Int cntUser;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               Q52SAN Submodel Definition                   
*********************************************************************/

class Q52SAN:public SANModel{
public:
const static int numErlangActivities = 2;

class activityGenMapActivity:public Activity {
public:

  Place* placeJobReady;
  short* placeJobReady_Mobius_Mark;
  Place* PNextJob;
  short* PNextJob_Mobius_Mark;
  Place* placeMaps;
  short* placeMaps_Mobius_Mark;

  double* TheDistributionParameters;
  activityGenMapActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // activityGenMapActivityActivity

class activityGetResMapActivity:public Activity {
public:

  Place* placeMaps;
  short* placeMaps_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;
  Place* placeMapsReady;
  short* placeMapsReady_Mobius_Mark;
  Place* PlaceActive;
  short* PlaceActive_Mobius_Mark;

  double* TheDistributionParameters;
  activityGetResMapActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // activityGetResMapActivityActivity

class activitySynchMapsActivity:public Activity {
public:

  Place* placeMaped;
  short* placeMaped_Mobius_Mark;
  Place* placeReduces;
  short* placeReduces_Mobius_Mark;
  Place* PlaceReduceStart;
  short* PlaceReduceStart_Mobius_Mark;

  double* TheDistributionParameters;
  activitySynchMapsActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // activitySynchMapsActivityActivity

class activityGetResReduceActivity:public Activity {
public:

  Place* placeReduces;
  short* placeReduces_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;
  Place* placeReducesReady;
  short* placeReducesReady_Mobius_Mark;
  Place* PlaceActive;
  short* PlaceActive_Mobius_Mark;

  double* TheDistributionParameters;
  activityGetResReduceActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // activityGetResReduceActivityActivity

class activitySynchReduceActivity:public Activity {
public:

  Place* placeReduced;
  short* placeReduced_Mobius_Mark;
  Place* placeStart;
  short* placeStart_Mobius_Mark;

  double* TheDistributionParameters;
  activitySynchReduceActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // activitySynchReduceActivityActivity

class IATakeActivity:public Activity {
public:

  Place* PlaceActive;
  short* PlaceActive_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;
  Place* PlaceRuning;
  short* PlaceRuning_Mobius_Mark;
  Place* placeMaps;
  short* placeMaps_Mobius_Mark;
  Place* placeReduces;
  short* placeReduces_Mobius_Mark;

  double* TheDistributionParameters;
  IATakeActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // IATakeActivityActivity

class IALastReadyActivity:public Activity {
public:

  Place* PlaceReduceStart;
  short* PlaceReduceStart_Mobius_Mark;
  Place* placeReduces;
  short* placeReduces_Mobius_Mark;
  Place* PNextJob;
  short* PNextJob_Mobius_Mark;

  double* TheDistributionParameters;
  IALastReadyActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // IALastReadyActivityActivity

class activityMapActivity:public Activity {
public:

  Place* placeMapsReady;
  short* placeMapsReady_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;
  Place* placeMaped;
  short* placeMaped_Mobius_Mark;

  double* TheDistributionParameters;
  activityMapActivity();
  ~activityMapActivity();
  double Rate(){return (ErlangParamM()/ErlangParamBeta());}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double ErlangParamM();
  double ErlangParamBeta();
}; // activityMapActivityActivity

class activityReduceActivity:public Activity {
public:

  Place* placeReducesReady;
  short* placeReducesReady_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;
  Place* placeReduced;
  short* placeReduced_Mobius_Mark;

  double* TheDistributionParameters;
  activityReduceActivity();
  ~activityReduceActivity();
  double Rate(){return (ErlangParamM()/ErlangParamBeta());}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double ErlangParamM();
  double ErlangParamBeta();
}; // activityReduceActivityActivity

class activityThinkActivity:public Activity {
public:

  Place* placeStart;
  short* placeStart_Mobius_Mark;
  Place* placeJobReady;
  short* placeJobReady_Mobius_Mark;

  double* TheDistributionParameters;
  activityThinkActivity();
  ~activityThinkActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // activityThinkActivityActivity

class activityActiveActivity:public Activity {
public:

  Place* PlaceInactive;
  short* PlaceInactive_Mobius_Mark;
  Place* PlaceActive;
  short* PlaceActive_Mobius_Mark;

  double* TheDistributionParameters;
  activityActiveActivity();
  ~activityActiveActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // activityActiveActivityActivity

class activityRunActivity:public Activity {
public:

  Place* PlaceRuning;
  short* PlaceRuning_Mobius_Mark;
  Place* placeRes;
  short* placeRes_Mobius_Mark;

  double* TheDistributionParameters;
  activityRunActivity();
  ~activityRunActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // activityRunActivityActivity

class activityInactiveActivity:public Activity {
public:

  Place* PlaceActive;
  short* PlaceActive_Mobius_Mark;
  Place* PlaceInactive;
  short* PlaceInactive_Mobius_Mark;

  double* TheDistributionParameters;
  activityInactiveActivity();
  ~activityInactiveActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // activityInactiveActivityActivity

  //List of user-specified place names
  Place* placeStart;
  Place* placeMaps;
  Place* placeMapsReady;
  Place* placeRes;
  Place* placeMaped;
  Place* placeReduces;
  Place* placeReducesReady;
  Place* placeReduced;
  Place* placeJobReady;
  Place* PlaceRuning;
  Place* PlaceActive;
  Place* PlaceInactive;
  Place* PlaceReduceStart;
  Place* PNextJob;

// array storing phase of all erlang activities
short** phases;

  // Create instances of all actvities
  activityGenMapActivity activityGenMap;
  activityGetResMapActivity activityGetResMap;
  activitySynchMapsActivity activitySynchMaps;
  activityGetResReduceActivity activityGetResReduce;
  activitySynchReduceActivity activitySynchReduce;
  IATakeActivity IATake;
  IALastReadyActivity IALastReady;
  activityMapActivity activityMap;
  activityReduceActivity activityReduce;
  activityThinkActivity activityThink;
  activityActiveActivity activityActive;
  activityRunActivity activityRun;
  activityInactiveActivity activityInactive;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup activityGenMapGroup;
  PostselectGroup activityGetResMapGroup;
  PostselectGroup activitySynchMapsGroup;
  PostselectGroup activityGetResReduceGroup;
  PostselectGroup activitySynchReduceGroup;
  PostselectGroup IATakeGroup;
  PostselectGroup IALastReadyGroup;

  Q52SAN();
  ~Q52SAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
void SetState(void *);
void CurrentState(void *);
int StateSize();
void printState(ostream *strm);
bool CompareState(void*, void*);

}; // end Q52SAN

#endif // Q52SAN_H_
