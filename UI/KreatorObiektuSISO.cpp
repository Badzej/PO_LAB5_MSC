//
// Created by Błażej on 22.06.2025.
//

#include "KreatorObiektuSISO.h"

std::shared_ptr<ObiektSISO> KreatorObiektuSISO::budujBlokSISO() {
        std::cout << "Wybierz rodzaj bloku:\n";
        std::cout << "1. Pojedynczy obiekt (ModelARX/RegulatorPID)\n";
        std::cout << "2. Blok szeregowy\n";
        std::cout << "3. Blok rownolegly\n";
        std::cout << "0. Anuluj\n";
        int wybor = ObslugaWejscia::pobierzWybor(0, 3);

        if (wybor == 0) return nullptr;
        if (wybor == 1) return stworzObiektSISO();
        if (wybor == 2 || wybor == 3) return budujLancuchDekoratorow(wybor);

        return nullptr;
    }


std::shared_ptr<ObiektSISO> KreatorObiektuSISO::stworzObiektSISO() {
        std::cout << "Wybierz typ obiektu:\n";
        std::cout << "1. Regulator PID\n";
        std::cout << "2. Model ARX\n";
        int wybor = ObslugaWejscia::pobierzWybor(1, 2);

        if (wybor == 1) {
            // Pobierz parametry PID i utworz obiekt
            double Kp = ObslugaWejscia::pobierzDodatniaLiczbe("Podaj Kp: ");
            double Ti = ObslugaWejscia::pobierzDodatniaLiczbe("Podaj Ti: ");
            double Td = ObslugaWejscia::pobierzDodatniaLiczbe("Podaj Td: ");
            return std::make_shared<RegulatorPID>(Kp, Ti, Td);
        } else if (wybor == 2) {
            // Pobierz parametry ARX i utworz obiekt
            int na = ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Podaj rzad wielomianu A (na): ");
            int nb = ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Podaj rzad wielomianu B (nb): ");
            unsigned int nk = static_cast<unsigned int>(ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Podaj opoznienie transportowe (k): "));
            double sigma = ObslugaWejscia::pobierzDodatniaLiczbe("Podaj odchylenie standardowe szumu (sigma): ");

            std::vector<double> wspA, wspB;

            std::cout << "Podaj wspolczynniki A (" << na+1 << " wartosci, oddzielone ENTEREM):\n";
            for (int i = 0; i <= na; ++i) {
                double a = ObslugaWejscia::pobierzLiczbe("A[" + std::to_string(i) + "]: ");
                wspA.push_back(a);
            }

            std::cout << "Podaj wspolczynniki B (" << nb << " wartosci, oddzielone ENTEREM):\n";
            for (int i = 0; i < nb; ++i) {
                double b = ObslugaWejscia::pobierzLiczbe("B[" + std::to_string(i) + "]: ");
                wspB.push_back(b);
            }

            return std::make_shared<ModelARX>(wspA, wspB, nk, sigma);
        }
        return nullptr;
    }



// Typ: 2 = szeregowy, 3 = rownolegly
std::shared_ptr<ObiektSISO> KreatorObiektuSISO::budujLancuchDekoratorow(int typ) {
        int ile;
        do {
            ile = ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Ile blokow polaczyc? (min 2):  ");
        } while (ile < 2);
        std::vector<std::shared_ptr<ObiektSISO>> bloki;
        for (int i = 0; i < ile; ++i) {
            std::cout << "Konfiguracja bloku " << (i + 1) << ":\n";
            auto blok = budujBlokSISO(); // rekurencyjnie, moze byc pojedynczy lub kolejny dekorator
            if (blok) bloki.push_back(blok);
            else {
                std::cout << "Blok nie zostal utworzony. Przerywam konfiguracje.\n";
                return nullptr;
            }
        }

        // lancuchowanie dekoratorow
        std::shared_ptr<ObiektSISO> aktualny = bloki[0];
        for (size_t i = 1; i < bloki.size(); ++i) {
            if (typ == 2) // szeregowy
                aktualny = std::make_shared<DekoratorSISOSzeregowy>(aktualny, bloki[i]);
            else // rownolegly
                aktualny = std::make_shared<DekoratorSISORownolegly>(aktualny, bloki[i]);
        }
        return aktualny;
    }