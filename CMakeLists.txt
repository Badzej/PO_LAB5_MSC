cmake_minimum_required(VERSION 3.30)
project(PO_LAB5_MSC)

set(CMAKE_CXX_STANDARD 26)

set(SOURCES
        main.cpp
        ModelARX.cpp
        RegulatorPID.cpp
        Sygnaly/SygnalStaly.cpp
        Sygnaly/SygnalSinusoidalny.cpp
        Sygnaly/SygnalProstokatny.cpp
        Sygnaly/SygnalTrojkatny.cpp
        Sygnaly/SygnalSzumBialy.cpp
        Sygnaly/SygnalKomponent.cpp
        Sygnaly/SumaSygnalow.cpp
        Sygnaly/SygnalZNasyceniem.cpp
        Sygnaly/SygnalFabryka.cpp
        Sygnaly/SygnalIO.cpp
        Dekoratory/DekoratorSISOSzeregowy.cpp
        Dekoratory/DekoratorSISORownolegly.cpp
        FabrykaObiektowSISO.cpp
        UI/InterfejsUzytkownika.h
        Konfiguracja/MenadzerKonfiguracji.cpp
        Konfiguracja/MenadzerKonfiguracji.h
        UI/InterfejsUzytkownika.cpp
        UI/Menu.cpp
        UI/Menu.h
        UI/ObslugaWejscia.cpp
        UI/ObslugaWejscia.h
        UI/KreatorObiektuSISO.cpp
        UI/KreatorObiektuSISO.h
        Testy/test_zapis_odczyt.cpp
        Testy/test_zapis_odczyt.h
)

add_executable(PO_LAB5_MSC ${SOURCES})

target_include_directories (PO_LAB5_MSC PUBLIC include_ext_lib)
target_include_directories (PO_LAB5_MSC PUBLIC cmake-build-debug)
target_include_directories (PO_LAB5_MSC PUBLIC Sygnaly)
target_include_directories (PO_LAB5_MSC PUBLIC Dekoratory)