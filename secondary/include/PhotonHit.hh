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
// $Id: LXePMTHit.hh 72250 2013-07-12 08:59:26Z gcosmo $
//
/// \file optical/LXe/include/LXePMTHit.hh
/// \brief Definition of the LXePMTHit class
//
//
#ifndef PhotonHit_h
#define PhotonHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"
#include "G4VPhysicalVolume.hh"

#include "tls.hh"

class G4VTouchable;

class PhotonHit : public G4VHit
{
  public:

    virtual void Print();
 
    PhotonHit();
    virtual ~PhotonHit();
    PhotonHit(const PhotonHit &right);

    const PhotonHit& operator=(const PhotonHit &right);
    G4int operator==(const PhotonHit &right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);
 
    inline void IncPhotonCount(){fPhotons++;}
    inline G4int GetPhotonCount(){return fPhotons;}

    inline void SetPMTNumber(G4int n) { fPmtNumber = n; }
    inline G4int GetPMTNumber() { return fPmtNumber; }

  public:

      void SetPathLength  (G4double PathLength)      { fPathLength = PathLength; };
      void SetTimeStep (G4double TimeStep)      { fTimeStep = TimeStep; };  
      void SetReflectionNumber    (G4int ReflectionNumber)      { fReflectionNumber = ReflectionNumber; };

      G4double GetPathLength()    { return fPathLength; };
      G4double GetTimeStep()  { return fTimeStep; };
      G4int GetReflectionNumber()    { return fReflectionNumber; };      

    
 

  private:

    G4int fPmtNumber;
    G4int fPhotons;
    G4double fPathLength;
    G4double fTimeStep;
    G4int fReflectionNumber;

};

typedef G4THitsCollection<PhotonHit> PhotonHitCollection;

extern G4ThreadLocal G4Allocator<PhotonHit>* PhotonHitAllocator;

inline void* PhotonHit::operator new(size_t){
  if(!PhotonHitAllocator)
      PhotonHitAllocator = new G4Allocator<PhotonHit>;
  return (void *) PhotonHitAllocator->MallocSingle();
}

inline void PhotonHit::operator delete(void *aHit){
  PhotonHitAllocator->FreeSingle((PhotonHit*) aHit);
}

#endif
