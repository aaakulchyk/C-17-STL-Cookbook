cmake_minimum_required(VERSION 3.16)
project(C__17_STL_Cookbook)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__17_STL_Cookbook main.cc stl_containers/vector_access.h stl_containers/keep_vector_sorted.h stl_containers/inserting_into_map.h)