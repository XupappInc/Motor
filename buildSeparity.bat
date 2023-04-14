@echo off

cls

msbuild "Separity.sln" /p:Configuration=Debug /p:Platform=x64
msbuild "Separity.sln" /p:Configuration=Release /p:Platform=x64
