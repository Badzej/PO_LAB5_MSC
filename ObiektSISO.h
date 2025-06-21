#pragma once
#include "include_ext_lib/json.hpp"
/**
 * @author Błażej Styrnol
 * @class ObiektSISO
 * @brief Wirtualna klasa interfejsu o jednym wejściu i jednym wyjściu (Single Input Single Output)
 */
class ObiektSISO
{
public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~ObiektSISO() = default;

    /**
     * @brief Symuluje działanie obiektu.
     * @param u Wejście.
     * @return Wyjście.
     */
    virtual double symuluj(double u) = 0;

    /**
     * @brief Zwraca ostatnie wyjście.
     * @return Ostatnia wartość wyjściowa.
     */
    virtual double pobierzOstatnieWyjscie() = 0 ;

    /**
     * @brief Serializuje obiekt do JSON.
     * @return Obiekt JSON.
     */
    virtual nlohmann::json serializuj() = 0;
};