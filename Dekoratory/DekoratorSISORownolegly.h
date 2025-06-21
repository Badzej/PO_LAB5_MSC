#pragma once
#include "..\ObiektSISO.h"
#include <memory>

#include "..\include_ext_lib\json.hpp"
/**
 * @author Błażej Styrnol
 * @class DekoratorSISORownolegly
 * @brief Klasa dekoratora łączącego dwa obiekty SISO równolegle.
 * Symulacja odbywa się poprzez sumowanie wyjść obu obiektów.
 */
class DekoratorSISORownolegly : public ObiektSISO {
    std::shared_ptr<ObiektSISO> pierwszy; /// Pierwszy obiekt SISO
    std::shared_ptr<ObiektSISO> drugi; /// Drugi obiekt SISO

public:
    /**
     * @brief Konstruktor równoległego dekoratora SISO.
     * @param pierwszy_ Pierwszy obiekt SISO
     * @param drugi_ Drugi obiekt SISO
     */
    DekoratorSISORownolegly(std::shared_ptr<ObiektSISO> pierwszy_, std::shared_ptr<ObiektSISO> drugi_);

    /**
     * @brief Konstruktor z obiektu JSON.
     * @param json Dane konfiguracyjne w formacie JSON
     */
    explicit DekoratorSISORownolegly(nlohmann::json json);

    /**
     * @brief Symuluje działanie równoległych obiektów SISO.
     * @param u Wartość wejściowa
     * @return Suma wyjść obu obiektów
     */
    double symuluj(double u) override;

    /**
     * @brief Zwraca ostatnie wyjście (sumę wyjść obiektów).
     * @return Ostatnia wartość wyjściowa
     */
    double pobierzOstatnieWyjscie() override;

    /**
     * @brief Serializuje obiekt do formatu JSON.
     * @return Obiekt JSON zawierający konfigurację
     */
    nlohmann::json serializuj() override;
};
