cmake_minimum_required(VERSION 3.19)
project(leetcode_competition)

set(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES("headers")

function(add_single_exe src_dir)
    file(GLOB_RECURSE FILE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/${src_dir}/*.cpp")
    foreach(v ${FILE_LIST})
        string(REGEX MATCH "${src_dir}/.*\\.cpp" relative_path ${v})
        string(REGEX REPLACE "${src_dir}/" "" file_name ${relative_path})
        string(REGEX REPLACE ".cpp" "" target_name ${file_name})
        add_executable(${target_name} ${v})
    endforeach()
endfunction()

add_single_exe(daily)
add_single_exe(backtrace)
add_single_exe(linkedlist)

add_single_exe(two_pointers)

add_executable(
        main main.cpp
)

# daily
#foreach(v ${DAILY})
#    # file relative path
#    string(REGEX MATCH "daily/.*" relative_path ${v})
#
#    # get file name without path
#    string(REGEX REPLACE "daily/" "" target_name ${relative_path})
#    # remove .cpp string
#    string(REGEX REPLACE ".cpp" "" target_name ${target_name})
#
##    message(STATUS ${target_name})
#    # add executable
#    add_executable(${target_name} ${v})
#
#endforeach()

#add_executable(leetcode_competition main.cpp headers/common.h headers/TreeNode.h)
#add_executable(nthUglyNumber daily/nthUglyNumber.cpp)
#add_executable(largestNumber daily/largestNumber.cpp)
#add_executable(numDecodings daily/numDecodings.cpp)
#add_executable(maxSumSubmatrix daily/maxSumSubmatrix.cpp)
#add_executable(decode daily/decode.cpp)

# backtrace
#add_executable(letterCombinations backtrace/letterCombinations.cpp)
#add_executable(isValidSudoku backtrace/isValidSudoku.cpp)
#add_executable(combinationSum backtrace/combinationSum.cpp)
