#pragma once
#ifndef ID_HPP_SEEN
#define ID_HPP_SEEN

#include <iostream>
#include <vector>


class Biblioteka;
class Praca;

Biblioteka biblioteka;

class ID {

public:

    int id;

    ID() {



        int lastID = 1;
        std::cout << "Pobrano ostatnie ID" << std::endl;
        id = lastID + 1;

    }

    // int getID();

    // virtual int getID(std::vector<Praca>& listaPrac);


};

#endif