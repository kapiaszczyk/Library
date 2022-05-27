#pragma once
#ifndef UI_MESSAGESS_SEEN
#define UI_MESSAGESS_SEEN

#include <iostream>
#include <vector>
#include <string>

class Praca;
//extern enum class Praca::messageFlag flag;

extern const std::vector<std::string> dozwoloneTypy;

extern void printTypeList(const std::vector<std::string>);

extern void menuMessage();

extern void subMenuMessage();

extern void searchMenuMessage();

extern void editMessage();

extern void editMessageInitial();

extern void errorLibraryEmpty();


// extern void typPracyMessage(enum Praca::messageFlag flag);

#endif