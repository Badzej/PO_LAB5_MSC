#pragma once
#include <iostream>
#include <limits>

/**
 * @author Błażej Styrnol
 * @class ObslugaWejscia
 * @brief Klasa narzędziowa do pobierania danych od użytkownika z konsoli.
 */
class ObslugaWejscia {
public:
    /**
     * @brief Pobiera od użytkownika wybór liczby całkowitej z podanego zakresu.
     * @param min Minimalna dopuszczalna wartość.
     * @param max Maksymalna dopuszczalna wartość.
     * @return Wybrana liczba całkowita.
     */
    static int pobierzWybor(int min, int max);

    /**
     * @brief Pobiera od użytkownika liczbę zmiennoprzecinkową.
     * @param prompt Tekst wyświetlany użytkownikowi.
     * @return Wprowadzona liczba typu double.
     */
    static double pobierzLiczbe(const std::string& prompt);

    /**
     * @brief Pobiera od użytkownika liczbę całkowitą.
     * @param prompt Tekst wyświetlany użytkownikowi.
     * @return Wprowadzona liczba całkowita.
     */
    static int pobierzLiczbeCalkowita(const std::string& prompt);

    /**
     * @brief Pobiera od użytkownika nieujemną liczbę całkowitą (unsigned int).
     * @param prompt Tekst wyświetlany użytkownikowi.
     * @return Wprowadzona liczba typu unsigned int.
     */
    static int pobierzDodatniaLiczbeCalkowita(const std::string& prompt);

    /**
     * @brief Pobiera od użytkownika dodatnią liczbę zmiennoprzecinkową.
     * @param prompt Tekst wyświetlany użytkownikowi.
     * @return Wprowadzona liczba typu double większa od zera.
     */
    static double pobierzDodatniaLiczbe(const std::string& prompt);
};
