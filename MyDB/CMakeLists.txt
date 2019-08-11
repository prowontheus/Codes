cmake_minimum_required(VERSION 3.13)
project(MyDB)

#set(CMAKE_CXX_STANDARD 11)

#set(BUILD_DIR .)  #设置编译目录,也就是Makefile文件所在目录
#message(${BUILD_DIR}) #打印目录路径
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_custom_target(MyDB COMMAND make) #最关键的就是这句, 设置外部编译文件而不是使用CMakeLists.txt


#include_directories(.)
#include_directories(cmake-build-debug)
#include_directories(include)
#include_directories(libs)
#include_directories(src)
#
#
#add_executable(MyDB
#        include/MyDB.h
#        libs/libMyDB.so
#        src/MyDB.cpp
#        src/MyDB.h
#        src/test.cpp
#        makefile)
