@echo off

set EXES=.\..\..\Exes

XCOPY /y /s .\build\dll\fmod.dll %EXES%
XCOPY /y /s .\build\dll\fmodL.dll %EXES%

XCOPY /y /s .\build\dll\fmodstudio.dll %EXES%
XCOPY /y /s .\build\dll\fmodstudioL.dll %EXES%

XCOPY /y /s .\build\dll\fsbank.dll %EXES%
XCOPY /y /s .\build\dll\flibfsbvorbis.dll %EXES%
XCOPY /y /s .\build\dll\opus.dll %EXES%