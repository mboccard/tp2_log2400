cmake_minimum_required(VERSION 3.15)
project(PolyInfusion LANGUAGES CXX)

add_executable(PolyInfusion
    src/main.cpp
    src/console/Console.cpp
    src/Sujet.cpp
    src/Reserve.cpp
    src/AlerteEcran.cpp
    src/AlerteTexte.cpp
    src/NotificationDistante.cpp
    src/Chauffage.cpp
    src/Distributeur.cpp
    src/Infuseur.cpp
    src/FabriqueCompact.cpp
    src/FabriquePro.cpp
    src/Besoins.cpp
    src/The.cpp
    src/StrategieInfusion.cpp
    src/InfusionAvecRincage.cpp
    src/Machine.cpp
)
target_include_directories(PolyInfusion PRIVATE include)
target_compile_features(PolyInfusion PRIVATE cxx_std_17)
set_target_properties(PolyInfusion PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
    target_compile_options(PolyInfusion PRIVATE /W4 /utf-8)
else()
    target_compile_options(PolyInfusion PRIVATE -Wall -Wextra -Wpedantic)
endif()
