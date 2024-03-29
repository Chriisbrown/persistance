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
// $Id: LXeSteppingAction.hh 68752 2013-04-05 10:23:47Z gcosmo $
//
/// \file optical/LXe/include/LXeSteppingAction.hh
/// \brief Definition of the LXeSteppingAction class
//
#ifndef LXeSteppingAction_H
#define LXeSteppingACtion_H 1

#include "globals.hh"
#include "G4UserSteppingAction.hh"

#include "G4OpBoundaryProcess.hh"

class LXeRecorderBase;
class LXeEventAction;
class LXeTrackingAction;
class LXeSteppingMessenger;

class LXeSteppingAction : public G4UserSteppingAction
{
  public:

    LXeSteppingAction(LXeRecorderBase*);
    virtual ~LXeSteppingAction();
    virtual void UserSteppingAction(const G4Step*);

    void SetOneStepPrimaries(G4bool b){fOneStepPrimaries=b;}
    G4bool GetOneStepPrimaries(){return fOneStepPrimaries;}

    void ResetCounter() {counterReflect = 0;}
    G4int GetNumberOfBounces(){return counterReflect;}
 
  private:

    LXeRecorderBase* fRecorder;
    G4bool fOneStepPrimaries;
    LXeSteppingMessenger* fSteppingMessenger;

    G4OpBoundaryProcessStatus fExpectedNextStatus;

    G4int counter = 0;


    G4float fL1 = 0;
    G4float fL2 = 0;

    //number of reflections photon has gone through
    G4int counterReflect;
};

#endif
