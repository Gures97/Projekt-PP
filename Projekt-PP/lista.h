#ifndef LISTA_H
#define LISTA_H
#define MAX 35

typedef struct element{
    char word_eng[MAX];
    char word_pol[3][MAX];
    struct element *next;
}ELEMENT;
typedef ELEMENT *Lista;

void dodaj_slowo(Lista*, char ang[], char pol[][MAX]);

void usun_slowo_ang(Lista* beg, char word[]);

void usun_slowo_pol(Lista* beg, char word[]);

Lista czy_jest_ang(Lista beg, char slowo[]);

Lista czy_jest_pol(Lista beg, char slowo[]);

int ile_pol(Lista);

void usun_element(Lista*, Lista);

Lista last(Lista);

Lista prev(Lista, Lista);



int liczba_elementow(Lista);

void wyswietl_slowo(Lista);

void destruktor(Lista);

#endif // LISTA_H
