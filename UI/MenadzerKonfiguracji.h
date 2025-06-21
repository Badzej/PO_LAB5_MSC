#pragma once

#include <memory>
#include <../include_ext_lib/json.hpp>

#include "../MenadzerPlikow.h"
#include "../Sygnaly/Sygnal.h"
#include "../ObiektSISO.h"

class MenadzerKonfiguracji {
private:
    std::shared_ptr<Sygnal> sygnal_wejsciowy;
    std::shared_ptr<ObiektSISO> symulowany_uklad;
public:
    MenadzerKonfiguracji() = default;
    void ustawSygnalWejsciowy(std::shared_ptr<Sygnal> sygnal);
    void ustawSymulowanyUklad(std::shared_ptr<ObiektSISO> uklad);
    [[nodiscard]] std::shared_ptr<Sygnal> pobierzSygnalWejsciowy() const;
    [[nodiscard]] std::shared_ptr<ObiektSISO> pobierzSymulowanyUklad() const;
    nlohmann::json serializuj() const ;
    void deserializuj(const nlohmann::json& j) ;
    void zapiszDoPliku(const std::string& sciezka) const;
    void wczytajZPliku(const std::string& sciezka);
};
