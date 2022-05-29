#include "Praca.h"
#include "UI_messages.h"

// Get member data functions

	void  Praca::clearCin() {
		std::cin.clear();
		std::cin.ignore();
	}

	void Praca::addIdPracy(int ID = 0, bool creatingNew = false) {
		if (!creatingNew) Praca::idPraca = ID;
		else Praca::idPraca = ID + 1;
	}
	
	void Praca::addTypPracy(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::typPracy = externaValue;
		}

		else {

			std::string temp = "";

			while (!Praca::validateType(temp, DOZWOLONE_TYPY_PRAC)) {

				std::cout << ">> Dodaj typ pracy\n";
				coutInputIndicator();

				std::cin >> temp;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				boost::algorithm::to_lower(temp);

				if (!Praca::validateType(temp, DOZWOLONE_TYPY_PRAC)) {

					std::cout << ">> Nieprawidlowy typ pracy.\n";
					std::cout << ">> Dozwolone typy pracy to:\n" << std::flush;
					printTypeList(DOZWOLONE_TYPY_PRAC);

					temp = "";

				}

			}

			Praca::typPracy = temp;
		}
	}

	void Praca::addTytul(std::string externaValue = "") {
		if (externaValue != "") {
			Praca::tytul = externaValue;
		}

		else {

			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj tytul pracy" << std::endl;
				coutInputIndicator();

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << ">> Tytul pracy nie moze byc pusty!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}


			Praca::tytul = temp;
		}
	}

	void Praca::addNazwiskoAutora(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::nazwiskoAutora = externaValue;
		}

		else {
			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj nazwisko autora " << std::endl;
				coutInputIndicator();

				std::cin >> temp;

				if (temp == "") {
					std::cout << "Nazwisko autora nie moze byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			Praca::nazwiskoAutora = temp;
		}
	}

	void Praca::addImionaAutora(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::imionaAutora = externaValue;
		}

		else {
			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj imiona autora oddzielone przecinkami" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::getline(std::cin, temp);

				if (temp == "") {
					std::cout << "Imiona autora nie moga byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			getInicjal(temp,COMA,"");

			Praca::imionaAutora = temp;
		}
	}

	void Praca::getInicjal(std::string imionaAutora, const char COMA, std::string externaValue = "") {

		if (externaValue != "") {
			Praca::inicjalyAutora = externaValue;
		}

		else {
			std::vector<std::string> imiona{};

			boost::algorithm::erase_all(imionaAutora, " ");

			std::stringstream sstream(imionaAutora);
			std::string word;
			std::string tempString;

			while (std::getline(sstream, word, COMA)) {
				imiona.push_back(word);
			}

			for (unsigned int i = 0; i < imiona.size(); i++) {
				tempString += imiona[i].substr(0, 1) + ". ";
			}

			Praca::inicjalyAutora = tempString;
		}
	}

	void Praca::addRok(int externaValue = -1) {

		if (externaValue != -1) {
			Praca::rok = externaValue;
		}

		else {
			int temp = 0;

			while (!validateYear(temp)) {

				std::cout << ">> Dodaj rok" << std::endl;
				coutInputIndicator();
				
				std::cin >> temp;

				if (!Praca::validateYear(temp)) {

					std::cout << ">> Minimalny rok to " << MINIMALNY_ROK << std::endl;
					temp = 0;

					Praca::clearCin();

				}

			}

			Praca::rok = temp;
		}
	}

	void Praca::addNazwiskoPromotora(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::nazwiskoPromotora = externaValue;
		}

		else {
			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj nazwisko promotora" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << ">> Nazwisko promotora nie moze byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			Praca::nazwiskoPromotora = temp;
		}
	}

	void Praca::addImionaPromotora(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::imionaPromotora = externaValue;
		}

		else {
			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj imie promotora" << std::endl;
				coutInputIndicator();

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << ">> Imie promotora nie moga byc puste!" << std::endl;

					temp = "";

					Praca::clearCin();
				}
			}
			Praca::imionaPromotora = temp;
		}
	}

	void Praca::addSlowaKluczowe(bool addingNew, std::string externaValue = "") {

		if (!addingNew) {
			Praca::slowaKluczowe = externaValue;
		}

		else {
			std::string temp = "";

			std::cout << ">> Dodaj slowa kluczowe oddzielone srednikami"
				<< std::endl;
			coutInputIndicator();

			std::getline(std::cin, temp);

			boost::algorithm::to_lower(temp);
			boost::algorithm::erase_all(temp, " ");

			Praca::slowaKluczowe = temp;
		}
	}

	void Praca::addStreszczenie(bool addingNew, std::string externaValue = "") {

		if (!addingNew) {
			Praca::streszczenie = externaValue;
		}

		else {

			std::string temp;
			std::cout << ">> Dodaj streszczenie" << std::endl;
			coutInputIndicator();

			std::getline(std::cin, temp);

			if (temp != "" && temp.size() > 1000) {

				std::cout << "Maksymalna ilosc znakow to 1000!" << std::endl;

				while (temp != "") {

					std::getline(std::cin, temp);

				}
			}

			Praca::streszczenie = temp;
		}
	}

// Read member data functions

	int Praca::readIdPracy() {return Praca::idPraca;}

	std::string Praca::readTypPracy() { return Praca::typPracy; }

	std::string Praca::readTytul() { return Praca::tytul; }

	std::string Praca::readNazwiskoAutora() { return Praca::nazwiskoAutora; }

	std::string Praca::readImionaAutora() { return Praca::imionaAutora; }

	std::string Praca::readInicjal() { return Praca::inicjalyAutora; }

	int Praca::readRok() { return Praca::rok; }

	std::string Praca::readNazwiskoPromotora() { return Praca::nazwiskoPromotora; }

	std::string Praca::readImionaPromotora() { return Praca::imionaPromotora; }

	std::string Praca::readSlowaKluczowe() { return Praca::slowaKluczowe; }

	std::string Praca::readStreszczenie() { return Praca::streszczenie; }

// Edit member data functions

	void Praca::editTypPracy() {

			std::string temp = "";

			while (!Praca::validateType(temp, DOZWOLONE_TYPY_PRAC)) {

				std::cout << ">> Dodaj typ pracy\n";
				coutInputIndicator();

				std::cin >> temp;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				boost::algorithm::to_lower(temp);

				if (!Praca::validateType(temp, DOZWOLONE_TYPY_PRAC)) {

					std::cout << ">> Nieprawidlowy typ pracy.\n";
					std::cout << ">> Dozwolone typy pracy to:\n" << std::flush;
					printTypeList(DOZWOLONE_TYPY_PRAC);

					temp = "";

				}

			}

			Praca::typPracy = temp;
		
	}

	void Praca::editTytul() {

			std::string temp;

			do {

				std::cout << ">> Dodaj tytul pracy" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Tytul pracy nie moze byc pusty!" << std::endl;
					temp = "";
				}
			} while (temp == "");


			Praca::tytul = temp;
		
	}

	void Praca::editNazwiskoAutora() {


			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj nazwisko autora " << std::endl;
				coutInputIndicator();
				std::cin.ignore();
				std::cin >> temp;

				if (temp == "") {
					std::cout << "Nazwisko autora nie moze byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			Praca::nazwiskoAutora = temp;
		
	}

	void Praca::editImionaAutora() {


			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj imiona autora oddzielone przecinkami" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::getline(std::cin, temp);

				if (temp == "") {
					std::cout << "Imiona autora nie moga byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			getInicjal(temp, COMA, "");

			Praca::imionaAutora = temp;
		
	}

	void Praca::editRok() {


			int temp = 0;

			while (!validateYear(temp)) {

				std::cout << ">> Dodaj rok" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::cin >> temp;

				if (!Praca::validateYear(temp)) {

					std::cout << ">> Minimalny rok to " << MINIMALNY_ROK << std::endl;
					temp = 0;

					Praca::clearCin();

				}

			}

			Praca::rok = temp;
		
	}

	void Praca::editNazwiskoPromotora() {


			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj nazwisko promotora" << std::endl;
				coutInputIndicator();

				std::cin.ignore();
				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Nazwisko promotora nie moze byc puste!" << std::endl;
					temp = "";

					Praca::clearCin();
				}

			}

			Praca::nazwiskoPromotora = temp;
		
	}

	void Praca::editImionaPromotora() {


			std::string temp = "";

			while (temp == "") {

				std::cout << ">> Dodaj imie promotora" << std::endl;
				coutInputIndicator();

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Imie promotora nie moga byc puste!" << std::endl;

					temp = "";

					Praca::clearCin();
				}


			}

			Praca::imionaPromotora = temp;

			Praca::getInicjal(Praca::imionaAutora, COMA, "");
		
	}

	void Praca::editSlowaKluczowe() {


			std::string temp = "";

			std::cout << ">> Dodaj slowa kluczowe oddzielone srednikami"<< std::endl;
			coutInputIndicator();
			std::cin.ignore();
			std::getline(std::cin, temp);

			boost::algorithm::to_lower(temp);
			temp = boost::regex_replace(temp, boost::regex("[' ']{2,}"), " ");

			Praca::slowaKluczowe = temp;
		
	}

	void Praca::editStreszczenie() {

			std::string temp;
			std::cout << ">> Dodaj streszczenie" << std::endl;
			coutInputIndicator();
			std::cin.ignore();
			std::getline(std::cin, temp);

			if (temp != "" && temp.size() > 1000) {

				std::cout << "Maksymalna ilosc znakow to 1000!" << std::endl;

				while (temp != "") {

					std::getline(std::cin, temp);

				}
			}

			Praca::streszczenie = temp;
	}



// MISC FUNCTIONS

	void Praca::printPraca(int id) {

		std::cout 
			<< "ID: " << Praca::readIdPracy() << std::endl
			<< "TP: " << Praca::readTypPracy() << std::endl
			<< "TT: " << Praca::readTytul() << std::endl
			<< "AN: " << Praca::readNazwiskoAutora() << std::endl
			<< "AI: " << Praca::readImionaAutora() << std::endl
			<< "II: " << Praca::readInicjal() << std::endl
			<< "YY: " << Praca::readRok() << std::endl
			<< "PN: " << Praca::readNazwiskoPromotora() << std::endl
			<< "PI: " << Praca::readImionaPromotora() << std::endl
			<< "SK: " << Praca::readSlowaKluczowe() << std::endl
			<< "ST: " << Praca::readStreszczenie() << std::endl;
	}

	// Sprawdza, czy podany rok pracy spelnia wymagania
	bool Praca::validateYear(int input) {
		if (input == 0 || input < MINIMALNY_ROK) return false;
		return true;
	}

	// Sprawdza, czy typ pracy jest prawidlowy
	bool Praca::validateType(std::string input, const std::vector<std::string> dozwoloneTypy) {
		return std::find(dozwoloneTypy.begin(), dozwoloneTypy.end(), input) != dozwoloneTypy.end();
	}



