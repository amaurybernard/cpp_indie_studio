cmake_minimum_required(VERSION 3.10)
project(cpp_indie_studio)

include_directories(Includes Includes/FileSystem)

set(CMAKE_CXX_STANDARD 17)

set(SRCS_DIR Srcs/)
file(
        GLOB_RECURSE
        SRCS
        ${SRCS_DIR}*.cpp
        )

set(INCS_DIR Includes/)
file(
        GLOB_RECURSE
        INCS
        ${INCS_DIR}*.hpp
)

add_executable(cpp_indie_studio ${SRCS} ${INCS})
