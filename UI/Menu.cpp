//
// Created by Błażej on 21.06.2025.
//

#include "Menu.h"

    void Menu::wyswietlMenu() {
        std::cout << "============================\n";
        std::cout << "   Symulator petli ARX -  MAIN MENU\n";
        std::cout << "============================\n";
        std::cout << "1. Konfiguracja sygnalu wejsciowego\n";
        std::cout << "2. Konfiguracja petli symulacji\n";
        std::cout << "3. Symuluj\n";
        std::cout << "4. Zapisz konfiguracje do pliku\n";
        std::cout << "5. Wczytaj konfiguracje z pliku\n";
        std::cout << "6. Wyswietl parametry sygnalu\n";
        std::cout << "7. Wyswietl konfiguracje petli\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "============================\n";
    }

    // Menu wyboru sygnalu
    void Menu::wyswietlMenuSygnalow() {
        std::cout << "Wybierz typ sygnalu:\n";
        std::cout << "1. Sinusoidalny\n";
        std::cout << "2. Prostokatny\n";
        std::cout << "3. Trojkatny\n";
        std::cout << "4. Staly\n";
        std::cout << "5. Szum bialy\n";
        std::cout << "6. Suma sygnalow\n";
        std::cout << "7. Ogranicznik amplitudy\n";
        std::cout << "0. Powrot\n";
    }



    // Menu PID
    void Menu::wyswietlMenuPID() {
        int temp_Kp=0, temp_Ti=0, temp_Td=0;
        std::cout << "Aktualne parametry:\n";
        std::cout << "- Wzmocnienie proporcjonalne (Kp): "<<temp_Kp<<" \n";
        std::cout << "- Czas calkowania (Ti): "<<temp_Ti<<" \n";
        std::cout << "- Czas rozniczkowania (Td): "<<temp_Td<<" \n";
        std::cout << "1. Ustaw wzmocnienie proporcjonalne\n";
        std::cout << "2. Ustaw czas calkowania\n";
        std::cout << "3. Ustaw czas rozniczkowania\n";
        std::cout << "4. Zatwierdz\n";
        std::cout << "0. Powrot\n";
    }

    // Menu ARX
    void Menu::wyswietlMenuARX() {
        std::cout << "Aktualne parametry:\n";
        std::cout << "- Wspolczynniki A: "<<" \n";
        std::cout << "- Wspolczynniki B: "<<"\n";
        std::cout << "- Opoznienie: "<<" \n";
        std::cout << "1. Ustaw wspolczynniki A: \n";
        std::cout << "2. Ustaw wspolczynniki B: \n";
        std::cout << "3. Ustaw opoznienie: \n";
        std::cout << "4. Zatwierdz\n";
        std::cout << "0. Powrot\n";
    }

    // Menu petli
    void Menu::wyswietlMenuPetli() {
        std::cout << "1. Dodaj element do petli\n";
        std::cout << "2. Wyswietl strukture petli\n";
        std::cout << "0. Wyjdz\n";

    }