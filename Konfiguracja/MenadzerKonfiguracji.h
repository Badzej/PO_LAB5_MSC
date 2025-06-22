#pragma once

#include <memory>
#include <../include_ext_lib/json.hpp>

#include "../Sygnaly/Sygnal.h"
#include "../ObiektSISO.h"
/**
 * @author Błażej Styrnol
 * @class MenadzerKonfiguracji
 * @brief Klasa zarządzająca bieżącą konfiguracją sygnału wejściowego i układu symulowanego.
 */
class MenadzerKonfiguracji {
private:
    std::shared_ptr<Sygnal> sygnal_wejsciowy;   /// Wskaźnik do sygnału wejściowego
    std::shared_ptr<ObiektSISO> symulowany_uklad;   /// Wskaźnik do układu symulowanego

public:
    /**
     * @brief Domyślny konstruktor klasy MenadzerKonfiguracji.
     */
    MenadzerKonfiguracji() = default;

    /**
     * @brief Ustawia sygnał wejściowy.
     * @param sygnal Wskaźnik do sygnału wejściowego.
     */
    void ustawSygnalWejsciowy(const std::shared_ptr<Sygnal>& sygnal);

    /**
     * @brief Ustawia układ symulowany.
     * @param uklad Wskaźnik do obiektu SISO będącego układem.
     */
    void ustawSymulowanyUklad(const std::shared_ptr<ObiektSISO>& uklad);

    /**
     * @brief Zwraca wskaźnik do bieżącego sygnału wejściowego.
     * @return Wskaźnik do sygnału wejściowego.
     */
    [[nodiscard]] std::shared_ptr<Sygnal> pobierzSygnalWejsciowy() const;

    /**
     * @brief Zwraca wskaźnik do bieżącego układu symulowanego.
     * @return Wskaźnik do obiektu SISO będącego układem.
     */
    [[nodiscard]] std::shared_ptr<ObiektSISO> pobierzSymulowanyUklad() const;

    /**
     * @brief Serializuje całą konfigurację do obiektu JSON.
     * @return Obiekt JSON zawierający konfigurację sygnału i układu.
     */
    [[nodiscard]] nlohmann::json serializuj() const ;

    /**
     * @brief Deserializuje konfigurację z obiektu JSON.
     * @param j Obiekt JSON z danymi konfiguracji.
     */
    void deserializuj(const nlohmann::json& j) ;

    /**
     * @brief Zapisuje bieżącą konfigurację do pliku.
     * @param sciezka Ścieżka do pliku docelowego.
     */
    void zapiszDoPliku(const std::string& sciezka) const;

    /**
     * @brief Wczytuje konfigurację z pliku.
     * @param sciezka Ścieżka do pliku źródłowego.
     */
    void wczytajZPliku(const std::string& sciezka);
};
