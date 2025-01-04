# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/src/919e48ca6e-40bc0391a2.clean;C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/x64-windows-dbg")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_DEBUG "OFF")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "CrowCpp")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS "ON")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Users/marci/AppData/Local/vcpkg/downloads/tools/cmake-3.27.1-windows/cmake-3.27.1-windows-i386/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Crow built using CMake")
set(CPACK_GENERATOR "DEB")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/x64-windows-dbg;Crow;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/pkgs/crow_x64-windows/debug")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "Crow 0.1.1")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "Crow 0.1.1")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/x64-windows-dbg/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION "A Fast and Easy to use C++ microframework for the web.")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Users/marci/AppData/Local/vcpkg/downloads/tools/cmake-3.27.1-windows/cmake-3.27.1-windows-i386/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Crow built using CMake")
set(CPACK_PACKAGE_FILE_NAME "Crow-0.1.1-win64")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://crowcpp.org")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Crow 0.1.1")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "Crow 0.1.1")
set(CPACK_PACKAGE_NAME "Crow")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "CrowCpp")
set(CPACK_PACKAGE_VERSION "0.1.1")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "1")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Users/marci/AppData/Local/vcpkg/downloads/tools/cmake-3.27.1-windows/cmake-3.27.1-windows-i386/share/cmake-3.27/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "C:/Users/marci/AppData/Local/vcpkg/downloads/tools/cmake-3.27.1-windows/cmake-3.27.1-windows-i386/share/cmake-3.27/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Users/marci/AppData/Local/vcpkg/downloads/tools/cmake-3.27.1-windows/cmake-3.27.1-windows-i386/share/cmake-3.27/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/x64-windows-dbg/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/crow/x64-windows-dbg/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
