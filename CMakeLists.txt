cmake_minimum_required(VERSION 3.19)
project(leetcode_competition)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(".")

add_executable(leetcode_competition main.cpp headers/common.h daily/largestNumber.cpp)
add_executable(nthUglyNumber daily/nthUglyNumber.cpp)
add_executable(largestNumber daily/largestNumber.cpp)

# backtrace
add_executable(letterCombinations backtrace/letterCombinations.cpp)