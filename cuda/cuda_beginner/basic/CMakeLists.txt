cmake_minimum_required(VERSION 3.8)
project(basic)

set(CMAKE_CXX_STANDARD 11)
find_package(CUDA REQUIRED)

set(SOURCE_FILES main.cu)
cuda_add_executable(basic ${SOURCE_FILES})