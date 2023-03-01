@echo off

set EXES=.\..\..\Exes
set CMAKE=.\..\..\CMake\bin\cmake.exe
set SRC=..\Src

mkdir .\build
cd .\build

%CMAKE% -DOGRE_BUILD_COMPONENT_BITES:BOOL="0" -DOGRE_BUILD_COMPONENT_BULLET:BOOL="0" -DOGRE_BUILD_RENDERSYSTEM_GL:BOOL="1" -DOGRE_INSTALL_DOCS:BOOL="0" -DOGRE_BUILD_PLUGIN_DOT_SCENE="0" -DOGRE_BUILD_SAMPLES:BOOL="0" -DOGRE_INSTALL_SAMPLES:BOOL="0" -DOGRE_BUILD_RENDERSYSTEM_GL3PLUS:BOOL="0" %SRC%

msbuild "OGRE.sln" /p:configuration=Debug
msbuild "OGRE.sln" /p:configuration=Release

cd ..

XCOPY /y /s .\build\bin\debug\Codec_STBI_d.dll %EXES%
XCOPY /y /s .\build\bin\debug\RenderSystem_GL_d.dll %EXES%
XCOPY /y /s .\build\bin\debug\OgreMain_d.dll %EXES%
XCOPY /y /s .\build\bin\debug\zlib.dll %EXES%

XCOPY /y /s .\build\bin\release\Codec_STBI.dll %EXES%
XCOPY /y /s .\build\bin\release\RenderSystem_GL.dll %EXES%
XCOPY /y /s .\build\bin\release\OgreMain.dll %EXES%

XCOPY /y /s .\build\bin\release\SDL2.dll %EXES%
