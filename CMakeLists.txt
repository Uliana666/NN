cmake_minimum_required(VERSION 3.20)
project(NN_iLoveYou)

set(CMAKE_CXX_STANDARD 17)

add_executable(NN_iLoveYou main.cpp Network.cpp Network.h const.h AbstractActivationFunction.h Functions.cpp Functions.h)
