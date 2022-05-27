#include "Praca.h"
#include "UI_messages.h"

// Get member data functions

enum class messageFlag {};

	void Praca::addIdPracy(int ID = 0, bool creatingNew = false) {
		if (!creatingNew) Praca::idPraca = ID;
		else Praca::idPraca = ID + 1;
	}

	void Praca::addTypPracy(std::string externaValue = "") {

		//typPracyMessage(Praca::messageFlag::initial);
		//typPracyMessage(Praca::messageFlag::allowedValues);

		if (externaValue != "") {
			Praca::typPracy = externaValue;
		}

		else {

			std::cout << "Dodaj typ pracy" << std::endl;

			std::string temp = "";

			while (!Praca::validateType(temp, dozwoloneTypy)) {

				std::cin >> temp;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				boost::algorithm::to_lower(temp);

				if (!Praca::validateType(temp, dozwoloneTypy)) {

					//typPracyMessage(Praca::messageFlag::error);
					//typPracyMessage(Praca::messageFlag::allowedValues);

					Praca::clearCin();

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

				std::cout << "Dodaj tytul pracy" << std::endl;

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Tytul pracy nie moze byc pusty!" << std::endl;
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

				std::cout << "Dodaj nazwisko autora " << std::endl;

				std::cin >> temp;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

				std::cout << "Dodaj imiona autora oddzielone przecinkami" << std::endl;

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
				std::cout << imiona[i] << " " << imiona[i].substr(0, 1) << std::endl;
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

				std::cout << "Dodaj rok" << std::endl;

				std::cin >> temp;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (!Praca::validateYear(temp)) {

					std::cout << "Minimalny rok to " << MINIMALNY_ROK << std::endl;
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

				std::cout << "Dodaj nazwisko promotora" << std::endl;

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Nazwisko promotora nie moze byc puste!" << std::endl;
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

				std::cout << "Dodaj imiona promotora oddzielone przecinkami" << std::endl;

				std::getline(std::cin, temp);

				if (temp == "") {

					std::cout << "Imiona promotora nie moga byc puste!" << std::endl;

					temp = "";

					Praca::clearCin();
				}


			}
			Praca::imionaPromotora = temp;
		}
	}

	void Praca::addSlowaKluczowe(std::string externaValue = "") {

		if (externaValue != "") {
			Praca::slowaKluczowe = externaValue;
		}

		else {
			std::string temp = "";

			std::cout << "Dodaj slowa kluczowe oddzielone srednikami" << std::endl;

			std::getline(std::cin, temp);

			Praca::slowaKluczowe = temp;
		}
	}

	void Praca::addStreszczenie(bool addingNew, std::string externaValue = "") {

		if (!addingNew) {
			Praca::streszczenie = externaValue;
		}

		else {

			std::string temp = "";

			std::cout << "Dodaj streszczenie" << std::endl;
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

	bool Praca::validateYear(int input) {

		if (input == 0 || input < MINIMALNY_ROK) return false;
		return true;

	}

	bool Praca::validateType(std::string input, const std::vector<std::string> dozwoloneTypy) {
		return std::find(dozwoloneTypy.begin(), dozwoloneTypy.end(), input) != dozwoloneTypy.end();
	}

	void Praca::clearCin() {
		std::cin.clear();
		std::cin.ignore();
	}

	std::string Praca::printSelected(int choice) {

		switch (choice) {
		case (0):
			return std::to_string(Praca::idPraca);
			break;
		default:
			return "NaN";
			break;
		}
	}


