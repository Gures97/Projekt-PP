#ifndef UI_H
#define UI_H
#include "lista.h"

char tresc[81];

void komunikat(char[]);

void UIpokaz_slownik(Lista, int);

void UIdodaj_slowo(Lista*);

void UIusun_slowo(Lista*);

void UIzapisz(Lista);

void UIwczytaj(Lista*);

int czy_jest_tab(char word[], char tab[][MAX]);

#endif // UI_H
