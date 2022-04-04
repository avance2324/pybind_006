cmake_minimum_required(VERSION 3.10.2)
project(Pet)

## store all header files in include/
include_directories(include)


set( SRC_FILES 
        src/main.cpp 
        src/Pet.cpp 
    )

## can manually add the source files using set command
# set(SOURCES src/mainapp.cpp src/student.cpp)

## however, the file(GLOB...) allows for wildcard additions
#file(GLOB SOURCES "*.cpp")

set(CMAKE_BUILD_TYPE Debug)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

