@echo off

cls

set BAT=build.bat

cd .\Dependencias

cd .\Ogre\
call %BAT%

cd ..\bullet3d\
call %BAT%

cd ..\FMOD\
call %BAT%

cd ..\Lua\
call %BAT%


cd..
cd..