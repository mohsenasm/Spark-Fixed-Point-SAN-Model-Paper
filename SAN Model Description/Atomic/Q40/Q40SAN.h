#ifndef Q40SAN_H_
#define Q40SAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Double share;
extern Double shareO;
extern Double rateActive;
extern Double rateInactive;
extern Double rateReturn;
extern Int cntUser;
extern Int cntCores;
extern Int cnt1;
extern Int cnt2;
extern Int cnt3;
extern Double avg1;
extern Double avg2;
extern Double avg3;
extern Double rateThink;
extern Int cnt4;
extern Double avg4;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               Q40SAN Submodel Definition                   
*********************************************************************/

class Q40SAN:public SANModel{
public:

class IAStart1Activity:public Activity {
public:

  Place* PReadyJobs;
  short* PReadyJobs_Mobius_Mark;
  Place* PNextJob;
  short* PNextJob_Mobius_Mark;
  Place* PWaiting1;
  short* PWaiting1_Mobius_Mark;
  Place* PWaiting2;
  short* PWaiting2_Mobius_Mark;

  double* TheDistributionParameters;
  IAStart1Activity();
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
}; // IAStart1ActivityActivity

class IAGet1Activity:public Activity {
public:

  Place* PWaiting1;
  short* PWaiting1_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PRunning1;
  short* PRunning1_Mobius_Mark;
  Place* PRunning2;
  short* PRunning2_Mobius_Mark;
  Place* PRunning3;
  short* PRunning3_Mobius_Mark;
  Place* PRunning4;
  short* PRunning4_Mobius_Mark;
  Place* PActive;
  short* PActive_Mobius_Mark;

  double* TheDistributionParameters;
  IAGet1Activity();
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
}; // IAGet1ActivityActivity

class IADone1Activity:public Activity {
public:

  Place* PDone1;
  short* PDone1_Mobius_Mark;
  Place* PDone2;
  short* PDone2_Mobius_Mark;
  Place* PWaiting3;
  short* PWaiting3_Mobius_Mark;

  double* TheDistributionParameters;
  IADone1Activity();
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
}; // IADone1ActivityActivity

class IAGet4Activity:public Activity {
public:

  Place* PWaiting4;
  short* PWaiting4_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PRunning1;
  short* PRunning1_Mobius_Mark;
  Place* PRunning2;
  short* PRunning2_Mobius_Mark;
  Place* PRunning3;
  short* PRunning3_Mobius_Mark;
  Place* PRunning4;
  short* PRunning4_Mobius_Mark;
  Place* PActive;
  short* PActive_Mobius_Mark;

  double* TheDistributionParameters;
  IAGet4Activity();
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
}; // IAGet4ActivityActivity

class IADone4Activity:public Activity {
public:

  Place* PDone4;
  short* PDone4_Mobius_Mark;
  Place* PStart;
  short* PStart_Mobius_Mark;

  double* TheDistributionParameters;
  IADone4Activity();
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
}; // IADone4ActivityActivity

class IAGetOActivity:public Activity {
public:

  Place* PActive;
  short* PActive_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PRunningO;
  short* PRunningO_Mobius_Mark;
  Place* PWaiting1;
  short* PWaiting1_Mobius_Mark;
  Place* PWaiting2;
  short* PWaiting2_Mobius_Mark;
  Place* PWaiting3;
  short* PWaiting3_Mobius_Mark;
  Place* PWaiting4;
  short* PWaiting4_Mobius_Mark;

  double* TheDistributionParameters;
  IAGetOActivity();
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
}; // IAGetOActivityActivity

class IALastReadyActivity:public Activity {
public:

  Place* PStartLast;
  short* PStartLast_Mobius_Mark;
  Place* PWaiting4;
  short* PWaiting4_Mobius_Mark;
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

class IAGet3Activity:public Activity {
public:

  Place* PWaiting3;
  short* PWaiting3_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PRunning1;
  short* PRunning1_Mobius_Mark;
  Place* PRunning2;
  short* PRunning2_Mobius_Mark;
  Place* PRunning3;
  short* PRunning3_Mobius_Mark;
  Place* PRunning4;
  short* PRunning4_Mobius_Mark;
  Place* PActive;
  short* PActive_Mobius_Mark;

  double* TheDistributionParameters;
  IAGet3Activity();
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
}; // IAGet3ActivityActivity

class IADone3Activity:public Activity {
public:

  Place* PDone3;
  short* PDone3_Mobius_Mark;
  Place* PWaiting4;
  short* PWaiting4_Mobius_Mark;
  Place* PStartLast;
  short* PStartLast_Mobius_Mark;

  double* TheDistributionParameters;
  IADone3Activity();
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
}; // IADone3ActivityActivity

class IAGet2Activity:public Activity {
public:

  Place* PWaiting2;
  short* PWaiting2_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PRunning1;
  short* PRunning1_Mobius_Mark;
  Place* PRunning2;
  short* PRunning2_Mobius_Mark;
  Place* PRunning3;
  short* PRunning3_Mobius_Mark;
  Place* PRunning4;
  short* PRunning4_Mobius_Mark;
  Place* PActive;
  short* PActive_Mobius_Mark;

  double* TheDistributionParameters;
  IAGet2Activity();
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
}; // IAGet2ActivityActivity

class TAExec1Activity:public Activity {
public:

  Place* PRunning1;
  short* PRunning1_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PDone1;
  short* PDone1_Mobius_Mark;

  double* TheDistributionParameters;
  TAExec1Activity();
  ~TAExec1Activity();
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
}; // TAExec1ActivityActivity

class TAExec4Activity:public Activity {
public:

  Place* PRunning4;
  short* PRunning4_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PDone4;
  short* PDone4_Mobius_Mark;

  double* TheDistributionParameters;
  TAExec4Activity();
  ~TAExec4Activity();
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
}; // TAExec4ActivityActivity

class TAThinkActivity:public Activity {
public:

  Place* PStart;
  short* PStart_Mobius_Mark;
  Place* PReadyJobs;
  short* PReadyJobs_Mobius_Mark;

  double* TheDistributionParameters;
  TAThinkActivity();
  ~TAThinkActivity();
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
}; // TAThinkActivityActivity

class TAActiveActivity:public Activity {
public:

  Place* PInactive;
  short* PInactive_Mobius_Mark;
  Place* PActive;
  short* PActive_Mobius_Mark;

  double* TheDistributionParameters;
  TAActiveActivity();
  ~TAActiveActivity();
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
}; // TAActiveActivityActivity

class TAExecOActivity:public Activity {
public:

  Place* PRunningO;
  short* PRunningO_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;

  double* TheDistributionParameters;
  TAExecOActivity();
  ~TAExecOActivity();
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
}; // TAExecOActivityActivity

class TAInactiveActivity:public Activity {
public:

  Place* PActive;
  short* PActive_Mobius_Mark;
  Place* PInactive;
  short* PInactive_Mobius_Mark;

  double* TheDistributionParameters;
  TAInactiveActivity();
  ~TAInactiveActivity();
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
}; // TAInactiveActivityActivity

class TAExec3Activity:public Activity {
public:

  Place* PRunning3;
  short* PRunning3_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PDone3;
  short* PDone3_Mobius_Mark;

  double* TheDistributionParameters;
  TAExec3Activity();
  ~TAExec3Activity();
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
}; // TAExec3ActivityActivity

class TAExec2Activity:public Activity {
public:

  Place* PRunning2;
  short* PRunning2_Mobius_Mark;
  Place* PCores;
  short* PCores_Mobius_Mark;
  Place* PDone2;
  short* PDone2_Mobius_Mark;

  double* TheDistributionParameters;
  TAExec2Activity();
  ~TAExec2Activity();
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
}; // TAExec2ActivityActivity

  //List of user-specified place names
  Place* PStart;
  Place* PWaiting1;
  Place* PRunning1;
  Place* PCores;
  Place* PDone1;
  Place* PWaiting4;
  Place* PRunning4;
  Place* PDone4;
  Place* PReadyJobs;
  Place* PRunningO;
  Place* PActive;
  Place* PInactive;
  Place* PStartLast;
  Place* PNextJob;
  Place* PWaiting3;
  Place* PRunning3;
  Place* PDone3;
  Place* PWaiting2;
  Place* PRunning2;
  Place* PDone2;

  // Create instances of all actvities
  IAStart1Activity IAStart1;
  IAGet1Activity IAGet1;
  IADone1Activity IADone1;
  IAGet4Activity IAGet4;
  IADone4Activity IADone4;
  IAGetOActivity IAGetO;
  IALastReadyActivity IALastReady;
  IAGet3Activity IAGet3;
  IADone3Activity IADone3;
  IAGet2Activity IAGet2;
  TAExec1Activity TAExec1;
  TAExec4Activity TAExec4;
  TAThinkActivity TAThink;
  TAActiveActivity TAActive;
  TAExecOActivity TAExecO;
  TAInactiveActivity TAInactive;
  TAExec3Activity TAExec3;
  TAExec2Activity TAExec2;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup IAStart1Group;
  PostselectGroup IAGet1Group;
  PostselectGroup IADone1Group;
  PostselectGroup IAGet4Group;
  PostselectGroup IADone4Group;
  PostselectGroup IAGetOGroup;
  PostselectGroup IALastReadyGroup;
  PostselectGroup IAGet3Group;
  PostselectGroup IADone3Group;
  PostselectGroup IAGet2Group;

  Q40SAN();
  ~Q40SAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end Q40SAN

#endif // Q40SAN_H_
