@echo off

cls

msbuild "Separity.sln" /p:Configuration=Debug /p:Platform=x64
msbuild "Separity.sln" /p:Configuration=Release /p:Platform=x64

XCOPY /y /s lib\x64\Debug\SeparityExports_d.dll Exes
XCOPY /y /s lib\x64\Release\SeparityExports.dll Exes