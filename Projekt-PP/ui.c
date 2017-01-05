#include "ui.h"
#include <stdio.h>

void komunikat(char wyb){
    switch(wyb){
        case'1':
            printf("\n\nPokazalbym slownik.\n");
            break;
        case'2':
            printf("\n\nDodalbym nowe slowo.\n");
            break;
        case'3':
            printf("\n\nZapislabym slownik do pliku.\n");
            break;
        case'4':
            printf("\n\nWczytalbym slownik z pliku.\n");
            break;
        case'q':
            printf("\n\nWychodze.\n");
            break;
        case'\0':
            printf("\n\n");
            break;
        default:
            printf("\n\nNie rozpoznano polecenia\n");
    }
}
