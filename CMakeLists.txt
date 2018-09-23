project("RNO Engine")
include(CTest)
cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 14)

add_executable(RNOEngine RNO_Engine/RNO_Engine.cpp)
