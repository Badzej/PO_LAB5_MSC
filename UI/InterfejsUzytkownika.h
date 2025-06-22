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

/**
 * @author Błażej Styrnol
 * @class InterfejsUzytkownika
 * @brief Główna klasa interfejsu tekstowego do zarządzania symulatorem
 *
 * Klasa zapewnia pełną funkcjonalność interfejsu tekstowego, umożliwiając:
 * - Konfigurację sygnałów wejściowych
 * - Budowanie pętli symulacji (szeregowych/równoległych)
 * - Przeprowadzanie symulacji
 * - Zarządzanie konfiguracją (zapis/odczyt)
 * - Wyświetlanie parametrów i wyników
 */
class InterfejsUzytkownika
{
private:
     std::unique_ptr<MenadzerKonfiguracji> konfiguracja; /// Menadżer przechowujący aktualną konfigurację

    /**
     * @brief Dodaje nowy sygnał wejściowy do konfiguracji
     */
    void dodajSygnal() const;

    /**
     * @brief Tworzy obiekt sygnału na podstawie wybranego typu
     * @param wybrany_sygnal Numer wybranego typu sygnału
     * @return Wskaźnik do utworzonego obiektu sygnału
     */
    static Sygnal * stworzSygnal(int wybrany_sygnal);

    /**
     * @brief Wyświetla parametry bieżącego sygnału wejściowego
     */
    void wyswietlParametrySygnalu() const;

    /**
     * @brief Rekurencyjnie wyświetla strukturę obiektu JSON
     * @param j Obiekt JSON do wyświetlenia
     * @param poziom Aktualny poziom zagnieżdżenia (do wcięć)
     */
    static void wyswietlJsonRekurencyjnie(const nlohmann::json& j, int poziom);

    /**
     * @brief Konfiguruje pętlę symulacji
     */
    void konfigurujPetle() const;

    /**
     * @brief Wyświetla konfigurację bieżącej pętli symulacji
     */
    void wyswietlKonfiguracjePetli() const;

    /**
     * @brief Przeprowadza symulację z bieżącą konfiguracją
     */
    void symuluj() const;

    /**
     * @brief Zapisuje bieżącą konfigurację do plików
     */
    void zapiszKonfiguracje() const;

    /**
     * @brief Wczytuje konfigurację z plików
     */
    void wczytajKonfiguracje() const;

public:
    /**
     * @brief Konstruktor interfejsu użytkownika
     */
    InterfejsUzytkownika();

    /**
     * @brief Uruchamia główną pętlę interfejsu
     */
    void uruchom() const;
};
