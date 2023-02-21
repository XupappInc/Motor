@echo off

cls

msbuild "Separity.sln" /p:configuration=Debug
msbuild "Separity.sln" /p:configuration=Release