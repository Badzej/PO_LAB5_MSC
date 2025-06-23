    // Menu glowne
#include "InterfejsUzytkownika.h"




    InterfejsUzytkownika::InterfejsUzytkownika() {
        konfiguracja = std::make_unique<MenadzerKonfiguracji>();
    uruchom();
}

void InterfejsUzytkownika::uruchom() const{
        while (true) {
            Menu::wyswietlMenu();
            int wybor = ObslugaWejscia::pobierzWybor(0, 7);
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

void InterfejsUzytkownika::dodajSygnal() const{
        Menu::wyswietlMenuSygnalow();
        int wybor = ObslugaWejscia::pobierzWybor(0, 7);
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
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj amplitude: "),
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj czestotliwosc: ")*M_PI/100.0 //100 probek na s
                );
            case 2: // SygnalProstokatny
                return new SygnalProstokatny(
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj amplitude: "),
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj czestotliwosc: ")*M_PI/100.0, //100 probek na s
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj wypelnienie [%]: ")/100.0
                );
            case 3: // SygnalTrojkatny
                return new SygnalTrojkatny(
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj amplitude: "),
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj czestotliwosc: ")*M_PI/100.0 //100 probek na s
                );
            case 4: // SygnalStaly
                return new SygnalStaly(
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj wartosc stala: ")
                );
            case 5: // SygnalSzumBialy
                return new SygnalSzumBialy(
                    ObslugaWejscia::pobierzDodatniaLiczbe("Podaj poziom szumu: ")
                );
            case 6: { // Suma sygnalow
                int ile;
                do {
                    ile = ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Ile sygnalow zsumowac? (min 2): ");
                } while (ile < 2);

                // Tworzymy pierwszy sygnal bazowy
                std::cout << "--- Sygnal 1 ---\n";
                Menu::wyswietlMenuSygnalow();
                int wybor1 = ObslugaWejscia::pobierzWybor(1, 7);
                std::unique_ptr<Sygnal> bazowy(stworzSygnal(wybor1));

                // Dodajemy kolejne sygnaly przez kolejne dekoratory
                for (int i = 2; i <= ile; ++i) {
                    std::cout << "--- Sygnal " << i << " ---\n";
                    Menu::wyswietlMenuSygnalow();
                    int wyborN = ObslugaWejscia::pobierzWybor(1, 7);
                    std::unique_ptr<Sygnal> nowy(stworzSygnal(wyborN));
                    bazowy = std::make_unique<SumaSygnalow>(std::move(bazowy), std::move(nowy));
                }
                return bazowy.release();
            }
            case 7: { // Ogranicznik amplitudy
                std::cout << "Tworzenie ogranicznika amplitudy.\n";
                Menu::wyswietlMenuSygnalow();
                int wybor = ObslugaWejscia::pobierzWybor(1, 7); // pozwalamy na dowolny sygnal jako bazowy
                std::unique_ptr<Sygnal> bazowy(stworzSygnal(wybor));
                double max_amp = ObslugaWejscia::pobierzDodatniaLiczbe("Podaj maksymalna amplitude (modul): ");
                return new SygnalZNasyceniem(std::move(bazowy), max_amp);
            }
            default:
                return nullptr;
        }
    }

void InterfejsUzytkownika::wyswietlParametrySygnalu() const{
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

void InterfejsUzytkownika::konfigurujPetle() const{
        std::cout << "Konfiguracja petli symulacji:\n";
        std::shared_ptr<ObiektSISO> nowa_petla = KreatorObiektuSISO::budujBlokSISO();
        if (nowa_petla) {
            konfiguracja->ustawSymulowanyUklad(nowa_petla);
            std::cout << "Petla symulacji zostala skonfigurowana.\n";
        } else {
            std::cout << "Nie udalo sie skonfigurowac petli.\n";
        }
    }



void InterfejsUzytkownika::wyswietlKonfiguracjePetli() const{
        auto uklad = konfiguracja->pobierzSymulowanyUklad();
        if (!uklad) {
            std::cout << "Brak skonfigurowanej petli symulacji.\n";
            return;
        }
        nlohmann::json j = uklad->serializuj();
        std::cout << "Konfiguracja petli symulacji:\n";
        wyswietlJsonRekurencyjnie(j, 0);
    }

void InterfejsUzytkownika::symuluj() const{
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
        int liczbaProbek = ObslugaWejscia::pobierzDodatniaLiczbeCalkowita("Podaj liczbe probek do symulacji: ");

        std::cout << "\nprobka   |   wejscie   |   wyjscie\n";
        for (int i = 0; i < liczbaProbek; ++i) {
            double u = sygnal->symuluj();      // Generuj probke sygnalu wejsciowego
            double y = uklad->symuluj(u);      // Przepusc przez uklad
            std::cout << i << "   |   " << u << "   |   " << y << "\n";
        }
        std::cout << "Symulacja zakonczona.\n";
    }
void InterfejsUzytkownika::zapiszKonfiguracje() const{
        std::string sciezka;
        std::cout << "Podaj nazwe pliku do zapisu konfiguracji: ";
        std::getline(std::cin >> std::ws, sciezka);
        konfiguracja->zapiszDoPliku(sciezka);
        std::cout << "Konfiguracja zostala zapisana do pliku " << sciezka << "\n";
    }

void InterfejsUzytkownika::wczytajKonfiguracje() const{
        std::string sciezka;
        std::cout << "Podaj nazwe pliku do wczytania konfiguracji: ";
        std::getline(std::cin >> std::ws, sciezka);
        konfiguracja->wczytajZPliku(sciezka);
        std::cout << "Konfiguracja zostala wczytana z pliku " << sciezka << "\n";
    }
