#ifndef LISTA_H
#define LISTA_H
#define MAX 35

typedef struct element{
    char word_eng[MAX];
    char word_pol[3][MAX];
    struct element *next;
}ELEMENT;
typedef ELEMENT *Lista;

Lista dodaj_slowo(Lista);

Lista last(Lista);

Lista prev(Lista, Lista);

int liczba_elementow(Lista);

void wyswietl_slowo(Lista);

#endif // LISTA_H
