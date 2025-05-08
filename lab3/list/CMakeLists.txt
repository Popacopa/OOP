
add_library(list STATIC linkedlist.cpp) 
target_include_directories(list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
