cmake_minimum_required(VERSION 3.10)
find_package(OpenMP)

#project(atomic)
add_executable(main src/main.c)

target_link_libraries(main PUBLIC OpenMP::OpenMP_CXX)
