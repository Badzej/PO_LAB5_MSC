#pragma once
#include <iostream>
#include <memory>
#include "Menu.h"
#include <limits>
#include "DekoratorSISORownolegly.h"
#include "DekoratorSISOSzeregowy.h"
#include "SumaSygnalow.h"
#include "SygnalProstokatny.h"
#include "SygnalSinusoidalny.h"
#include "SygnalStaly.h"
#include "SygnalSzumBialy.h"
#include "SygnalTrojkatny.h"
#include "SygnalZNasyceniem.h"
#include "..\RegulatorPID.h"
#include "..\ModelARX.h"
#include "ObslugaWejscia.h"
#include "../Konfiguracja/MenadzerKonfiguracji.h"
#include "KreatorObiektuSISO.h"

class InterfejsUzytkownika
{
private:
    std::unique_ptr<MenadzerKonfiguracji> konfiguracja;
    int status=0;

    void dodajSygnal() const;
    static Sygnal * stworzSygnal(int wybrany_sygnal);
    void wyswietlParametrySygnalu() const;
    static void wyswietlJsonRekurencyjnie(const nlohmann::json& j, int poziom);

    void konfigurujPetle();

    void wyswietlKonfiguracjePetli() const;

    void symuluj() const;

    void zapiszKonfiguracje() const;
    void wczytajKonfiguracje() const;
public:
    InterfejsUzytkownika();

    void uruchom();
};
