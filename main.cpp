
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Sygnaly/SumaSygnalow.h"
#include <cmath>
#include "RegulatorPID.h"
#include "ModelARX.h"
#include "Dekoratory/DekoratorSISORownolegly.h"
#include "Dekoratory/DekoratorSISOSzeregowy.h"
#include "Sygnaly/SygnalSinusoidalny.h"
#include "Sygnaly/SygnalProstokatny.h"
#include "Sygnaly/SygnalStaly.h"
#include "Sygnaly/SygnalSzumBialy.h"
#include "Sygnaly/SygnalTrojkatny.h"
#include "Sygnaly/SygnalZNasyceniem.h"
#include "Sygnaly/SygnalIO.h"
#include "MenadzerPlikow.h"
#include "UI/InterfejsUzytkownika.h"


int main() {
	// double f = 1.0;               // 1 Hz
	// double fs = 100.0;            // 100 próbek/sek
	// double omega = M_PI * f / fs;  //radiany na próbkę
	// std::unique_ptr<Sygnal>  wejscie =  std::make_unique<SygnalSinusoidalny>(1.0,omega);
	// std::shared_ptr<ObiektSISO> regulator= std::make_shared<RegulatorPID>(1.0, 0.5, 0.1);
	// std::shared_ptr<ObiektSISO> model= std::make_shared<ModelARX>(
	// 	std::vector<double>{ -0.4,1.0,1.2,8.1 },
	// 	std::vector<double>{ 0.6 },
	// 	1,
	// 	0
	// );
	// std::shared_ptr<ObiektSISO> model2 = std::make_shared<ModelARX>(		std::vector<double>{ -0.4,1.0,1.2,8.1 },
	// 	std::vector<double>{ 0.6 },
	// 	1,
	// 	0);
	//
	// auto szeregowy = std::make_shared<DekoratorSISOSzeregowy>(regulator, model);
	// auto rownolegly = std::make_shared<DekoratorSISORownolegly>(szeregowy, model2);
	//
	// MenadzerPlikow::zapiszObiektSISODoPliku("plik.json",rownolegly);
	// auto sygnal_zdeserializowany = MenadzerPlikow::wczytajObiektSISOZPliku("plik.json");
	//
	// for (int i = 0; i < 10; i++) {
	// 	double u=wejscie->symuluj();
	// 	double wyjscie = rownolegly->symuluj(u);
	// 	std::cout << "Krok " << i << " -> Wyjscie: " << wyjscie << std::endl;
	// 	double wyjscie_kopii = sygnal_zdeserializowany->symuluj(u);
	// 	std::cout << "Krok " << i << " -> Wyjscie deserializowane: " << wyjscie_kopii << std::endl;
	// }
	std::unique_ptr<InterfejsUzytkownika> ui = std::make_unique<InterfejsUzytkownika>();
}
