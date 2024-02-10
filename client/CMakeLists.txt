cmake_minimum_required(VERSION 3.5)
project(GestionForme)

# include_directories(${GTEST_INCLUDE_DIRS})
# SET(CMAKE_EXE_LINKER_FLAGS  "-lgtest")

add_executable(gestion-forme main.cpp
        Formes/FormeSimple/Cercle.h
        Formes/FormeSimple/Segment.h
        Formes/FormeSimple/Triangle.h
        Formes/FormeSimple/Polygone.h
        Formes/Groupe.h
        InterfacesGraphiques/InterfaceGraphique.h
        InterfacesGraphiques/ClientTCP/ClientTCP.cpp
        Sauvegardeur/SauvegardeurTxt.h
        Sauvegardeur/SauvegardeurTxt.cpp
        Chargeur/ChargeurTxt.h
        Chargeur/Analyseur/AnalyseurTxt.h
        Chargeur/Analyseur/AnalyseurTxtCOR.h
        Chargeur/Analyseur/AnalyseurTxtSegment.h
        Chargeur/ChargeurTxt.cpp
        Chargeur/Analyseur/AnalyseurTxtCercle.h
        Chargeur/Analyseur/AnalyseurTxtPolygone.h
        Chargeur/Analyseur/AnalyseurTxtTriangle.h
        Chargeur/Analyseur/AnalyseurTxtGroupe.h
)

add_executable(tests Tests/main.cpp Tests/Geometrie/testVec2D.cpp Tests/Geometrie/testMat22.cpp Tests/Formes/FormeSimple/testSeg.cpp
        Tests/Formes/FormeSimple/testCercle.cpp
        Tests/Formes/FormeSimple/testPolygone.cpp
        Tests/Formes/FormeSimple/testTriangle.cpp
        Tests/Geometrie/testGeoPlane.cpp
)
