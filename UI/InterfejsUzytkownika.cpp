    // Menu glowne
#include "InterfejsUzytkownika.h"

#include <limits>

#include "DekoratorSISORownolegly.h"
#include "DekoratorSISOSzeregowy.h"
#include "SumaSygnalow.h"
#include "SygnalProstokatny.h"
#include "SygnalSinusoidalny.h"
#include "SygnalStaly.h"
#include "SygnalSzumBialy.h"
#include "SygnalTrojkatny.h"
#include "SygnalZNasyceniem.h"
#include "..\RegulatorPID.h"
#include "..\ModelARX.h"

    void InterfejsUzytkownika::wyswietlMenu() {
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
    void InterfejsUzytkownika::wyswietlMenuSygnalow() {
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
    void InterfejsUzytkownika::wyswietlMenuPID() {
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
    void InterfejsUzytkownika::wyswietlMenuARX() {
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
    void InterfejsUzytkownika::wyswietlMenuPetli() {
        std::cout << "1. Dodaj element do petli\n";
        std::cout << "2. Wyswietl strukture petli\n";
        std::cout << "0. Wyjdz\n";

    }

    // Pobieranie wyboru z zakresu
    int InterfejsUzytkownika::pobierzWybor(int min, int max) {
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
    double InterfejsUzytkownika::pobierzLiczbe(const std::string& prompt) {
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
    int InterfejsUzytkownika::pobierzLiczbeCalkowita(const std::string& prompt) {
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

InterfejsUzytkownika::InterfejsUzytkownika() {
        konfiguracja = std::make_unique<MenadzerKonfiguracji>();
    uruchom();
}

void InterfejsUzytkownika::uruchom() {
        while (true) {
            wyswietlMenu();
            int wybor = pobierzWybor(0, 7);
            switch (wybor) {
                case 0:
                    std::cout << "Do widzenia!\n";
                    return;
                case 1:
                    // Konfiguracja sygnalu wejsciowego
                    dodajSygnal();
                    break;
                case 2:
                    // Konfiguracja petli symulacji (tu budujesz szereg/rownolegle)
                    konfigurujPetle();
                    break;
                case 3:
                    // Symulacja
                    symuluj();
                    break;
                case 4:
                    // Zapisz konfiguracje do pliku
                    zapiszKonfiguracje();
                    break;
                case 5:
                    // Wczytaj konfiguracje z pliku
                    wczytajKonfiguracje();
                    break;
                case 6:
                    // Wyswietl parametry sygnalu
                    wyswietlParametrySygnalu();
                    break;
                case 7:
                    // Wyswietl konfiguracje petli
                    wyswietlKonfiguracjePetli();
                    break;
                default:
                    std::cout << "Nieznana opcja!\n";
            }
        }
    }

void InterfejsUzytkownika::dodajSygnal() {
        wyswietlMenuSygnalow();
        int wybor = pobierzWybor(0, 7);
        if (wybor == 0) return;
        Sygnal* nowy_sygnal = stworzSygnal(wybor);
        if (nowy_sygnal) {
            konfiguracja->ustawSygnalWejsciowy(std::shared_ptr<Sygnal>(nowy_sygnal));
            std::cout << "Sygnal wejsciowy zostal ustawiony.\n";
        } else {
            std::cout << "Nie udalo sie utworzyc sygnalu.\n";
        }
    }

Sygnal* InterfejsUzytkownika::stworzSygnal(int wybrany_sygnal) {
        switch (wybrany_sygnal) {
            case 1: // SygnalSinusoidalny
                return new SygnalSinusoidalny(
                    pobierzLiczbe("Podaj amplitude: "),
                    pobierzLiczbe("Podaj czestotliwosc: ")
                );
            case 2: // SygnalProstokatny
                return new SygnalProstokatny(
                    pobierzLiczbe("Podaj amplitude: "),
                    pobierzLiczbe("Podaj czestotliwosc: "),
                    pobierzLiczbe("Podaj wypelnienie [%]: ")
                );
            case 3: // SygnalTrojkatny
                return new SygnalTrojkatny(
                    pobierzLiczbe("Podaj amplitude: "),
                    pobierzLiczbe("Podaj czestotliwosc: ")
                );
            case 4: // SygnalStaly
                return new SygnalStaly(
                    pobierzLiczbe("Podaj wartosc stala: ")
                );
            case 5: // SygnalSzumBialy
                return new SygnalSzumBialy(
                    pobierzLiczbe("Podaj poziom szumu: ")
                );
            case 6: { // Suma sygnalow
                int ile;
                do {
                    ile = pobierzLiczbeCalkowita("Ile sygnalow zsumowac? (min 2): ");
                } while (ile < 2);

                // Tworzymy pierwszy sygnal bazowy
                std::cout << "--- Sygnal 1 ---\n";
                wyswietlMenuSygnalow();
                int wybor1 = pobierzWybor(1, 7);
                std::unique_ptr<Sygnal> bazowy(stworzSygnal(wybor1));

                // Dodajemy kolejne sygnaly przez kolejne dekoratory
                for (int i = 2; i <= ile; ++i) {
                    std::cout << "--- Sygnal " << i << " ---\n";
                    wyswietlMenuSygnalow();
                    int wyborN = pobierzWybor(1, 7);
                    std::unique_ptr<Sygnal> nowy(stworzSygnal(wyborN));
                    bazowy = std::make_unique<SumaSygnalow>(std::move(bazowy), std::move(nowy));
                }
                return bazowy.release();
            }
            case 7: { // Ogranicznik amplitudy
                std::cout << "Tworzenie ogranicznika amplitudy.\n";
                wyswietlMenuSygnalow();
                int wybor = pobierzWybor(1, 7); // pozwalamy na dowolny sygnal jako bazowy
                std::unique_ptr<Sygnal> bazowy(stworzSygnal(wybor));
                double max_amp = pobierzLiczbe("Podaj maksymalna amplitude (modul): ");
                return new SygnalZNasyceniem(std::move(bazowy), max_amp);
            }
            default:
                return nullptr;
        }
    }

void InterfejsUzytkownika::wyswietlParametrySygnalu() {
        auto sygnal = konfiguracja->pobierzSygnalWejsciowy();
        if (!sygnal) {
            std::cout << "Brak ustawionego sygnalu wejsciowego.\n";
            return;
        }
        nlohmann::json j = sygnal->serializuj();
        wyswietlJsonRekurencyjnie(j, 0);
    }

void InterfejsUzytkownika::wyswietlJsonRekurencyjnie(const nlohmann::json& j, int poziom) {
        std::string indent(poziom * 2, ' ');
        if (j.is_object()) {
            for (auto it = j.begin(); it != j.end(); ++it) {
                std::cout << indent << it.key() << ": ";
                if (it.value().is_primitive()) {
                    std::cout << it.value() << "\n";
                } else {
                    std::cout << "\n";
                    wyswietlJsonRekurencyjnie(it.value(), poziom + 1);
                }
            }
        } else if (j.is_array()) {
            for (const auto& el : j) {
                wyswietlJsonRekurencyjnie(el, poziom + 1);
            }
        } else {
            std::cout << indent << j << "\n";
        }
    }

void InterfejsUzytkownika::konfigurujPetle() {
        std::cout << "Konfiguracja petli symulacji:\n";
        std::shared_ptr<ObiektSISO> nowa_petla = budujBlokSISO();
        if (nowa_petla) {
            konfiguracja->ustawSymulowanyUklad(nowa_petla);
            std::cout << "Petla symulacji zostala skonfigurowana.\n";
        } else {
            std::cout << "Nie udalo sie skonfigurowac petli.\n";
        }
    }

std::shared_ptr<ObiektSISO> InterfejsUzytkownika::budujBlokSISO() {
        std::cout << "Wybierz rodzaj bloku:\n";
        std::cout << "1. Pojedynczy obiekt (ModelARX/RegulatorPID)\n";
        std::cout << "2. Blok szeregowy\n";
        std::cout << "3. Blok rownolegly\n";
        std::cout << "0. Anuluj\n";
        int wybor = pobierzWybor(0, 3);

        if (wybor == 0) return nullptr;
        if (wybor == 1) return stworzObiektSISO();
        if (wybor == 2 || wybor == 3) return budujLancuchDekoratorow(wybor);

        return nullptr;
    }


std::shared_ptr<ObiektSISO> InterfejsUzytkownika::stworzObiektSISO() {
        std::cout << "Wybierz typ obiektu:\n";
        std::cout << "1. Regulator PID\n";
        std::cout << "2. Model ARX\n";
        int wybor = pobierzWybor(1, 2);

        if (wybor == 1) {
            // Pobierz parametry PID i utworz obiekt
            double Kp = pobierzLiczbe("Podaj Kp: ");
            double Ti = pobierzLiczbe("Podaj Ti: ");
            double Td = pobierzLiczbe("Podaj Td: ");
            return std::make_shared<RegulatorPID>(Kp, Ti, Td);
        } else if (wybor == 2) {
            // Pobierz parametry ARX i utworz obiekt
            int na = pobierzLiczbeCalkowita("Podaj rzad wielomianu A (na): ");
            int nb = pobierzLiczbeCalkowita("Podaj rzad wielomianu B (nb): ");
            unsigned int nk = static_cast<unsigned int>(pobierzLiczbeCalkowita("Podaj opoznienie transportowe (k): "));
            double sigma = pobierzLiczbe("Podaj odchylenie standardowe szumu (sigma): ");

            std::vector<double> wspA, wspB;

            std::cout << "Podaj wspolczynniki A (" << na + 1 << " wartosci, oddzielone ENTEREM):\n";
            for (int i = 0; i <= na; ++i) {
                double a = pobierzLiczbe("A[" + std::to_string(i) + "]: ");
                wspA.push_back(a);
            }

            std::cout << "Podaj wspolczynniki B (" << nb << " wartosci, oddzielone ENTEREM):\n";
            for (int i = 0; i < nb; ++i) {
                double b = pobierzLiczbe("B[" + std::to_string(i) + "]: ");
                wspB.push_back(b);
            }

            return std::make_shared<ModelARX>(wspA, wspB, nk, sigma);
        }
        return nullptr;
    }



// Typ: 2 = szeregowy, 3 = rownolegly
std::shared_ptr<ObiektSISO> InterfejsUzytkownika::budujLancuchDekoratorow(int typ) {
        int ile = pobierzLiczbeCalkowita("Ile blokow polaczyc? (min 2): ");
        if (ile < 2) ile = 2;

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

        // lańcuchowanie dekoratorow
        std::shared_ptr<ObiektSISO> aktualny = bloki[0];
        for (size_t i = 1; i < bloki.size(); ++i) {
            if (typ == 2) // szeregowy
                aktualny = std::make_shared<DekoratorSISOSzeregowy>(aktualny, bloki[i]);
            else // rownolegly
                aktualny = std::make_shared<DekoratorSISORownolegly>(aktualny, bloki[i]);
        }
        return aktualny;
    }

void InterfejsUzytkownika::wyswietlKonfiguracjePetli() {
        auto uklad = konfiguracja->pobierzSymulowanyUklad();
        if (!uklad) {
            std::cout << "Brak skonfigurowanej petli symulacji.\n";
            return;
        }
        nlohmann::json j = uklad->serializuj();
        std::cout << "Konfiguracja petli symulacji:\n";
        wyswietlJsonRekurencyjnie(j, 0);
    }

void InterfejsUzytkownika::symuluj() {
        auto sygnal = konfiguracja->pobierzSygnalWejsciowy();
        auto uklad = konfiguracja->pobierzSymulowanyUklad();

        if (!sygnal) {
            std::cout << "Brak ustawionego sygnalu wejsciowego!\n";
            return;
        }
        if (!uklad) {
            std::cout << "Brak skonfigurowanej petli symulacji!\n";
            return;
        }

        // Parametry symulacji
        int liczbaProbek = pobierzLiczbeCalkowita("Podaj liczbe probek do symulacji: ");
        double krok = pobierzLiczbe("Podaj krok czasowy [s]: ");

        double t = 0.0;

        std::cout << "\nt\twejscie\twyjscie\n";
        for (int i = 0; i < liczbaProbek; ++i) {
            double u = sygnal->symuluj();      // Generuj probke sygnalu wejsciowego
            double y = uklad->symuluj(u);      // Przepusc przez uklad
            std::cout << t << "\t" << u << "\t" << y << "\n";
            t += krok;
        }
        std::cout << "Symulacja zakończona.\n";
    }

void InterfejsUzytkownika::zapiszKonfiguracje() {
        std::string sciezka;
        std::cout << "Podaj nazwe pliku do zapisu konfiguracji: ";
        std::getline(std::cin >> std::ws, sciezka);
        konfiguracja->zapiszDoPliku(sciezka);
        std::cout << "Konfiguracja zostala zapisana do pliku " << sciezka << "\n";
    }

void InterfejsUzytkownika::wczytajKonfiguracje() {
        std::string sciezka;
        std::cout << "Podaj nazwe pliku do wczytania konfiguracji: ";
        std::getline(std::cin >> std::ws, sciezka);
        konfiguracja->wczytajZPliku(sciezka);
        std::cout << "Konfiguracja zostala wczytana z pliku " << sciezka << "\n";
    }
