// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExP01Classes

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/usersc/cb15760/persistance/secondary/include/ExP01Classes.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *G4String_Dictionary();
   static void G4String_TClassManip(TClass*);
   static void *new_G4String(void *p = 0);
   static void *newArray_G4String(Long_t size, void *p);
   static void delete_G4String(void *p);
   static void deleteArray_G4String(void *p);
   static void destruct_G4String(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G4String*)
   {
      ::G4String *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G4String));
      static ::ROOT::TGenericClassInfo 
         instance("G4String", "G4String.hh", 59,
                  typeid(::G4String), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G4String_Dictionary, isa_proxy, 4,
                  sizeof(::G4String) );
      instance.SetNew(&new_G4String);
      instance.SetNewArray(&newArray_G4String);
      instance.SetDelete(&delete_G4String);
      instance.SetDeleteArray(&deleteArray_G4String);
      instance.SetDestructor(&destruct_G4String);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G4String*)
   {
      return GenerateInitInstanceLocal((::G4String*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G4String*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G4String_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G4String*)0x0)->GetClass();
      G4String_TClassManip(theClass);
   return theClass;
   }

   static void G4String_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *G4VHit_Dictionary();
   static void G4VHit_TClassManip(TClass*);
   static void *new_G4VHit(void *p = 0);
   static void *newArray_G4VHit(Long_t size, void *p);
   static void delete_G4VHit(void *p);
   static void deleteArray_G4VHit(void *p);
   static void destruct_G4VHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G4VHit*)
   {
      ::G4VHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G4VHit));
      static ::ROOT::TGenericClassInfo 
         instance("G4VHit", "G4VHit.hh", 48,
                  typeid(::G4VHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G4VHit_Dictionary, isa_proxy, 4,
                  sizeof(::G4VHit) );
      instance.SetNew(&new_G4VHit);
      instance.SetNewArray(&newArray_G4VHit);
      instance.SetDelete(&delete_G4VHit);
      instance.SetDeleteArray(&deleteArray_G4VHit);
      instance.SetDestructor(&destruct_G4VHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G4VHit*)
   {
      return GenerateInitInstanceLocal((::G4VHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G4VHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G4VHit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G4VHit*)0x0)->GetClass();
      G4VHit_TClassManip(theClass);
   return theClass;
   }

   static void G4VHit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CLHEPcLcLHep3Vector_Dictionary();
   static void CLHEPcLcLHep3Vector_TClassManip(TClass*);
   static void *new_CLHEPcLcLHep3Vector(void *p = 0);
   static void *newArray_CLHEPcLcLHep3Vector(Long_t size, void *p);
   static void delete_CLHEPcLcLHep3Vector(void *p);
   static void deleteArray_CLHEPcLcLHep3Vector(void *p);
   static void destruct_CLHEPcLcLHep3Vector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CLHEP::Hep3Vector*)
   {
      ::CLHEP::Hep3Vector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CLHEP::Hep3Vector));
      static ::ROOT::TGenericClassInfo 
         instance("CLHEP::Hep3Vector", "CLHEP/Vector/ThreeVector.h", 41,
                  typeid(::CLHEP::Hep3Vector), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CLHEPcLcLHep3Vector_Dictionary, isa_proxy, 4,
                  sizeof(::CLHEP::Hep3Vector) );
      instance.SetNew(&new_CLHEPcLcLHep3Vector);
      instance.SetNewArray(&newArray_CLHEPcLcLHep3Vector);
      instance.SetDelete(&delete_CLHEPcLcLHep3Vector);
      instance.SetDeleteArray(&deleteArray_CLHEPcLcLHep3Vector);
      instance.SetDestructor(&destruct_CLHEPcLcLHep3Vector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CLHEP::Hep3Vector*)
   {
      return GenerateInitInstanceLocal((::CLHEP::Hep3Vector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CLHEP::Hep3Vector*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CLHEPcLcLHep3Vector_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CLHEP::Hep3Vector*)0x0)->GetClass();
      CLHEPcLcLHep3Vector_TClassManip(theClass);
   return theClass;
   }

   static void CLHEPcLcLHep3Vector_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PhotonHit_Dictionary();
   static void PhotonHit_TClassManip(TClass*);
   static void *new_PhotonHit(void *p = 0);
   static void *newArray_PhotonHit(Long_t size, void *p);
   static void delete_PhotonHit(void *p);
   static void deleteArray_PhotonHit(void *p);
   static void destruct_PhotonHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PhotonHit*)
   {
      ::PhotonHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PhotonHit));
      static ::ROOT::TGenericClassInfo 
         instance("PhotonHit", "PhotonHit.hh", 48,
                  typeid(::PhotonHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PhotonHit_Dictionary, isa_proxy, 4,
                  sizeof(::PhotonHit) );
      instance.SetNew(&new_PhotonHit);
      instance.SetNewArray(&newArray_PhotonHit);
      instance.SetDelete(&delete_PhotonHit);
      instance.SetDeleteArray(&deleteArray_PhotonHit);
      instance.SetDestructor(&destruct_PhotonHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PhotonHit*)
   {
      return GenerateInitInstanceLocal((::PhotonHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PhotonHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PhotonHit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PhotonHit*)0x0)->GetClass();
      PhotonHit_TClassManip(theClass);
   return theClass;
   }

   static void PhotonHit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_G4String(void *p) {
      return  p ? new(p) ::G4String : new ::G4String;
   }
   static void *newArray_G4String(Long_t nElements, void *p) {
      return p ? new(p) ::G4String[nElements] : new ::G4String[nElements];
   }
   // Wrapper around operator delete
   static void delete_G4String(void *p) {
      delete ((::G4String*)p);
   }
   static void deleteArray_G4String(void *p) {
      delete [] ((::G4String*)p);
   }
   static void destruct_G4String(void *p) {
      typedef ::G4String current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G4String

namespace ROOT {
   // Wrappers around operator new
   static void *new_G4VHit(void *p) {
      return  p ? new(p) ::G4VHit : new ::G4VHit;
   }
   static void *newArray_G4VHit(Long_t nElements, void *p) {
      return p ? new(p) ::G4VHit[nElements] : new ::G4VHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_G4VHit(void *p) {
      delete ((::G4VHit*)p);
   }
   static void deleteArray_G4VHit(void *p) {
      delete [] ((::G4VHit*)p);
   }
   static void destruct_G4VHit(void *p) {
      typedef ::G4VHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G4VHit

namespace ROOT {
   // Wrappers around operator new
   static void *new_CLHEPcLcLHep3Vector(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CLHEP::Hep3Vector : new ::CLHEP::Hep3Vector;
   }
   static void *newArray_CLHEPcLcLHep3Vector(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CLHEP::Hep3Vector[nElements] : new ::CLHEP::Hep3Vector[nElements];
   }
   // Wrapper around operator delete
   static void delete_CLHEPcLcLHep3Vector(void *p) {
      delete ((::CLHEP::Hep3Vector*)p);
   }
   static void deleteArray_CLHEPcLcLHep3Vector(void *p) {
      delete [] ((::CLHEP::Hep3Vector*)p);
   }
   static void destruct_CLHEPcLcLHep3Vector(void *p) {
      typedef ::CLHEP::Hep3Vector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CLHEP::Hep3Vector

namespace ROOT {
   // Wrappers around operator new
   static void *new_PhotonHit(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::PhotonHit : new ::PhotonHit;
   }
   static void *newArray_PhotonHit(Long_t nElements, void *p) {
      return p ? new(p) ::PhotonHit[nElements] : new ::PhotonHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_PhotonHit(void *p) {
      delete ((::PhotonHit*)p);
   }
   static void deleteArray_PhotonHit(void *p) {
      delete [] ((::PhotonHit*)p);
   }
   static void destruct_PhotonHit(void *p) {
      typedef ::PhotonHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PhotonHit

namespace ROOT {
   static TClass *vectorlEPhotonHitmUgR_Dictionary();
   static void vectorlEPhotonHitmUgR_TClassManip(TClass*);
   static void *new_vectorlEPhotonHitmUgR(void *p = 0);
   static void *newArray_vectorlEPhotonHitmUgR(Long_t size, void *p);
   static void delete_vectorlEPhotonHitmUgR(void *p);
   static void deleteArray_vectorlEPhotonHitmUgR(void *p);
   static void destruct_vectorlEPhotonHitmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PhotonHit*>*)
   {
      vector<PhotonHit*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PhotonHit*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PhotonHit*>", -2, "vector", 216,
                  typeid(vector<PhotonHit*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPhotonHitmUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<PhotonHit*>) );
      instance.SetNew(&new_vectorlEPhotonHitmUgR);
      instance.SetNewArray(&newArray_vectorlEPhotonHitmUgR);
      instance.SetDelete(&delete_vectorlEPhotonHitmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEPhotonHitmUgR);
      instance.SetDestructor(&destruct_vectorlEPhotonHitmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PhotonHit*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<PhotonHit*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPhotonHitmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PhotonHit*>*)0x0)->GetClass();
      vectorlEPhotonHitmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPhotonHitmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPhotonHitmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PhotonHit*> : new vector<PhotonHit*>;
   }
   static void *newArray_vectorlEPhotonHitmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PhotonHit*>[nElements] : new vector<PhotonHit*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPhotonHitmUgR(void *p) {
      delete ((vector<PhotonHit*>*)p);
   }
   static void deleteArray_vectorlEPhotonHitmUgR(void *p) {
      delete [] ((vector<PhotonHit*>*)p);
   }
   static void destruct_vectorlEPhotonHitmUgR(void *p) {
      typedef vector<PhotonHit*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PhotonHit*>

namespace {
  void TriggerDictionaryInitialization_ExP01Classes_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/usersc/cb15760/persistance/secondary",
"/cvmfs/sft.cern.ch/lcg/releases/clhep/2.4.1.0-2c56f/x86_64-slc6-gcc7-opt/lib/CLHEP-2.4.1.0/../../include",
"/cvmfs/sft.cern.ch/lcg/releases/Geant4/10.04.p02-fd180/x86_64-slc6-gcc7-opt/include/Geant4",
"/cvmfs/sft.cern.ch/lcg/releases/XercesC/3.1.3-b3bf1/x86_64-slc6-gcc7-opt/include",
"/cvmfs/sft.cern.ch/lcg/releases/veccore/0.4.2-ff84f/x86_64-slc6-gcc7-opt/lib/cmake/VecCore/../../../include",
"/cvmfs/sft.cern.ch/lcg/releases/Vc/1.3.2-7fbe0/x86_64-slc6-gcc7-opt/include",
"/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.14.04-0d8dc/x86_64-slc6-gcc7-opt/include",
"/cvmfs/sft.cern.ch/lcg/releases/VecGeom/v00.05.01-18de3/x86_64-slc6-gcc7-opt/lib/cmake/VecGeom/../../../include",
"/usersc/cb15760/persistance/secondary/include",
"/cvmfs/sft.cern.ch/lcg/releases/Geant4/10.04.p02-fd180/x86_64-slc6-gcc7-opt/include/Geant4",
"/cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-slc6-gcc7-opt/include",
"/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.14.04-0d8dc/x86_64-slc6-gcc7-opt/include",
"/usersc/cb15760/persistance/secondary/build/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ExP01Classes dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$G4String.hh")))  __attribute__((annotate("$clingAutoload$PhotonHit.hh")))  G4String;
class __attribute__((annotate("$clingAutoload$PhotonHit.hh")))  PhotonHit;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$G4VHit.hh")))  __attribute__((annotate("$clingAutoload$PhotonHit.hh")))  G4VHit;
namespace CLHEP{class __attribute__((annotate("$clingAutoload$CLHEP/Vector/ThreeVector.h")))  __attribute__((annotate("$clingAutoload$PhotonHit.hh")))  Hep3Vector;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ExP01Classes dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef G4_STORE_TRAJECTORY
  #define G4_STORE_TRAJECTORY 1
#endif
#ifndef G4VERBOSE
  #define G4VERBOSE 1
#endif
#ifndef G4GEOM_USE_USOLIDS
  #define G4GEOM_USE_USOLIDS 1
#endif
#ifndef VECCORE_ENABLE_VC
  #define VECCORE_ENABLE_VC 1
#endif
#ifndef VECGEOM_VC
  #define VECGEOM_VC 1
#endif
#ifndef VECGEOM_REPLACE_USOLIDS
  #define VECGEOM_REPLACE_USOLIDS 1
#endif
#ifndef VECGEOM_QUADRILATERALS_VC
  #define VECGEOM_QUADRILATERALS_VC 1
#endif
#ifndef VECGEOM_NO_SPECIALIZATION
  #define VECGEOM_NO_SPECIALIZATION 1
#endif
#ifndef VECGEOM_ROOT
  #define VECGEOM_ROOT 1
#endif
#ifndef VECGEOM_USOLIDS
  #define VECGEOM_USOLIDS 1
#endif
#ifndef VECGEOM_INPLACE_TRANSFORMATIONS
  #define VECGEOM_INPLACE_TRANSFORMATIONS 1
#endif
#ifndef VECGEOM_USE_INDEXEDNAVSTATES
  #define VECGEOM_USE_INDEXEDNAVSTATES 1
#endif
#ifndef G4UI_USE
  #define G4UI_USE 1
#endif
#ifndef G4VIS_USE
  #define G4VIS_USE 1
#endif
#ifndef G4MULTITHREADED
  #define G4MULTITHREADED 1
#endif
#ifndef G4UI_USE_TCSH
  #define G4UI_USE_TCSH 1
#endif
#ifndef G4INTY_USE_XT
  #define G4INTY_USE_XT 1
#endif
#ifndef G4VIS_USE_RAYTRACERX
  #define G4VIS_USE_RAYTRACERX 1
#endif
#ifndef G4INTY_USE_QT
  #define G4INTY_USE_QT 1
#endif
#ifndef G4UI_USE_QT
  #define G4UI_USE_QT 1
#endif
#ifndef G4VIS_USE_OPENGLQT
  #define G4VIS_USE_OPENGLQT 1
#endif
#ifndef G4UI_USE_XM
  #define G4UI_USE_XM 1
#endif
#ifndef G4VIS_USE_OPENGLXM
  #define G4VIS_USE_OPENGLXM 1
#endif
#ifndef G4VIS_USE_OPENGLX
  #define G4VIS_USE_OPENGLX 1
#endif
#ifndef G4VIS_USE_OPENGL
  #define G4VIS_USE_OPENGL 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
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
/// \file persistency/P01/include/ExP01Classes.hh
/// \brief Declaration of the classes for generating dictionaries
//
// $Id: ExP01Classes.hh 68025 2013-03-13 13:43:46Z gcosmo $
//
#include "PhotonHit.hh"

std::vector<PhotonHit*> a;
#undef __G4String

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CLHEP::Hep3Vector", payloadCode, "@",
"G4String", payloadCode, "@",
"G4VHit", payloadCode, "@",
"PhotonHit", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExP01Classes",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExP01Classes_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExP01Classes_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExP01Classes() {
  TriggerDictionaryInitialization_ExP01Classes_Impl();
}
