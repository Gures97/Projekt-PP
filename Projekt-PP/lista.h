#ifndef LISTA_H
#define LISTA_H

typedef struct element{
    char word_ang[35];
    char word_pol[3][35];
    struct element *next;
}ELEMENT;
typedef ELEMENT *Lista;

Lista init();

void add_empty(Lista);

#endif // LISTA_H
