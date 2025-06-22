#include "UI/InterfejsUzytkownika.h"
#include "Testy/test_zapis_odczyt.h"

int main() {
	uruchomWszystkieTesty();
	std::unique_ptr<InterfejsUzytkownika> ui = std::make_unique<InterfejsUzytkownika>();
}
