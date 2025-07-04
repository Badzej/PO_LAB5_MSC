#include "SygnalSinusoidalny.h"
#include <cmath>
SygnalSinusoidalny::SygnalSinusoidalny(double amp,double czest): amplituda(amp), czestotliwosc(czest){
  xn_1=amplituda*sin(czestotliwosc);
}

SygnalSinusoidalny::SygnalSinusoidalny(const nlohmann::json &j) :
amplituda(j["amplituda"].get<double>()),
czestotliwosc(j["czestotliwosc"].get<double>()),
xn_1(amplituda*sin(czestotliwosc)){
}

double SygnalSinusoidalny::symuluj(){
  if (stan_symulacji > 1) {
    double wyjscie = 2*cos(czestotliwosc)*xn_1 - xn_2;
    xn_2 = xn_1;
    xn_1 = wyjscie;
    return wyjscie;
  }
  else if (stan_symulacji > 0 ) {
    stan_symulacji++;
    return xn_1;
  }
  stan_symulacji++;
  return xn_2;
}

nlohmann::json SygnalSinusoidalny::serializuj() {
  return {
              {"typ", "sinusoidalny"},
              {"amplituda", amplituda},
              {"czestotliwosc", czestotliwosc}
  };
}
