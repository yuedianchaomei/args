cmake_minimum_required(VERSION 3.10)
project(Args)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

add_library(parser src/Parser.cpp)
target_include_directories(parser PUBLIC include)
add_executable(args args.cpp)
target_link_libraries(args parser)