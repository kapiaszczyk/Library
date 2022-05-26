#pragma once
#ifndef ADDITIONAL_FUNCTIONS_SEEN
#define ADDITIONAL_FUNCTIONS_SEEN

#include <string>
#include <iostream>
#include <vector>

extern const int MINIMALNY_ROK;
extern const int ILE_WARTOSCI_PRACA;

// Sprawdza, czy numer to int
bool check_number(std::string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) return false;
    }
    return true;
}


#endif