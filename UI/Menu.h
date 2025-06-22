#pragma once
#include <iostream>

/**
 * @author Błażej Styrnol
 * @class Menu
 * @brief Klasa pomocnicza do wyświetlania menu tekstowych w aplikacji.
 */
class Menu {
public:
    /**
     * @brief Wyświetla główne menu aplikacji.
     */
    static void wyswietlMenu();

    /**
     * @brief Wyświetla menu wyboru typu sygnału.
     */
    static void wyswietlMenuSygnalow();

    /**
     * @brief Wyświetla menu konfiguracji regulatora PID.
     */
    static void wyswietlMenuPID();

    /**
     * @brief Wyświetla menu konfiguracji modelu ARX.
     */
    static void wyswietlMenuARX();

    /**
     * @brief Wyświetla menu konfiguracji pętli symulacji.
     */
    static void wyswietlMenuPetli();
};

