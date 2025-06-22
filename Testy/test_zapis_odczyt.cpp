#include "test_zapis_odczyt.h"

void testZapisOdczytSygnalu() {
    MenadzerKonfiguracji menadzer;
    auto sygnal = std::make_shared<SygnalSinusoidalny>(1.0, 2.0);
    menadzer.ustawSygnalWejsciowy(sygnal);
    menadzer.zapiszDoPliku("test_sygnal.json");

    MenadzerKonfiguracji menadzer2;
    menadzer2.wczytajZPliku("test_sygnal.json");
    auto sygnal2 = menadzer2.pobierzSygnalWejsciowy();
    assert(sygnal2 != nullptr);
    assert(sygnal2->serializuj() == sygnal->serializuj());
    std::cout << "testZapisOdczytSygnalu passed\n";
}

void testZapisOdczytUkladu() {
    MenadzerKonfiguracji menadzer;
    std::vector<double> A = {1.0, 2.0};
    std::vector<double> B = {3.0};
    auto uklad = std::make_shared<ModelARX>(A, B, 1, 0.0);
    menadzer.ustawSymulowanyUklad(uklad);
    menadzer.zapiszDoPliku("test_uklad.json");

    MenadzerKonfiguracji menadzer2;
    menadzer2.wczytajZPliku("test_uklad.json");
    auto uklad2 = menadzer2.pobierzSymulowanyUklad();
    assert(uklad2 != nullptr);
    assert(uklad2->serializuj() == uklad->serializuj());
    std::cout << "testZapisOdczytUkladu passed\n";
}

void testZapisOdczytPelnejKonfiguracji() {
    MenadzerKonfiguracji menadzer;
    auto sygnal = std::make_shared<SygnalSinusoidalny>(1.0, 2.0);
    menadzer.ustawSygnalWejsciowy(sygnal);
    std::vector<double> A = {1.0, 2.0};
    std::vector<double> B = {3.0};
    auto uklad = std::make_shared<ModelARX>(A, B, 1, 0.0);
    menadzer.ustawSymulowanyUklad(uklad);
    menadzer.zapiszDoPliku("test_pelna.json");

    MenadzerKonfiguracji menadzer2;
    menadzer2.wczytajZPliku("test_pelna.json");
    auto sygnal2 = menadzer2.pobierzSygnalWejsciowy();
    auto uklad2 = menadzer2.pobierzSymulowanyUklad();
    assert(sygnal2 != nullptr);
    assert(uklad2 != nullptr);
    assert(sygnal2->serializuj() == sygnal->serializuj());
    assert(uklad2->serializuj() == uklad->serializuj());
    std::cout << "testZapisOdczytPelnejKonfiguracji passed\n";
}

void uruchomWszystkieTesty() {
    testZapisOdczytSygnalu();
    testZapisOdczytUkladu();
    testZapisOdczytPelnejKonfiguracji();
}
