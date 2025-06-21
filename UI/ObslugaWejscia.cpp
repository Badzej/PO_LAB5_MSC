#include "ObslugaWejscia.h"



// Pobieranie wyboru z zakresu
int ObslugaWejscia::pobierzWybor(int min, int max) {
    int wybor;
    while (true) {
        std::cout << "Wybierz opcje (" << min << "-" << max << "): ";
        std::cin >> wybor;
        if (std::cin.fail() || wybor < min || wybor > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nieprawidlowy wybor!\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return wybor;
        }
    }
}

// Pobieranie liczby zmiennoprzecinkowej
double ObslugaWejscia::pobierzLiczbe(const std::string& prompt) {
    double liczba;
    while (true) {
        std::cout << prompt;
        std::cin >> liczba;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nieprawidlowa liczba!\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return liczba;
        }
    }
}

// Pobieranie liczby calkowitej
int ObslugaWejscia::pobierzLiczbeCalkowita(const std::string& prompt) {
    int liczba;
    while (true) {
        std::cout << prompt;
        std::cin >> liczba;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Nieprawidlowa liczba!\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return liczba;
        }
    }
}