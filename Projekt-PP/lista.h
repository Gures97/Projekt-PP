#ifndef LISTA_H
#define LISTA_H

typedef struct element{
    char word_ang[35];
    char word_pol[3][35];
    element * next;
} ELEMENT;

typedef ELEMEMNT *Lista;
#endif // LISTA_H
