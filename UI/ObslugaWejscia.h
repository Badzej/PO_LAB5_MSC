#pragma once
#include <iostream>
#include <limits>

class ObslugaWejscia {
public:
    static int pobierzWybor(int min, int max);
    static double pobierzLiczbe(const std::string& prompt);
    static int pobierzLiczbeCalkowita(const std::string& prompt);
};
