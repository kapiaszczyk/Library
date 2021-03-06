#include "Biblioteka.h"
#include "Praca.h"
#include "UI_messages.h"

// Misc 

    // Warunek sortowania prac wg ID
    bool cmp(std::pair<int, Praca> a, std::pair<int, Praca> b) {
        return a.first < b.first;
    }

    // Przekazuje ostatnio u?yte ID
    int Biblioteka::getLastId(std::vector<std::pair<int, Praca>>& listaPrac) {
        // Sortowanie listy prac w przypadku, gdy prace nie sa posortowane wg narastajacego ID
        std::sort(listaPrac.begin(), listaPrac.end(), cmp);
        return listaPrac.back().first;
    }

    // Sprawdza, czy plik wejsciowy jest pusty
    bool Biblioteka::isLibraryEmpty(Biblioteka biblioteka) {
        if ((std::filesystem::file_size("prace.dat") == 0)) return true;
        return false;
    }

    // Funkcja umozliwiajace edytowanie wielu elementu pracy
    void Biblioteka::editAgain(bool& restart) {

        std::cout << ">> Czy chcesz edytowac inna wartosc? y/n\n";
        coutInputIndicator();

        std::cin.clear();
        char choice;
        std::cin >> choice;

        if (choice == 'y') restart = true;
        else restart = false;

    }

// Main functions

    // Inicjalizuje menu biblioteki
    void Biblioteka::menu(Biblioteka& biblioteka) {

        int choice{};
        bool subMenu = false;
        bool wrongInput = false;

        do {

            menuMessage();

            std::cin >> choice;

            if (choice < 1 || choice > 7) {
                std::cout << ">> Wybierz jedna z opcji" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {

                switch (choice) {
                case 1:
                    biblioteka.dodajPrace();
                    break;
                case 2:
                    biblioteka.edytujPrace(biblioteka.listaPrac);
                    break;
                case 3:
                    biblioteka.wyswSkrocone(biblioteka.listaPrac);
                    break;
                case 4:
                    biblioteka.wyswPelne(biblioteka.listaPrac);
                    break;
                case 5:
                    biblioteka.szukaj();
                    break;
                case 6:
                    subMenu = true;
                    break;
                default:
                    std::cout << ">> Wybierz jedna z trzech funkcji" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    break;
                }

                while (subMenu) {

                    subMenuMessage();
                    int choiceSub{};
                    std::cin >> choiceSub;

                    switch (choiceSub) {
                    case 1:
                        Biblioteka::wyswietlLiczbePrac(listaPrac);
                        break;
                    case 2:
                        Biblioteka::ilePracPromotora();
                        break;
                    case 3:
                        Biblioteka::najczSlowaKluczowe();
                        break;
                    case 4:
                        subMenu = false;
                        break;
                    default:
                        std::cout << ">> Wybierz jedna z trzech funkcji" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }

            }
        } while (choice != 7);
    }

    // Wyswietla liczbe prac przechowywana w danym momencie w bibliotece
    void Biblioteka::wyswietlLiczbePrac(std::vector<std::pair<int, Praca>> listaPrac) {

        int liczbaMgr{}, liczbaLic{}, liczbaInz{};

        // Liczby wystapienie kazdego typu
        for (unsigned int i = 0; i < listaPrac.size(); ++i) {
            if (listaPrac[i].second.readTypPracy() == "mgr") liczbaMgr++;
            if (listaPrac[i].second.readTypPracy() == "lic") liczbaLic++;
            if (listaPrac[i].second.readTypPracy() == "inz") liczbaInz++;
        }

        // Przekazujemy liczbe wystapien na wyjscie
        separatorLine();
        std::cout << ">> Liczba wszystkich prac: " << listaPrac.size() << std::endl;
        std::cout << ">> Liczba wszystkich mgr: " << liczbaMgr << std::endl;
        std::cout << ">> Liczba wszystkich lic: " << liczbaLic << std::endl;
        std::cout << ">> Liczba wszystkich inz: " << liczbaInz << std::endl;
        separatorLine();

    }

    // Funkcja sprawdza, jaka wartosc zawiera dana linia w pliku
    int Biblioteka::checkValue(std::string line, const std::string id[]) {
        std::string lineId = "";
        for (int i = 0; i < ILE_WARTOSCI_PRACA; ++i) {
            if (line.substr(0, 2) == id[i]) return i;
            if (line == "") return -1;
        }
    }

    // Wczytuje wszystkie prace
    void Biblioteka::wczytajPrace(std::vector<std::pair<int, Praca>>& listaPrac) {

        Praca nowaPraca;

        if (std::filesystem::file_size("prace.dat") == 0) {
            errorLibraryEmpty();
        }
        else {
            std::ifstream stream("prace.dat");
            stream.seekg(0);

            std::string tempLine;

            int counter = 0;

            while (!stream.eof())
            {
                std::getline(stream, tempLine);

                switch (checkValue(tempLine, IDENTYFIKATORY_DANYCH)) {
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
                    nowaPraca.Praca::addSlowaKluczowe(false, tempLine);
                    counter++;
                    break;
                case 10:
                    tempLine.erase(0, 3);
                    nowaPraca.Praca::addStreszczenie(false, tempLine);
                    counter++;
                    break;
                default:
                    break;
                }

                if (counter == ILE_WARTOSCI_PRACA) {
                    listaPrac.push_back(std::make_pair(nowaPraca.Praca::readIdPracy(), nowaPraca));
                    counter = 0;
                }
            }
        }

    }

    // Wyswietla skrocona liste prac
    void Biblioteka::wyswSkrocone(std::vector<std::pair<int, Praca>> listaPrac) {

        std::cout << ">>  Lista prac - format skrocony\n";
        separatorLine();

        if (listaPrac.size() == 0) {
            errorLibraryEmpty();
        }
        else {
            for (unsigned int i = 0; i < listaPrac.size(); ++i) {
                std::cout << +"{" +
                    std::to_string(listaPrac[i].second.Praca::readIdPracy()) + "} " +
                    listaPrac[i].second.Praca::readTypPracy() + " " +
                    listaPrac[i].second.Praca::readInicjal() +
                    listaPrac[i].second.Praca::readNazwiskoAutora() + " \"" +
                    listaPrac[i].second.Praca::readTytul() + "\" " +
                    std::to_string(listaPrac[i].second.Praca::readRok()) << std::endl;
            }
        }

        separatorLine();

    }

    // Wyswietla pelna liste prac
    void Biblioteka::wyswPelne(std::vector<std::pair<int, Praca>> listaPrac) {

        std::cout << ">> Lista prac - format pelny" << std::endl;

        if (listaPrac.size() == 0) {
            errorLibraryEmpty();
        }
        else {
            for (unsigned int i = 0; i < listaPrac.size(); ++i) {
                separatorLine();
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

        separatorLine();
    }

    // Funkcja pozwalajace dodac nowa prace
    void Biblioteka::dodajPrace() {

        std::cout << ">> Dodawanie prac\n";

        Praca nowaPraca;

        if (listaPrac.size() == 0) {
            nowaPraca.Praca::addIdPracy(0, true);
        } else nowaPraca.Praca::addIdPracy(Biblioteka::getLastId(listaPrac), true);
        std::cout << ">> ID nowej pracy: " << std::to_string(nowaPraca.Praca::readIdPracy()) << std::endl;

        nowaPraca.Praca::addTypPracy("");
        nowaPraca.Praca::addTytul("");
        nowaPraca.Praca::addNazwiskoAutora("");
        nowaPraca.Praca::addImionaAutora("");

        nowaPraca.Praca::addRok(-1);
        nowaPraca.Praca::addNazwiskoPromotora("");
        nowaPraca.Praca::addImionaPromotora("");
        nowaPraca.Praca::addSlowaKluczowe(true, "");
        nowaPraca.Praca::addStreszczenie(true, "");

        listaPrac.push_back(std::make_pair(nowaPraca.Praca::readIdPracy(), nowaPraca));
        zapiszPrace(listaPrac);

        std::cout << ">> Praca zostala dodana do biblioteki\n";
    }

    // Funkcja zapisujaca prace w pliku
     void Biblioteka::zapiszPrace(std::vector<std::pair<int, Praca>>& listaPrac) {

        std::sort(listaPrac.begin(), listaPrac.end(), cmp);

        std::ofstream myfile("prace.dat", std::ofstream::out | std::ofstream::trunc);

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

    // Pozwala edytowac wybrana prace
     void Biblioteka::edytujPrace(std::vector<std::pair<int, Praca>> & listaPrac) {

         bool restart = false;

         if (listaPrac.size() == 0) {
             errorLibraryEmpty();
         }
         else{

             std::cout << ">> Edycja pracy\n";
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
                             std::cout << ">> Znaleziono prace" << std::endl;
                             idZnalezionejPracy = listaPrac[i].first;
                             indeksZnalezionejPracy = i;
                             found = true;
                         }
                     }

                     break;

                 }

                 if (!found) {
                     std::cout << ">> Nie ma takiej pracy!" << std::endl;
                     std::cout << ">> Czy chcesz wyszukac prace jeszcze raz? y/n" << std::endl;
                     coutInputIndicator();
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
                             listaPrac[indeksZnalezionejPracy].second.Praca::editTypPracy();
                             Biblioteka::editAgain(restartEditing);

                             break;
                         case 2:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editTytul();
                             Biblioteka::editAgain(restartEditing);

                             break;
                         case 3:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editNazwiskoAutora();
                             Biblioteka::editAgain(restartEditing);
                             break;
                         case 4:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editImionaAutora();
                             Biblioteka::editAgain(restartEditing);
                             break;
                         case 5:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editRok();
                             Biblioteka::editAgain(restartEditing);
                             break;
                         case 6:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editSlowaKluczowe();
                             Biblioteka::editAgain(restartEditing);
                             break;
                         case 7:
                             listaPrac[indeksZnalezionejPracy].second.Praca::editStreszczenie();
                             Biblioteka::editAgain(restartEditing);
                             break;
                         case 8:
                             std::cout << ">> Anulowanie edycji\n";
                             break;
                         default:
                             break;
                         }
                     } while (restartEditing);
                 }

             } while (restart);
        }

    }

    // Wyszukuje ID prac wg wybranego kryterium
    void Biblioteka::szukaj() {

         std::cout << ">> Wyszukiwanie pracy\n";
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
                 std::cout << ">> Wyszukiwanie nazwiskiem autora\n";
                 coutInputIndicator();
                 std::cin >> search_key;
                 boost::algorithm::to_lower(search_key);

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readNazwiskoAutora().find(search_key) != std::string::npos) { 
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
                 }

                break; 
             case 2:
                 std::cout << ">> Wyszukiwanie nazwiskiem promotora\n";

                 coutInputIndicator();
                 std::cin >> search_key;
                 boost::algorithm::to_lower(search_key);

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readNazwiskoPromotora().find(search_key) != std::string::npos) {
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
                 }

                 break;
             case 3:
                 std::cout << ">> Wyszukiwanie tytulem\n";
                 coutInputIndicator();
                 std::cin >> search_key;
                 boost::algorithm::to_lower(search_key);

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readTytul().find(search_key) != std::string::npos) {
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
                 }

                 break;
             case 4:
                 std::cout << ">> Wyszukiwanie slowami kluczowymi\n";

                 coutInputIndicator();
                 std::cin >> search_key;
                 boost::algorithm::to_lower(search_key);

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readSlowaKluczowe().find(search_key) != std::string::npos) {
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
                 }

                 break;
             case 5:
                 std::cout << ">> Wyszukiwanie streszczeniem\n";

                 coutInputIndicator();
                 std::cin >> search_key;
                 boost::algorithm::to_lower(search_key);

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readStreszczenie().find(search_key) != std::string::npos) {
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
                 }

                 break;
             case 6:
                 std::cout << ">> Wyszukiwanie rokiem powstania\n";

                 coutInputIndicator();
                 std::cin >> search_key;

                 for (unsigned int i = 0; i < listaPrac.size(); i++)
                 {
                     if (listaPrac[i].second.Praca::readRok() == std::stoi(search_key)) {
                         idWynikow.push_back(listaPrac[i].second.Praca::readIdPracy());
                     }
                 }

                 messageFoundInID();

                 for (unsigned int i = 0; i < idWynikow.size(); i++)
                 {
                     std::cout << idWynikow[i] << ", ";
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

         std::cout << ">> Liczba prac poszczegolnych promotorow\n";
         separatorLine();
         if (listaPrac.size() == 0) {
             errorLibraryEmpty();
         }
         else {

             // Tworzymy wektor unikalnych nazwisk promotorow
             std::vector<std::pair<std::string, int>> listaPromotora;
             for (unsigned int i = 0; i < listaPrac.size(); i++) {
                 listaPromotora.emplace_back(std::make_pair(listaPrac[i].second.readNazwiskoPromotora(), 0));
             }

             std::sort(listaPromotora.begin(), listaPromotora.end());
             listaPromotora.erase(unique(listaPromotora.begin(), listaPromotora.end()), listaPromotora.end());

             // Sprawdzamy w ktorej pracy wystepuje to nazwisko i zapisujemy to w drugim elemencie wektora
             for (unsigned int j = 0; j < listaPromotora.size(); j++) {
                 for (unsigned int i = 0; i < listaPrac.size(); i++) {
                     if (listaPromotora[j].first == listaPrac[i].second.readNazwiskoPromotora()) {
                         listaPromotora[j].second += 1;
                     }
                 }
             }

             // Sortowanie wektora
             sort(listaPromotora.begin(), listaPromotora.end());

             // Output
             for (unsigned int j = 0; j < listaPromotora.size(); j++) {
                 std::cout << ">> Promotor: " << listaPromotora[j].first << " ilosc prac: "  << listaPromotora[j].second << std::endl;
                 separatorLine();
             }

         }

    }

    // Wyswietla najczesciej wystepujace slowa kluczowe
     void Biblioteka::najczSlowaKluczowe() {

         std::cout << ">> 10 najczesciej powtarzajacych sie slow kluczowych\n";
         separatorLine();

         if (listaPrac.size() == 0) {
             errorLibraryEmpty();
         }
         else {

             // Dla kazdej pracy rozbijamy slowa kluczowe na pojedyncze slowa
             std::vector<std::string> listaSlow;

             for (unsigned int i = 0; i < listaPrac.size(); i++) {
                 std::string input = listaPrac[i].second.readSlowaKluczowe();
                 std::vector<std::string> slowa;
                 boost::split(slowa, input, boost::is_any_of(";"));
                 for (unsigned int i = 0; i < slowa.size(); i++) {
                     listaSlow.emplace_back(slowa[i]);
                 }
             }

             // Liczymy duplikaty
             std::sort(listaSlow.begin(), listaSlow.end());
             std::map<std::string, int> duplicates;
             for_each(listaSlow.begin(), listaSlow.end(), [&duplicates](std::string val) { duplicates[val]++; });

             // Dodajemy do wektora i sortujemy wg wystapien
             std::vector<std::pair<std::string, int>> pairs;
             for (auto itr = duplicates.begin(); itr != duplicates.end(); ++itr)
                 pairs.push_back(*itr);

             sort(pairs.begin(), pairs.end(), [=](std::pair<std::string, int>& a, std::pair<std::string, int>& b)
                 {
                     return a.second > b.second;
                 }
             );

             // Przekazujemy na wyjscie posortowany wektor, ograniczony do  10 pozycji
             pairs.resize(10);
             int index = 0;
             for (auto i : pairs) {std::cout << ++index << ". " << i.first << ' ' << i.second << std::endl; }
             separatorLine();
         }
    }