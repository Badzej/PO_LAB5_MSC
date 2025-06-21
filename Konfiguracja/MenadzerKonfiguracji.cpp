#include "MenadzerKonfiguracji.h"

#include "SygnalFabryka.h"
#include "../FabrykaObiektowSISO.h"
#include <fstream>

// Settery
void MenadzerKonfiguracji::ustawSygnalWejsciowy(std::shared_ptr<Sygnal> sygnal) {
    sygnal_wejsciowy = sygnal;
}

void MenadzerKonfiguracji::ustawSymulowanyUklad(std::shared_ptr<ObiektSISO> uklad) {
    symulowany_uklad = uklad;
}

// Gettery
std::shared_ptr<Sygnal> MenadzerKonfiguracji::pobierzSygnalWejsciowy() const {
    return sygnal_wejsciowy;
}

std::shared_ptr<ObiektSISO> MenadzerKonfiguracji::pobierzSymulowanyUklad() const {
    return symulowany_uklad;
}

nlohmann::json MenadzerKonfiguracji::serializuj() const {
    nlohmann::json j;
    if (sygnal_wejsciowy)
        j["sygnal_wejsciowy"] = sygnal_wejsciowy->serializuj();
    if (symulowany_uklad)
        j["symulowany_uklad"] = symulowany_uklad->serializuj();
    return j;
}

void MenadzerKonfiguracji::deserializuj(const nlohmann::json& j) {
    if (j.contains("sygnal_wejsciowy"))
        sygnal_wejsciowy = SygnalFabryka::stworz_z_json(j["sygnal_wejsciowy"]);
    if (j.contains("symulowany_uklad"))
        symulowany_uklad = FabrykaObiektowSISO::stworzZJson(j["symulowany_uklad"]);
}

void MenadzerKonfiguracji::zapiszDoPliku(const std::string& sciezka) const {
    nlohmann::json j = serializuj();
    std::ofstream plik(sciezka);
    if (plik.is_open())
        plik << j.dump(4);
}

void MenadzerKonfiguracji::wczytajZPliku(const std::string& sciezka) {
    std::ifstream plik(sciezka);
    if (plik.is_open()) {
        nlohmann::json j;
        plik >> j;
        deserializuj(j);
    }
}