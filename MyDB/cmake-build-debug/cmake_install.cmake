<<<<<<< HEAD:hello/build/cmake_install.cmake
# Install script for directory: /home/narada/Codes/hello
=======
# Install script for directory: /Users/prowontheus/Codes/MyDB
>>>>>>> eeda10b485559c91bae72d6e9bdc1c091803ce52:MyDB/cmake-build-debug/cmake_install.cmake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD:hello/build/cmake_install.cmake
file(WRITE "/home/narada/Codes/hello/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/Users/prowontheus/Codes/MyDB/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> eeda10b485559c91bae72d6e9bdc1c091803ce52:MyDB/cmake-build-debug/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
