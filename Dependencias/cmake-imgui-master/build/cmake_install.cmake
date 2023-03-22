# Install script for directory: C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/dist")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/Debug/imguid.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/Release/imgui.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/MinSizeRel/imguimr.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/RelWithDebInfo/imguird.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/imgui" TYPE FILE FILES
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imgui.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imconfig.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imgui_internal.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imstb_rectpack.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imstb_textedit.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/imstb_truetype.h"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/backends/imgui_impl_win32.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/misc/fonts" TYPE FILE FILES
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/Cousine-Regular.ttf"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/DroidSans.ttf"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/Karla-Regular.ttf"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/ProggyClean.ttf"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/ProggyTiny.ttf"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/src/imgui/misc/fonts/Roboto-Medium.ttf"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/Debug/imguid.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/RelWithDebInfo/imguird.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/ImGuiTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/ImGuiTargets.cmake"
         "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/ImGuiTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui/ImGuiTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/CMakeFiles/Export/1c9f1db1a0c9398944d65050189647a4/ImGuiTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/imgui" TYPE FILE FILES
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/generated/ImGuiConfigVersion.cmake"
    "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/generated/ImGuiConfig.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/laura/Documents/Cole/3/2Cuatri/P3/Motor/Dependencias/cmake-imgui-master/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
