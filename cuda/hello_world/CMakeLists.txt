cmake_minimum_required(VERSION 3.8)
project(project)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES srcs/main.cpp)
add_executable(out ${SOURCE_FILES})
target_link_libraries(out ${OpenCV_LIBS})


###cuda_c++文件编译
#cmake_minimum_required(VERSION 2.8)
#project(vectorAdd)
#find_package(CUDA REQUIRED)
#set(PROJECT_SRC cuda.cu)
#cuda_add_executable(cuda ${PROJECT_SRC})
