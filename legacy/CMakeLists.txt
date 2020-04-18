cmake_minimum_required(VERSION 3.16)
project(templates_98)
set(CMAKE_CXX_STANDARD 98)

set(SRC_DIR "./src")

include_directories(${SRC_DIR})
include_directories(${COMMON_LIB_PATH})
add_subdirectory(${COMMON_LIB_PATH} "./common" EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}_example01 ${SRC_DIR}/example01.cpp ${COMMON_SOURCES})
add_executable(${PROJECT_NAME}_example02 ${SRC_DIR}/example02.cpp ${COMMON_SOURCES})
