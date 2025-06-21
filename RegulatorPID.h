#pragma once


#include "include_ext_lib/json.hpp"
#include "ObiektSISO.h"
/**
 * @author Błażej Styrnol
 * @class RegulatorPID
 * @brief Klasa implementująca regulator PID (proporcjonalny, całkujący i różniczkujący).
 * Klasa umożliwia symulację działania regulatora P, PI lub PID.
 */
class RegulatorPID : public ObiektSISO {
    double k=0;                /// Wzmocnienie części proporcjonalnej (P)
    double ti=0;               /// Czas całkowania (I)
    double td=0;               /// Czas różniczkowania (D)
    double suma_uchybow=0;     /// Suma uchybów do obliczania części całkującej
    double poprzedni_uchyb=0;  /// Poprzednia wartość uchybu do obliczania części różniczkującej

    /**
    * @brief Sprawdza, czy podana wartość jest dodatnia, zero traktowane jest jako wartość dodatnia.
    * @param wartosc_spr Wartość do sprawdzenia.
    * @return True, jeśli wartość jest większa lub równa zero, w przeciwnym razie false.
    */
    inline bool czyDodatnia(double wartosc_spr);

    /**
    * @brief Oblicza wyjście części proporcjonalnej.
    * @param e Aktualny uchyb.
    * @return Wartość sygnału proporcjonalnego.
    */
    [[nodiscard]] double obliczWyjscieP(double e) const;

    /**
    * @brief Oblicza wyjście części całkującej.
    * @param e Aktualny uchyb.
    * @return Wartość sygnału całkującego.
    */
    double obliczWyjscieI(double e);

    /**
    * @brief Oblicza wyjście części różniczkującej.
    * @param e Aktualny uchyb.
    * @return Wartość sygnału różniczkującego.
    */
    double obliczWyjscieD(double e);

public:
    /**
    * @brief Konstruktor regulatora P.
    * @param p Wzmocnienie części proporcjonalnej.
    */
    explicit RegulatorPID(double p);

    /**
    * @brief Konstruktor regulatora PI.
    * @param p Wzmocnienie części proporcjonalnej.
    * @param i Czas całkowania.
    */
    explicit RegulatorPID(double p, double i);

    /**
    * @brief Konstruktor regulatora PID.
    * @param p Wzmocnienie części proporcjonalnej.
    * @param i Czas całkowania.
    * @param d Czas różniczkowania.
    */
    explicit RegulatorPID(double p, double i, double d);

    /**
     * @brief Konstruktor regulatora PID z obiektu JSON.
     * @param json Obiekt JSON zawierający parametry regulatora.
     */
    explicit RegulatorPID(const nlohmann::json &json);

    /**
    * @brief Ustawia parametry regulatora P.
    * @param p Wzmocnienie części proporcjonalnej.
    */
    void ustawP(double p);

    /**
    * @brief Ustawia parametry regulatora PI.
    * @param p Wzmocnienie części proporcjonalnej.
    * @param i Czas całkowania.
    */
    void ustawPI(double p, double i);

    /**
    * @brief Ustawia parametry regulatora PID.
    * @param p Wzmocnienie części proporcjonalnej.
    * @param i Czas całkowania.
    * @param d Czas różniczkowania.
    */
    void ustawPID(double p, double i, double d);

    /**
    * @brief Symuluje działanie regulatora dla danego uchybu.
    * @param e Aktualny uchyb.
    * @return Wartość sygnału sterującego wygenerowanego przez regulator.
    */
    double symuluj(double e) override;

    /**
     * @brief Zwraca ostatnią wartość sygnału sterującego.
     * @return Ostatnia wyjściowa wartość regulatora.
     */
    double pobierzOstatnieWyjscie() override;

    /**
     * @brief Serializuje konfigurację regulatora PID do formatu JSON.
     * @return Obiekt JSON zawierający parametry regulatora.
     */
    nlohmann::json serializuj() override;
};