#include "ObslugaWejscia.h"

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

int ObslugaWejscia::pobierzDodatniaLiczbeCalkowita(const std::string& prompt) {
    int liczba;
    while (true) {
        std::cout << prompt;
        std::cin >> liczba;
        if (std::cin.fail() || liczba <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Podaj nieujemną liczbę całkowitą!\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return liczba;
        }
    }
}


double ObslugaWejscia::pobierzDodatniaLiczbe(const std::string& prompt) {
    double liczba;
    while (true) {
        std::cout << prompt;
        std::cin >> liczba;
        if (std::cin.fail() || liczba <= 0.0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Podaj liczbe nieujemna!\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return liczba;
        }
    }
}
