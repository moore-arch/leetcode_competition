cmake_minimum_required(VERSION 3.19)
project(leetcode_competition)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES("headers")

add_executable(leetcode_competition main.cpp headers/common.h)
add_executable(nthUglyNumber daily/nthUglyNumber.cpp)
add_executable(largestNumber daily/largestNumber.cpp)
add_executable(numDecodings daily/numDecodings.cpp)

# backtrace
add_executable(letterCombinations backtrace/letterCombinations.cpp)
add_executable(isValidSudoku backtrace/isValidSudoku.cpp)
add_executable(combinationSum backtrace/combinationSum.cpp)
