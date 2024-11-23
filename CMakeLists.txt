cmake_minimum_required(VERSION 3.5.0)
project(main VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} ) 

add_library(quickdemo src/quickdemo.cpp)

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS}
    quickdemo
)

