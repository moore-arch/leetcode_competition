cmake_minimum_required(VERSION 3.19)
project(leetcode_competition)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode_competition main.cpp common.h largestNumber.cpp)
add_executable(nthUglyNumber nthUglyNumber.cpp)
add_executable(largestNumber largestNumber.cpp)