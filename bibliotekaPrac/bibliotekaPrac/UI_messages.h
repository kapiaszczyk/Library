#pragma once
#ifndef UI_MESSAGESS_SEEN
#define UI_MESSAGESS_SEEN

class Praca;

extern const std::vector<std::string> dozwoloneTypy;

extern void printTypeList(const std::vector<std::string> dozwoloneTypy);

extern void menuMessage();

extern void subMenuMessage();

extern void searchMenuMessage();

extern void editMessage();

extern void typPracyMessage(Praca::messageFlag flag);

#endif