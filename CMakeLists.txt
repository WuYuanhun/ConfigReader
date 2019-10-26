cmake_minimum_required(VERSION 3.15)
project(ConfigReader)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConfigReaderTest test.cpp src/ConfigReader.cpp src/ConfigReader.h src/FileReader.cpp src/FileReader.h)