cmake_minimum_required(VERSION 3.5)
project(test_yarp_thrift CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(GNUInstallDirs)
# include(CTest)
# option(BUILD_TESTING "Build tests" OFF)

# Find packages needed for this main CMakeLists.txt.
# Subfolders will find the dependencies they need.
find_package(YARP 3.0 REQUIRED)

add_subdirectory(src)
add_subdirectory(thrift)