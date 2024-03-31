cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17) # погуглить насчет стандарта, так мне не нравится 

project(test-task VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(test-task main.cpp
                         command.cpp
                         file.cpp
                         executor.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
