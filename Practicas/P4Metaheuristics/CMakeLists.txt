CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(Metaheuristica)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
add_executable(p1.out src/main.cpp src/MQKPEvaluator.cpp src/MQKPInstance.cpp src/MQKPSolGenerator.cpp src/MQKPSolution.cpp src/MQKPObjectAssignmentOperation.cpp src/Timer.cpp src/seeds.cpp)
