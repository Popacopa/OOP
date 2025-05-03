cmake_minimum_required(VERSION 3.31)



add_executable(main main.cpp)
project(master)
set_target_properties(main PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)