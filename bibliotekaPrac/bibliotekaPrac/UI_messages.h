#pragma once
#ifndef UI_MESSAGESS_SEEN
#define UI_MESSAGESS_SEEN

#include <iostream>
#include <vector>
#include <string>
#include <regex>

class Praca;
//extern enum class Praca::messageFlag flag;

extern const std::vector<std::string> DOZWOLONE_TYPY_PRAC;

extern void printTypeList(const std::vector<std::string>);

extern void menuMessage();

extern void subMenuMessage();

extern void searchMenuMessage();

extern void editMessage();

extern void editMessageInitial();

extern void errorLibraryEmpty();

extern void messageFoundInID();

extern void typPracyMessage(int);

extern void coutInputIndicator();

extern inline void separatorLine();

#endif