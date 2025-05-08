project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(test test.cpp)
add_subdirectory(list)
target_link_libraries(test PUBLIC list)
