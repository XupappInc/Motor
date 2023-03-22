#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ImGui::imgui" for configuration "RelWithDebInfo"
set_property(TARGET ImGui::imgui APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(ImGui::imgui PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/imguird.lib"
  )

list(APPEND _cmake_import_check_targets ImGui::imgui )
list(APPEND _cmake_import_check_files_for_ImGui::imgui "${_IMPORT_PREFIX}/lib/imguird.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
