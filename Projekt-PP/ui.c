#include "ui.h"
#include <stdio.h>

void komunikat(char wyb){
    switch(wyb){
        case'1':
            printf("\n\nPokazalem slownik.\n");
            break;
        case'2':
            printf("\n\nDodalem nowe slowo.\n");
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

void UIpokaz_slownik(Lista beg){
    char c;
    system("cls");
    if(beg == NULL){
        printf("Brak slow w slowniku\n");
    }
    while(beg != NULL){
        wyswietl_slowo(beg);
        beg = beg->next;
    }
    printf("ENTER aby wyjsc: ");
    fflush(stdin);
    getchar();
    //scanf("%c", &c);
}

void UIdodaj_slowo(Lista *slownik){
    char ang[MAX];
    char pol[3][MAX];
    int i;

    system("cls");
    printf("=====================\n");
    printf("     DODAJ SLOWO\n");
    printf("=====================\n\n\n");
    printf("Podaj slowo angielskie: ");
    fflush(stdin);
    gets(ang);
    fflush(stdin);
    for(i = 0; i < 3; i++){
        printf("Podaj %d polski odpowiednik (jesli wiecej nie ma - ENTER): ", i+1);
        gets(pol[i]);
    }
    dodaj_slowo(slownik, ang, pol);

}
