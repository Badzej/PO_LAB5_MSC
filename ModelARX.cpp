#include "ModelARX.h"
#include <numeric>
#include "include_ext_lib/json.hpp"
#include <fstream>

double ModelARX::generujZaklocenie() const {
    if (sigma == 0.0) return 0.0;
    std::normal_distribution<double> dist(0.0, sigma);
    static std::default_random_engine gen;
    return dist(gen);
}

double ModelARX::oblicz(const std::vector<double>& wielomian,const std::deque<double>& poprzednie_wartosci) const {
    size_t n = std::min(wielomian.size(), poprzednie_wartosci.size());
    return std::inner_product(wielomian.begin(), wielomian.begin() + n, poprzednie_wartosci.begin(), 0.0);  ///iloczyn skalarny n wspolczynnikow wielomianu i poprzednich wartosci
}

ModelARX::ModelARX(const std::vector<double>& a, const std::vector<double>& b, unsigned int opoznienie, double moc) : A(a), B(b), k(opoznienie), sigma(moc) {
  u_hist.resize(b.size() + k, 0.0);
  y_hist.resize(a.size(), 0.0);
}

ModelARX::ModelARX(const nlohmann::json& plik_json):
    A(plik_json["A"].get<std::vector<double>>()),
    B(plik_json["B"].get<std::vector<double>>()),
    k(plik_json["k"].get<unsigned int>()),
    sigma(plik_json["sigma"].get<double>()) {
        u_hist.resize(B.size() + k, 0.0);
        y_hist.resize(A.size(), 0.0);
}

double ModelARX::symuluj(double u) {
    u_hist.push_front(u);
    std::deque<double> u_opoznione(u_hist.begin() + k, u_hist.end());
    double wyjscie = ModelARX::oblicz(B,u_opoznione) - ModelARX::oblicz(A,y_hist) + generujZaklocenie();
    y_hist.push_front(wyjscie);
    return wyjscie;
}

nlohmann::json ModelARX::serializuj() {
    return {
                  {"typ", "ModelARX"},
                  {"A", A},
                  {"B", B},
                  {"k", k},
                  {"sigma", sigma}
    };
}

double ModelARX::pobierzOstatnieWyjscie() {
    return y_hist.back();
}