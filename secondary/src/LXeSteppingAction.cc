//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: LXeSteppingAction.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/LXe/src/LXeSteppingAction.cc
/// \brief Implementation of the LXeSteppingAction class
//
//
#include "LXeSteppingAction.hh"
#include "LXeEventAction.hh"
#include "LXeTrackingAction.hh"
#include "LXeTrajectory.hh"
#include "LXePMTSD.hh"
#include "LXeUserTrackInformation.hh"
#include "LXeUserEventInformation.hh"
#include "LXeSteppingMessenger.hh"
#include "LXeRecorderBase.hh"

#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4EventManager.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeSteppingAction::LXeSteppingAction(LXeRecorderBase* r)
  : fRecorder(r),fOneStepPrimaries(false)
{
  fSteppingMessenger = new LXeSteppingMessenger(this);

  fExpectedNextStatus = Undefined;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXeSteppingAction::~LXeSteppingAction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXeSteppingAction::UserSteppingAction(const G4Step * theStep){

  G4Track* theTrack = theStep->GetTrack();

  if ( theTrack->GetCurrentStepNumber() == 1 ) fExpectedNextStatus = Undefined;
 
  LXeUserTrackInformation* trackInformation
    =(LXeUserTrackInformation*)theTrack->GetUserInformation();
  LXeUserEventInformation* eventInformation
    =(LXeUserEventInformation*)G4EventManager::GetEventManager()
    ->GetConstCurrentEvent()->GetUserInformation();

  G4StepPoint* thePrePoint = theStep->GetPreStepPoint();
  G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

  G4StepPoint* thePostPoint = theStep->GetPostStepPoint();
  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();

  G4OpBoundaryProcessStatus boundaryStatus=Undefined;
  static G4ThreadLocal G4OpBoundaryProcess* boundary=NULL;

    if (thePostPoint->GetStepStatus() == fGeomBoundary) {
       if(thePrePV->GetName() == "name1" && thePostPV->GetName() == "name")
          fL1 = theTrack->GetTrackLength(); // leaving volume1
      if(thePrePV->GetName() == "name" && thePostPV->GetName() == "name2")
          fL2 = theTrack->GetTrackLength(); // entering volume2
      fL2 = theTrack->GetTrackLength();
    }
    if (fL2 > fL1) {
       G4double diff = fL2 - fL1;
       //G4cout << "Path Length: " << diff << "cm" << G4endl;
       fL2 = fL1 = 0;
    }

    G4String thePostPVname = " ";
    G4String thePrePVname = " ";
    if ( thePostPV ) {
       thePostPVname = thePostPV->GetName();
       thePrePVname = thePrePV->GetName();
       //G4cout << "Post PV: " << thePostPVname << "  Pre PV: " << thePrePVname << G4endl;
       //G4cout << thePostPVname << G4endl;
        if ( thePostPVname == "pmt" ) {
          //G4cout << "Path Length - PMT: " << theTrack->GetTrackLength() << "cm" << G4endl;
        }
        if ( thePostPVname.find("photocath") == 0) {

          G4float path_length = theTrack->GetTrackLength();
          G4String pmt_number = thePostPVname.back();
          //G4float global_time = theTrack->GetGlobalTime();
          G4float local_time = theTrack->GetLocalTime();

          // G4cout << "\nPhoton Number: " << counter << G4endl;
           // G4cout << "Path Length: " << path_length << "cm" << G4endl;
           // G4cout << "PMT Number: " << pmt_number << G4endl;
           //G4cout << "Global Time: " << global_time << "ns idk" << G4endl;
           // G4cout << "Local Time: " << local_time << "ns idk" << G4endl;

           G4int reflections = GetNumberOfBounces();
           ResetCounter();

           // G4cout << "Number of Reflections: " << reflections << G4endl;

           counter += 1;
         }
       }
    //Discard photons that exit the world volume
    if (!thePostPV) {
      ResetCounter();
    }
    //discard photons that were absorbed
    if (theTrack -> GetTrackStatus() != fAlive) {
      ResetCounter();
    }


    //Retrieve status of photon
    G4OpBoundaryProcessStatus theStatus = Undefined;

    G4ProcessManager* OpManager = G4OpticalPhoton::OpticalPhoton() -> GetProcessManager();

    if (OpManager) {
      G4int MAXofPostStepLoops = OpManager -> GetPostStepProcessVector() -> entries();
      G4ProcessVector* fPostStepDoItVector = OpManager -> GetPostStepProcessVector(typeDoIt);

      for (G4int i = 0; i < MAXofPostStepLoops; i++) {
        G4VProcess* fCurrentProcess = (*fPostStepDoItVector)[i];
        G4OpBoundaryProcess* opProcess = dynamic_cast < G4OpBoundaryProcess* > (fCurrentProcess);
        if (opProcess) {
          theStatus = opProcess -> GetStatus();
          break;
        }
      }

      switch (theStatus) {
        case TotalInternalReflection:
        case FresnelReflection:
        case LambertianReflection:
        case LobeReflection:
        case SpikeReflection:
              counterReflect++;
      }
    }

    // if((trackInformation->GetTrackStatus()&hitPMT)){
    //   G4cout << "Path Length: " << theTrack->GetTrackLength() << "cm" << G4endl;
    //
    // }






  //find the boundary process only once
  if(!boundary){
    G4ProcessManager* pm
      = theStep->GetTrack()->GetDefinition()->GetProcessManager();
    G4int nprocesses = pm->GetProcessListLength();
    G4ProcessVector* pv = pm->GetProcessList();
    G4int i;
    for( i=0;i<nprocesses;i++){
      if((*pv)[i]->GetProcessName()=="OpBoundary"){
        boundary = (G4OpBoundaryProcess*)(*pv)[i];
        break;
      }
    }
  }

  if(theTrack->GetParentID()==0){
    //This is a primary track
 
    G4TrackVector* fSecondary=fpSteppingManager->GetfSecondary();
    G4int tN2ndariesTot = fpSteppingManager->GetfN2ndariesAtRestDoIt()
      + fpSteppingManager->GetfN2ndariesAlongStepDoIt()
      + fpSteppingManager->GetfN2ndariesPostStepDoIt();

    //If we havent already found the conversion position and there were
    //secondaries generated, then search for it
    if(!eventInformation->IsConvPosSet() && tN2ndariesTot>0 ){
      for(size_t lp1=(*fSecondary).size()-tN2ndariesTot;
          lp1<(*fSecondary).size(); lp1++){
        const G4VProcess* creator=(*fSecondary)[lp1]->GetCreatorProcess();
        if(creator){
          G4String creatorName=creator->GetProcessName();
          if(creatorName=="phot"||creatorName=="compt"||creatorName=="conv"){
            //since this is happening before the secondary is being tracked
            //the Vertex position has not been set yet(set in initial step)
            eventInformation->SetConvPos((*fSecondary)[lp1]->GetPosition());
          }
        }
      }
    }

    if(fOneStepPrimaries&&thePrePV->GetName()=="scintillator")
      theTrack->SetTrackStatus(fStopAndKill);
  }

  if(!thePostPV){//out of world
    fExpectedNextStatus=Undefined;
    return;
  }

  G4ParticleDefinition* particleType = theTrack->GetDefinition();
  if(particleType==G4OpticalPhoton::OpticalPhotonDefinition()){
    //Optical photon only

    if(thePrePV->GetName()=="Slab")
      //force drawing of photons in WLS slab
      trackInformation->SetForceDrawTrajectory(true);
    else if(thePostPV->GetName()=="expHall")
      //Kill photons entering expHall from something other than Slab
      theTrack->SetTrackStatus(fStopAndKill);

    //Was the photon absorbed by the absorption process
    if(thePostPoint->GetProcessDefinedStep()->GetProcessName()
       =="OpAbsorption"){
      eventInformation->IncAbsorption();
      trackInformation->AddTrackStatusFlag(absorbed);
    }

    boundaryStatus=boundary->GetStatus();

    //Check to see if the partcile was actually at a boundary
    //Otherwise the boundary status may not be valid
    //Prior to Geant4.6.0-p1 this would not have been enough to check
    if(thePostPoint->GetStepStatus()==fGeomBoundary){
      if(fExpectedNextStatus==StepTooSmall){
        if(boundaryStatus!=StepTooSmall){
          G4ExceptionDescription ed;
          ed << "LXeSteppingAction::UserSteppingAction(): "
                << "No reallocation step after reflection!"
                << G4endl;
          G4Exception("LXeSteppingAction::UserSteppingAction()", "LXeExpl01",
          JustWarning,ed,
          "Something is wrong with the surface normal or geometry");
        }
      }
      fExpectedNextStatus=Undefined;
      switch(boundaryStatus){
      case Absorption:
        trackInformation->AddTrackStatusFlag(boundaryAbsorbed);
        eventInformation->IncBoundaryAbsorption();
        break;
      case Detection: //Note, this assumes that the volume causing detection
                      //is the photocathode because it is the only one with
                      //non-zero efficiency
        {
        //Triger sensitive detector manually since photon is
        //absorbed but status was Detection
        G4SDManager* SDman = G4SDManager::GetSDMpointer();
        G4String sdName="/LXeDet/pmtSD";
        LXePMTSD* pmtSD = (LXePMTSD*)SDman->FindSensitiveDetector(sdName);
        if(pmtSD)pmtSD->ProcessHits_constStep(theStep,NULL);
        trackInformation->AddTrackStatusFlag(hitPMT);
        break;
        }
      case FresnelReflection:
      case TotalInternalReflection:
      case LambertianReflection:
      case LobeReflection:
      case SpikeReflection:
      case BackScattering:
        trackInformation->IncReflections();
        fExpectedNextStatus=StepTooSmall;
        break;
      default:
        break;
      }
    }
  }

  if(fRecorder)fRecorder->RecordStep(theStep);
}
