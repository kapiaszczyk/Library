#include "Biblioteka.h"
#include "additionalFunctions.h"
#include "Praca.h"
#include "UI_messages.h"

#include <set>

bool isLibraryEmpty(Biblioteka biblioteka) {
    if ((std::filesystem::file_size("prace.txt") == 0)) return true;
    return false;
}


bool cmp(std::pair<int, Praca> a, std::pair<int, Praca> b) {
    return a.first < b.first;
    // test
}

void Biblioteka::wyswietlLiczbePrac(std::vector<std::pair<int, Praca>> listaPrac) {

    int liczbaMgr{}, liczbaLic{}, liczbaInz{};

    for (unsigned int i = 0; i < listaPrac.size(); ++i) {
        if (listaPrac[i].second.readTypPracy() == "mgr") liczbaMgr++;
        if (listaPrac[i].second.readTypPracy() == "lic") liczbaLic++;
        if (listaPrac[i].second.readTypPracy() == "inz") liczbaInz++;
    }

    std::cout << "Liczba wszystkich prac: " << listaPrac.size() << std::endl;
    std::cout << "Liczba wszystkich mgr: " << liczbaMgr << std::endl;
    std::cout << "Liczba wszystkich lic: " << liczbaLic << std::endl;
    std::cout << "Liczba wszystkich inz: " << liczbaInz << std::endl;

}


int Biblioteka::getLastId(std::vector<std::pair<int, Praca>>& listaPrac) {

    std::sort(listaPrac.begin(), listaPrac.end(), cmp);

    std::cout << listaPrac.back().first << std::endl;

    return listaPrac.back().first;

}

// Inicjalizuje menu biblioteki
void Biblioteka::menu(Biblioteka& biblioteka) {

    int choice{};
    bool subMenu = false;

    while (choice != 7) {

        menuMessage();

        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Dodawanie prac" << std::endl;
            biblioteka.dodajPrace();
            break;        
        case 2:
            std::cout << "Edycja pracy" << std::endl;
            biblioteka.edytujPrace(biblioteka.listaPrac);
            break;
        case 3:
            std::cout << "Wyswietlanie listy prac w formacie skroconym" << std::endl;
            biblioteka.wyswSkrocone(biblioteka.listaPrac);

            break;
        case 4:
            std::cout << "Wyswietlanie listy prac w formacie pelnym" << std::endl;
            biblioteka.wyswPelne(biblioteka.listaPrac);
            break;
        case 5:
            std::cout << "Wyszukiwanie pracy" << std::endl;
            biblioteka.szukaj();
            break;
        case 6:
            std::cout << "Dodatkowe funkcje" << std::endl;
            subMenu = true;
            break;
        }

        if (subMenu) {

            subMenu = false;
            int choice{};

            subMenuMessage();

            std::cin >> choice;

            switch (choice) {
            case 1:
                std::cout << "Wyswietlanie liczby wszystkich prac" << std::endl;
                Biblioteka::wyswietlLiczbePrac(listaPrac);
                break;
            case 2:
                std::cout << "Wyswietlanie liczby prac dla poszczegolnych promotorow" << std::endl;
                Biblioteka::ilePracPromotora();
                break;
            case 3:
                std::cout << "Wyswietlanie 10 slow kluczowych" << std::endl;
                break;
            default:
                std::cout << "Wybiez jedna z trzech funkcji" << std::endl;
                break;

            }
        }



    }
}

int Biblioteka::checkValue(std::string line, const std::string id[]) {

    std::string lineId = "";

    if (true) {
        for (int i = 0; i < ILE_WARTOSCI_PRACA; ++i) {
            if (line.substr(0, 2) == id[i]) return i;
            if (line == "") return -1;
        }
    }
}

// Wczytuje wszystkie prace
void Biblioteka::wczytajPrace(std::vector<std::pair<int, Praca>>& listaPrac) {

    Praca nowaPraca;

    if (std::filesystem::file_size("prace.txt") == 0) {
        errorLibraryEmpty();
    }
    else {
        std::ifstream stream("prace.txt");
        stream.seekg(0);

        std::string tempLine;

        int counter = 0;

        while (!stream.eof())
        {
            std::getline(stream, tempLine);

            switch (checkValue(tempLine, lineId)) {
            case 0:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addIdPracy(std::stoi(tempLine), false);
                counter++;
                break;
            case 1:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addTypPracy(tempLine);
                counter++;
                break;
            case 2:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addTytul(tempLine);
                counter++;
                break;
            case 3:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addNazwiskoAutora(tempLine);
                counter++;
                break;
            case 4:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addImionaAutora(tempLine);
                counter++;
                break;
            case 5:
                tempLine.erase(0, 3);
                nowaPraca.Praca::getInicjal(nowaPraca.Praca::readImionaAutora(), COMA, tempLine);
                counter++;
                break;
            case 6:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addRok(std::stoi(tempLine));
                counter++;
                break;
            case 7:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addNazwiskoPromotora(tempLine);
                counter++;
                break;
            case 8:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addImionaPromotora(tempLine);
                counter++;
                break;
            case 9:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addSlowaKluczowe(tempLine);
                counter++;
                break;
            case 10:
                tempLine.erase(0, 3);
                nowaPraca.Praca::addStreszczenie(false, tempLine);
                counter++;
                break;
            default:
                // std::cout << "Blad podczas wczytywania danych" << std::endl;
                break;
            }

            if (counter == ILE_WARTOSCI_PRACA) {
                listaPrac.push_back(std::make_pair(nowaPraca.Praca::readIdPracy(), nowaPraca));
                // wypiszPrace(nowaPraca);
                counter = 0;
            }
        }
    }

}

// Wyswietla skrocona liste prac
void Biblioteka::wyswSkrocone(std::vector<std::pair<int, Praca>> listaPrac) {

    if (listaPrac.size() == 0) {
        errorLibraryEmpty();
    }
    else {
        for (unsigned int i = 0; i < listaPrac.size(); ++i) {
            std::cout <<
                std::to_string(listaPrac[i].second.Praca::readIdPracy()) + " " +
                listaPrac[i].second.Praca::readTypPracy() + " " +
                listaPrac[i].second.Praca::readInicjal() +
                listaPrac[i].second.Praca::readNazwiskoAutora() + " " +
                listaPrac[i].second.Praca::readTytul() + " " +
                std::to_string(listaPrac[i].second.Praca::readRok()) << std::endl;
        }
    }
}

// Wyswietla pelna liste prac
void Biblioteka::wyswPelne(std::vector<std::pair<int, Praca>> listaPrac) {

    if (listaPrac.size() == 0) {
        errorLibraryEmpty();
    }
    else {
        for (unsigned int i = 0; i < listaPrac.size(); ++i) {
            std::cout << "------------------------------------" << std::endl;
            std::cout
                << "ID: " << listaPrac[i].second.Praca::readIdPracy() << std::endl
                << "Typ: " << listaPrac[i].second.Praca::readTypPracy() << std::endl
                << "Autor: " << listaPrac[i].second.Praca::readImionaAutora() + " " + listaPrac[i].second.Praca::readNazwiskoAutora() << std::endl
                << "Tytul: " << listaPrac[i].second.Praca::readTytul() << std::endl
                << "Slowa kluczowe: " << listaPrac[i].second.Praca::readSlowaKluczowe() << std::endl
                << "Rok: " << listaPrac[i].second.Praca::readRok() << std::endl
                << "Promotor: " << listaPrac[i].second.Praca::readImionaPromotora() + " " + listaPrac[i].second.Praca::readNazwiskoPromotora() << std::endl
                << "Streszczenie: " << listaPrac[i].second.Praca::readStreszczenie() << std::endl;
        }
    }

    std::cout << "------------------------------------" << std::endl;
}

// Funkcja pozwalajace dodac nowa prace
void Biblioteka::dodajPrace() {

    Praca nowaPraca;
    std::cout << "Dodano nowa instancje praca" << std::endl;
    if (listaPrac.size() == 0) {
        nowaPraca.Praca::addIdPracy(0, true);
    }
    else nowaPraca.Praca::addIdPracy(Biblioteka::getLastId(listaPrac), true);
    std::cout << "Do pracy przypisano ID" << std::endl;
    std::cout << "ID tej pracy: " << nowaPraca.Praca::printSelected(0) << std::endl;

    nowaPraca.Praca::addTypPracy("");
    nowaPraca.Praca::addTytul("");
    nowaPraca.Praca::addNazwiskoAutora("");
    nowaPraca.Praca::addImionaAutora("");

    nowaPraca.Praca::addRok(-1);
    nowaPraca.Praca::addNazwiskoPromotora("");
    nowaPraca.Praca::addImionaPromotora("");
    nowaPraca.Praca::addSlowaKluczowe("");
    nowaPraca.Praca::addStreszczenie(true, "");

    listaPrac.push_back(std::make_pair(nowaPraca.Praca::readIdPracy(), nowaPraca));
    zapiszPrace(listaPrac);
}

// Funkcja zapisujaca prace w pliku
 void Biblioteka::zapiszPrace(std::vector<std::pair<int, Praca>>& listaPrac) {

    std::sort(listaPrac.begin(), listaPrac.end(), cmp);

    std::ofstream myfile("prace.txt", std::ofstream::out | std::ofstream::trunc);

    for (unsigned int i = 0; i < listaPrac.size(); i++) {
        myfile  << "ID " << listaPrac[i].second.readIdPracy() << '\n'
                << "TP " << listaPrac[i].second.readTypPracy() << '\n'
                << "TT " << listaPrac[i].second.readTytul() << '\n'
                << "AN " << listaPrac[i].second.readNazwiskoAutora() << '\n'
                << "AI " << listaPrac[i].second.readImionaAutora() << '\n'
                << "II " << listaPrac[i].second.readInicjal() << '\n'
                << "YY " << listaPrac[i].second.readRok() << '\n'
                << "PN " << listaPrac[i].second.readNazwiskoPromotora() << '\n'
                << "PI " << listaPrac[i].second.readImionaPromotora() << '\n'
                << "SK " << listaPrac[i].second.readSlowaKluczowe() << '\n'
                << "ST " << listaPrac[i].second.readStreszczenie() << '\n';
    }
    myfile.close();
}

 void Biblioteka::editAgain(bool & restart) {

     std::cout << "Czy chcesz edytowac inna wartosc?" << std::endl;
     std::cout << "y/n" << std::endl;

     char choice;
     std::cin >> choice;

     if (choice == 'y') restart = true;
     else restart = false;

 }

// Pozwala edytowac wybrana prace
 void Biblioteka::edytujPrace(std::vector<std::pair<int, Praca>> listaPrac) {

     bool restart = false;

     if (listaPrac.size() == 0) {
         errorLibraryEmpty();
     }
     else{
         do {

             restart = false;

             editMessageInitial();

             int temp = 0;
             int idZnalezionejPracy = 0;
             int indeksZnalezionejPracy = 0;
             bool found = false;
             std::cin >> temp;

             while (!found) {
                 for (unsigned int i = 0; i < listaPrac.size(); i++) {
                     if (listaPrac[i].first == temp) {
                         std::cout << "Znaleziono prace" << std::endl;
                         idZnalezionejPracy = listaPrac[i].first;
                         indeksZnalezionejPracy = i;
                         found = true;
                     }
                 }

                 break;

             }

             if (!found) {
                 std::cout << "Nie ma takiej pracy!" << std::endl;
                 std::cout << "Czy chcesz wyszukac prace jeszcze raz? " << std::endl;
                 std::cout << "y/n" << std::endl;

                 char choice;

                 std::cin >> choice;

                 if (choice == 'y') restart = true;
             }

             if (found) {

                 bool restartEditing = false;

                 do {

                     std::cout
                         << "ID: " << listaPrac[indeksZnalezionejPracy].second.Praca::readIdPracy() << std::endl
                         << "TP: " << listaPrac[indeksZnalezionejPracy].second.Praca::readTypPracy() << std::endl
                         << "TT: " << listaPrac[indeksZnalezionejPracy].second.Praca::readTytul() << std::endl
                         << "AN: " << listaPrac[indeksZnalezionejPracy].second.Praca::readNazwiskoAutora() << std::endl
                         << "AI: " << listaPrac[indeksZnalezionejPracy].second.Praca::readImionaAutora() << std::endl
                         << "II: " << listaPrac[indeksZnalezionejPracy].second.Praca::readInicjal() << std::endl
                         << "YY: " << listaPrac[indeksZnalezionejPracy].second.Praca::readRok() << std::endl
                         << "PN: " << listaPrac[indeksZnalezionejPracy].second.Praca::readNazwiskoPromotora() << std::endl
                         << "PI: " << listaPrac[indeksZnalezionejPracy].second.Praca::readImionaPromotora() << std::endl
                         << "SK: " << listaPrac[indeksZnalezionejPracy].second.Praca::readSlowaKluczowe() << std::endl
                         << "ST: " << listaPrac[indeksZnalezionejPracy].second.Praca::readStreszczenie() << std::endl;

                     editMessage();

                     int choice = 0;

                     std::cin >> choice;

                     switch (choice) {
                     case 1:
                         std::cout << "Podaj nowy typ pracy" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addTypPracy("");

                         Biblioteka::editAgain(restartEditing);

                         break;
                     case 2:
                         std::cout << "Podaj nowy tytul pracy" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addTytul("");

                         Biblioteka::editAgain(restartEditing);

                         break;
                     case 3:
                         std::cout << "Podaj nazwiska autora pracy" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addNazwiskoAutora("");
                         Biblioteka::editAgain(restartEditing);
                         break;
                     case 4:
                         std::cout << "Podaj imiona autora pracy" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addImionaAutora("");
                         Biblioteka::editAgain(restartEditing);
                         break;
                     case 5:
                         std::cout << "Podaj rok pracy" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addRok(0);
                         Biblioteka::editAgain(restartEditing);
                         break;
                     case 6:
                         std::cout << "Podaj nowe slowa kluczowe" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addSlowaKluczowe("");
                         Biblioteka::editAgain(restartEditing);
                         break;
                     case 7:
                         std::cout << "Podaj nowe streszczenie" << std::endl;
                         listaPrac[indeksZnalezionejPracy].second.Praca::addStreszczenie(false, "");
                         Biblioteka::editAgain(restartEditing);
                     default:
                         break;
                     }
                 } while (restartEditing);
             }

         } while (restart);
    }

}

// Wyszukuje 
 void Biblioteka::szukaj() {
     if (listaPrac.size() == 0) {
         errorLibraryEmpty();
     }
     else {
         searchMenuMessage();

         std::string search_key;
         std::vector<int> idWynikow;

         int choice = 0;
         std::cin >> choice;


         switch (choice) {

         case 1:
             std::cout << "Wyszukiwanie przez nazwisko\n";

             std::cin >> search_key;
             boost::algorithm::to_lower(search_key);

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readNazwiskoAutora().find(search_key) != std::string::npos) { 
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

            break; 
         case 2:
             std::cout << "Wyszukiwanie przez nazwisko promotora\n";

             std::cin >> search_key;
             boost::algorithm::to_lower(search_key);

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readNazwiskoPromotora().find(search_key) != std::string::npos) {
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

             break;
         case 3:
             std::cout << "Wyszukiwanie tytulem\n";

             std::cin >> search_key;
             boost::algorithm::to_lower(search_key);

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readTytul().find(search_key) != std::string::npos) {
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

             break;
         case 4:
             std::cout << "Wyszukiwanie slowami kluczkowymi\n";
             std::cin >> search_key;
             boost::algorithm::to_lower(search_key);

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readSlowaKluczowe().find(search_key) != std::string::npos) {
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

             break;
         case 5:
             std::cout << "Wyszukiwanie streszczeniem\n";
             std::cin >> search_key;
             boost::algorithm::to_lower(search_key);

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readStreszczenie().find(search_key) != std::string::npos) {
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

             break;
         case 6:
             std::cout << "Wyszukiwanie rokiem powstania\n";
             std::cin >> search_key;

             for (unsigned int i = 0; i < listaPrac.size(); i++)
             {
                 if (listaPrac[i].second.Praca::readRok() == std::stoi(search_key)) {
                     idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                 }
             }

             std::cout << "Znaleziono w pracach o ID: ";

             for (unsigned int i = 0; i < idWynikow.size(); i++)
             {
                 std::cout << idWynikow[i] << " ";
             }

             break;
         default:
             break;
         }
     }
}

// Wyswietla liczbe prac w bibliotece
 void Biblioteka::ilePrac() {
     if (listaPrac.size() == 0) {
         errorLibraryEmpty();
     }
     else {
         std::cout << listaPrac.size() << std::endl;
     }
}

// Wyswietla liczbe prac dla danego promotora
 void Biblioteka::ilePracPromotora() {

     if (listaPrac.size() == 0) {
         errorLibraryEmpty();
     }
     else {

         std::vector<std::pair<std::string, int>> listaPromotora;

         for (unsigned int i = 0; i < listaPrac.size(); i++) {
             listaPromotora.emplace_back(std::make_pair(listaPrac[i].second.readNazwiskoPromotora(), 0));
         }

         std::sort(listaPromotora.begin(), listaPromotora.end());
         listaPromotora.erase(unique(listaPromotora.begin(), listaPromotora.end()), listaPromotora.end());

         for (unsigned int j = 0; j < listaPromotora.size(); j++) {
             for (unsigned int i = 0; i < listaPrac.size(); i++) {
                 if (listaPromotora[j].first == listaPrac[i].second.readNazwiskoPromotora()) {
                     listaPromotora[j].second += 1;
                 }
             }
         }

         sort(listaPromotora.begin(), listaPromotora.end());

         for (unsigned int j = 0; j < listaPromotora.size(); j++) {

             std::cout << "Promotor: " << listaPromotora[j].first << " ilosc: "  << listaPromotora[j].second << std::endl;
             
         }

     }

}

// Wyswietla najczesciej wystepujace slowa kluczowe
 void Biblioteka::najczSlowaKluczowe() {
     if (listaPrac.size() == 0) {
         errorLibraryEmpty();
     }
     else {

     }
}