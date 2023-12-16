cmake_minimum_required(VERSION 2.6)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gestion-forme main.cpp
        Formes/Groupe.h
        Formes/FormeSimple/Cercle.h
        Formes/FormeSimple/Cercle.h)

add_executable(tests Tests/main.cpp Tests/testVec2D.cpp Tests/testMat22.cpp Tests/Formes/FormeSimple/testSeg.cpp)  
target_link_libraries(tests gtest)
