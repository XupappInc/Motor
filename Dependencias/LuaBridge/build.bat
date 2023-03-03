@echo off

set EXES=.\..\..\Exes
set CMAKE=.\..\..\CMake\bin\cmake.exe
set SRC=..\Src

mkdir .\build
cd .\build

%CMAKE% -DLUABRIDGE_TESTING:BOOL="0" -Dgtest_force_shared_crt:BOOL="0" -DCMAKE_CONFIGURATION_TYPES:STRING="Debug;Release;" -DLUABRIDGE_CXX17:BOOL="1" %SRC%

msbuild "LuaBridge.sln" /p:configuration=Debug
msbuild "LuaBridge.sln" /p:configuration=Release

cd ..
