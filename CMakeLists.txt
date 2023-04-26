cmake_minimum_required(VERSION 3.20)

project(DervDesignPattern)

include_directories(include)

add_executable(SimpleMC1 src/SimpleMCMain1.cpp
                         src/Random1.cpp)