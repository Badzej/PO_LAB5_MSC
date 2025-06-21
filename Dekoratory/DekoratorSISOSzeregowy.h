#pragma once
#include "..\ObiektSISO.h"
#include <memory>
#include "..\include_ext_lib\json.hpp"

/**
 * @author Błażej Styrnol
 * @class DekoratorSISOSzeregowy
 * @brief Klasa dekoratora łączącego dwa obiekty SISO szeregowo.
 * Wyjście pierwszego obiektu jest wejściem dla drugiego.
 */
class DekoratorSISOSzeregowy : public ObiektSISO {
    std::shared_ptr<ObiektSISO> pierwszy;  /// Pierwszy obiekt SISO
    std::shared_ptr<ObiektSISO> drugi;  /// Drugi obiekt SISO

public:
    /**
     * @brief Konstruktor szeregowego dekoratora SISO.
     * @param pierwszy_ Pierwszy obiekt SISO
     * @param drugi_ Drugi obiekt SISO
     */
    DekoratorSISOSzeregowy(std::shared_ptr<ObiektSISO> pierwszy_, std::shared_ptr<ObiektSISO> drugi_);

    /**
     * @brief Konstruktor z obiektu JSON.
     * @param json Dane konfiguracyjne w formacie JSON
     */
    explicit DekoratorSISOSzeregowy(nlohmann::json json);

    /**
     * @brief Symuluje działanie szeregowo połączonych obiektów SISO.
     * @param u Wartość wejściowa
     * @return Wynik działania drugiego obiektu SISO
     */
    double symuluj(double u) override;

    /**
     * @brief Zwraca ostatnie wyjście drugiego obiektu.
     * @return Ostatnia wartość wyjściowa
     */
    double pobierzOstatnieWyjscie() override ;

    /**
     * @brief Serializuje obiekt do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację
     */
    nlohmann::json serializuj() override;
};