# Install script for directory: /usersc/cb15760/persistance/secondary

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/usersc/cb15760/persistance/secondary/build/exampleP01")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01"
         OLD_RPATH "/usersc/cb15760/persistance/secondary/build:/cvmfs/sft.cern.ch/lcg/releases/Geant4/10.04.p02-fd180/x86_64-slc6-gcc7-opt/lib64:/cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/XercesC/3.1.3-b3bf1/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.14.04-0d8dc/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/VecGeom/v00.05.01-18de3/x86_64-slc6-gcc7-opt/lib/cmake/VecGeom/../..:/cvmfs/sft.cern.ch/lcg/releases/clhep/2.4.1.0-2c56f/x86_64-slc6-gcc7-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.28-19981/x86_64-slc6-gcc62-opt/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/exampleP01")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/usersc/cb15760/persistance/secondary/build/readHits")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits"
         OLD_RPATH "/usersc/cb15760/persistance/secondary/build:/cvmfs/sft.cern.ch/lcg/releases/Geant4/10.04.p02-fd180/x86_64-slc6-gcc7-opt/lib64:/cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/XercesC/3.1.3-b3bf1/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.14.04-0d8dc/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/VecGeom/v00.05.01-18de3/x86_64-slc6-gcc7-opt/lib/cmake/VecGeom/../..:/cvmfs/sft.cern.ch/lcg/releases/clhep/2.4.1.0-2c56f/x86_64-slc6-gcc7-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.28-19981/x86_64-slc6-gcc62-opt/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/readHits")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/usersc/cb15760/persistance/secondary/build/libExP01ClassesDict.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so"
         OLD_RPATH "/cvmfs/sft.cern.ch/lcg/releases/Geant4/10.04.p02-fd180/x86_64-slc6-gcc7-opt/lib64:/cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/XercesC/3.1.3-b3bf1/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.14.04-0d8dc/x86_64-slc6-gcc7-opt/lib:/cvmfs/sft.cern.ch/lcg/releases/VecGeom/v00.05.01-18de3/x86_64-slc6-gcc7-opt/lib/cmake/VecGeom/../..:/cvmfs/sft.cern.ch/lcg/releases/clhep/2.4.1.0-2c56f/x86_64-slc6-gcc7-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/sft.cern.ch/lcg/releases/binutils/2.28-19981/x86_64-slc6-gcc62-opt/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExP01ClassesDict.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/usersc/cb15760/persistance/secondary/build/ExP01Classes_rdict.pcm")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/usersc/cb15760/persistance/secondary/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
