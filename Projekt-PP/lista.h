#ifndef LISTA_H
#define LISTA_H

typedef struct element{
    char* word_eng;
    char* word_pol[3];
    struct element *next;
}ELEMENT;
typedef ELEMENT *Lista;

Lista init();

void add(Lista, int);

int liczba_elementow(Lista);

#endif // LISTA_H
