# Install script for directory: C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/x64-windows/share/boost-build

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/pkgs/boost-exception_x64-windows")
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
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
file(GLOB LIBS "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.so.*" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.so" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.a" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.dylib" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.dylib.*" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.lib")
if(LIBS)
    file(INSTALL ${LIBS} DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
endif()
file(GLOB DLLS "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.dll" "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/stage/lib/*.pyd")
if(DLLS)
    file(INSTALL ${DLLS} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
endif()

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/marci/OneDrive/Pulpit/PO_biblioteka/vcpkg_installed/x64-windows/vcpkg/blds/boost-exception/x64-windows-rel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")