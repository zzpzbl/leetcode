cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(untitled 659Split_Array_into_Consecutive_Subsequences/659.cpp 621Task_Scheduler.cpp "85Maximal_Rectangle/85(1).cpp" "85Maximal_Rectangle/85(2).cpp" 239Sliding_Window_Maximum/239.cpp)

#add_executable(untitled 321Create_Maximum_Number/321Create_Maximum_Number.cpp)
#add_executable(./第217场周赛/5614-找出最具竞争力的子序列.cpp)
#add_executable(./第217场周赛/5615-使数组互补的最少操作次数.cpp)