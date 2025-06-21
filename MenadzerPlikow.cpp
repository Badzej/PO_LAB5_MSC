#include "MenadzerPlikow.h"
#include "Sygnaly\SygnalFabryka.h"
#include <fstream>
#include "include_ext_lib/json.hpp"

#include "FabrykaObiektowSISO.h"

void MenadzerPlikow::zapiszSygnalDoPliku(const std::string& sciezka, const std::unique_ptr<Sygnal>& sygnal) {
    std::ofstream plik(sciezka);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można utworzyć pliku: " + sciezka);
    }
    nlohmann::json j = sygnal->serializuj();
    plik << j.dump(4);
    plik.close();
}

std::unique_ptr<Sygnal> MenadzerPlikow::wczytajSygnalZPliku(const std::string& sciezka) {
    std::ifstream plik(sciezka);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + sciezka);
    }
    nlohmann::json j;
    plik >> j;
    plik.close();
    return SygnalFabryka::stworz_z_json(j);
}

std::shared_ptr<ObiektSISO> MenadzerPlikow::wczytajObiektSISOZPliku(const std::string &sciezka) {
    std::ifstream plik(sciezka);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku: " + sciezka);
    }
    nlohmann::json j;
    plik >> j;
    plik.close();
    return FabrykaObiektowSISO::stworzZJson(j);
}

void MenadzerPlikow::zapiszObiektSISODoPliku(const std::string& sciezka, const std::shared_ptr<ObiektSISO>& obiekt_SISO) {
    std::ofstream plik(sciezka);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można utworzyć pliku: " + sciezka);
    }
    nlohmann::json j = obiekt_SISO->serializuj();
    plik << j.dump(4);
    plik.close();
}