cmake_minimum_required(VERSION 3.22...4.2)
project(tenstorrent_metalium_experiments)

find_package(TT-Metalium REQUIRED)

add_executable(000-null-compute-kernel)
target_sources(000-null-compute-kernel PRIVATE 000-null-compute-kernel.cpp)

target_link_libraries(000-null-compute-kernel PUBLIC TT::Metalium)
