cmake_minimum_required(VERSION 3.5)
project(demo)

set(DYLD_LIBRARY_PATH /usr/local/include)
set(CMAKE_CXX_STANDARD 11)

find_package(CUDA REQUIRED)


#SET(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -lcuda -lcublas")
#SET (CUDA_VERBOSE_BUILD ON CACHE BOOL "nvcc verbose" FORCE)


set(SOURCE_FILES main.cu layer.cu)

cuda_add_executable(out ${SOURCE_FILES})
target_link_libraries(out cuda cublas)

