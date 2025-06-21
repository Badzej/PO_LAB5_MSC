#pragma once
#include <iostream>
#include <memory>

#include "MenadzerKonfiguracji.h"
class InterfejsUzytkownika
{
private:
    std::unique_ptr<MenadzerKonfiguracji> konfiguracja;
    int status=0;

    void wyswietlMenu();
    void wyswietlMenuSygnalow();
    void wyswietlMenuPID();
    void wyswietlMenuARX();
    void wyswietlMenuPetli();

    void dodajSygnal();
    Sygnal * stworzSygnal(int wybrany_sygnal);
    void wyswietlParametrySygnalu();
    void wyswietlJsonRekurencyjnie(const nlohmann::json& j, int poziom);

    void konfigurujPetle();
    std::shared_ptr<ObiektSISO> budujBlokSISO();
    std::shared_ptr<ObiektSISO> stworzObiektSISO();
    std::shared_ptr<ObiektSISO> budujLancuchDekoratorow(int typ);
    void wyswietlKonfiguracjePetli();

    void symuluj();

    int pobierzWybor(int min, int max);
    double pobierzLiczbe(const std::string& prompt);
    int pobierzLiczbeCalkowita(const std::string& prompt);

    void zapiszKonfiguracje();
    void wczytajKonfiguracje();
public:
    InterfejsUzytkownika();

    void uruchom();
};
