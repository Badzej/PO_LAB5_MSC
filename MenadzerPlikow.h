#pragma once
#include <memory>

#include "ObiektSISO.h"
#include "Sygnaly/Sygnal.h"

/**
 * @author Błażej Styrnol
 * @class MenadzerPlikow
 * @brief Klasa pomocnicza do operacji zapisu i odczytu sygnałów oraz obiektów SISO do/z plików.
 * Umożliwia serializację oraz deserializację danych w formacie JSON.
 */
class MenadzerPlikow {
public:
    /**
     * @brief Zapisuje sygnał do pliku.
     * @param sciezka Ścieżka do pliku.
     * @param sygnal Sygnał do zapisania.
     */
    static void zapiszSygnalDoPliku(const std::string& sciezka, const std::unique_ptr<Sygnal>& sygnal);
    /**
     * @brief Wczytuje sygnał z pliku JSON.
     * @param sciezka Ścieżka do pliku.
     * @return Unikalny wskaźnik do wczytanego sygnału.
     */
    static std::unique_ptr<Sygnal> wczytajSygnalZPliku(const std::string& sciezka);

    /**
     * @brief Zapisuje obiekt SISO do pliku JSON.
     * @param sciezka Ścieżka do pliku
     * @param obiekt_SISO Obiekt SISO do zapisania
     */
    static void zapiszObiektSISODoPliku(const std::string& sciezka, const std::shared_ptr<ObiektSISO>& obiekt_SISO);

    /**
     * @brief Wczytuje obiekt SISO z pliku JSON.
     * @param sciezka Ścieżka do pliku
     * @return Wskaźnik do wczytanego obiektu SISO
     */
    static std::shared_ptr<ObiektSISO> wczytajObiektSISOZPliku(const std::string &sciezka);
};
