cmake_minimum_required(VERSION 3.1)
project(heat_equation VERSION 0.0.1)

include_directories(include)

set(SOURCES 
src/main.cpp
)

add_executable(heat_equation ${SOURCES})

# uncomment for more sp33dZ
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "-O3")

# Define C++14 standard
set_property(TARGET heat_equation PROPERTY CXX_STANDARD 14)

