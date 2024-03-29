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
// $Id: LXePMTSD.cc 73915 2013-09-17 07:32:26Z gcosmo $
//
/// \file optical/LXe/src/LXePMTSD.cc
/// \brief Implementation of the LXePMTSD class
//
//
#include "LXePMTSD.hh"
#include "LXePMTHit.hh"
#include "PhotonHit.hh"
#include "LXeDetectorConstruction.hh"
#include "LXeUserTrackInformation.hh"

#include "G4RunManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4ios.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleDefinition.hh"

#include "LXeSteppingAction.hh"
#include "LXeEventAction.hh"
#include "LXeTrackingAction.hh"
#include "LXeTrajectory.hh"
#include "LXeUserTrackInformation.hh"
#include "LXeUserEventInformation.hh"
#include "LXeRecorderBase.hh"

#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4EventManager.hh"
#include "G4ProcessManager.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4ios.hh"
#include "G4UImanager.hh"

#include "RootIO.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePMTSD::LXePMTSD(G4String name)
  : G4VSensitiveDetector(name),fPMTHitCollection(0),fPhotonHitCollection(0),fPMTPositionsX(0)
  ,fPMTPositionsY(0),fPMTPositionsZ(0)
{
  collectionName.insert("pmtHitCollection");
  collectionName.insert("PhotonHitCollection");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LXePMTSD::~LXePMTSD()
{
  RootIO::GetInstance()->Close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::SetPmtPositions(const std::vector<G4ThreeVector>& positions)
{
  for (G4int i=0; i<G4int(positions.size()); ++i) {
    if(fPMTPositionsX)fPMTPositionsX->push_back(positions[i].x());
    if(fPMTPositionsY)fPMTPositionsY->push_back(positions[i].y());
    if(fPMTPositionsZ)fPMTPositionsZ->push_back(positions[i].z());
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::Initialize(G4HCofThisEvent* hitsCE){
  fPMTHitCollection = new LXePMTHitsCollection
                      (SensitiveDetectorName,collectionName[0]);
  fPhotonHitCollection = new PhotonHitCollection
                      (SensitiveDetectorName,collectionName[0]);
  //Store collection with event and keep ID
  static G4int hitCID = -1;
  if(hitCID<0){
    hitCID = GetCollectionID(0);
  }
  hitsCE->AddHitsCollection( hitCID, fPMTHitCollection );
  hitsCE->AddHitsCollection( hitCID, fPhotonHitCollection );
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool LXePMTSD::ProcessHits(G4Step* ,G4TouchableHistory* ){
  return false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//Generates a hit and uses the postStepPoint's mother volume replica number
//PostStepPoint because the hit is generated manually when the photon is
//absorbed by the photocathode

G4bool LXePMTSD::ProcessHits_constStep(const G4Step* aStep,
                                       G4TouchableHistory* ){

  //need to know if this is an optical photon
  if(aStep->GetTrack()->GetDefinition()
     != G4OpticalPhoton::OpticalPhotonDefinition()) return false;
 
  //User replica number 1 since photocathode is a daughter volume
  //to the pmt which was replicated
  G4int pmtNumber=
    aStep->GetPostStepPoint()->GetTouchable()->GetReplicaNumber(1);
  G4VPhysicalVolume* physVol=
    aStep->GetPostStepPoint()->GetTouchable()->GetVolume(1);

  //Find the correct hit collection
  G4int n=fPMTHitCollection->entries();
  LXePMTHit* hit=NULL;
  for(G4int i=0;i<n;i++){
    if((*fPMTHitCollection)[i]->GetPMTNumber()==pmtNumber){
      hit=(*fPMTHitCollection)[i];
      break;
    }
  }
  G4int np=fPhotonHitCollection->entries();
  PhotonHit* hitp=NULL;
  for(G4int i=0;i<np;i++){
    if((*fPhotonHitCollection)[i]->GetPMTNumber()==pmtNumber){
      hitp=(*fPhotonHitCollection)[i];
      break;
    }
  }
 
  if(hitp==NULL){//this pmt wasnt previously hit in this event
    hitp = new PhotonHit(); //so create new hit
    hitp->SetPMTNumber(pmtNumber);

    fPhotonHitCollection->insert(hitp);
  }

  if(hit==NULL){//this pmt wasnt previously hit in this event
  hit = new LXePMTHit(); //so create new hit
  hit->SetPMTNumber(pmtNumber);
  hit->SetPMTPhysVol(physVol);
  fPMTHitCollection->insert(hit);
  hit->SetPMTPos((*fPMTPositionsX)[pmtNumber],(*fPMTPositionsY)[pmtNumber],
                  (*fPMTPositionsZ)[pmtNumber]);
  }

  hit->IncPhotonCount(); //increment hit for the selected pmt
  hitp->IncPhotonCount();

  const G4Event* evt = G4RunManager::GetRunManager()->GetCurrentEvent();
  if (evt->GetEventID() == eID) {
  } else {
      if (evt) eID = evt->GetEventID();
      photon_counter = 0;
  }

  photon_counter += 1;

  G4Track* theTrack = aStep->GetTrack();
  G4float path_length = theTrack->GetTrackLength();

  hitp->SetPathLength (path_length);

  G4float local_time = theTrack->GetLocalTime();

  hitp->SetTimeStep (local_time);

  G4StepPoint* thePrePoint = aStep->GetPreStepPoint();
  G4VPhysicalVolume* thePrePV = thePrePoint->GetPhysicalVolume();

  G4StepPoint* thePostPoint = aStep->GetPostStepPoint();
  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();

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

  G4int reflections = GetNumberOfBounces();
  hitp-> SetReflectionNumber (reflections);
  

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::EndOfEvent(G4HCofThisEvent*) 
{
 G4int NbHits = fPhotonHitCollection->entries();
  std::vector<PhotonHit*> hitsVector;

  { 
    G4cout << "\n-------->Storing hits in the ROOT file: in this event there are " << NbHits 
           << " hits in the tracker chambers: " << G4endl;
    for (G4int i=0;i<NbHits;i++) (*fPhotonHitCollection)[i]->Print();
  } 

  
  for (G4int i=0;i<NbHits;i++) 
    hitsVector.push_back((*fPhotonHitCollection)[i]);
  
  RootIO::GetInstance()->Write(&hitsVector);

  //
}
 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::clear() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::DrawAll() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LXePMTSD::PrintAll() {}
