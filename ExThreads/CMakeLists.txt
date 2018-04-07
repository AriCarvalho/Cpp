cmake_minimum_required(VERSION 2.8)

project(ExThreads)
find_package (Threads)
set_source_files_properties(main.cpp LANGUAGE CXX)
add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
