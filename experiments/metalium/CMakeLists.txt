cmake_minimum_required(VERSION 3.22...4.2)
project(tenstorrent_metalium_experiments)

find_package(TT-Metalium REQUIRED)

add_executable(${EXAMPLE_OUT} ${EXAMPLE_SRC})

target_link_libraries(${EXAMPLE_OUT} PUBLIC TT::Metalium)
