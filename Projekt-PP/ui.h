#ifndef UI_H
#define UI_H
#include "lista.h"

void komunikat(char);

void UIpokaz_slownik(Lista, int);

void UIdodaj_slowo(Lista*);

void UIusun_slowo(Lista*);

int czy_jest_tab(char word[], char tab[][MAX]);

#endif // UI_H
