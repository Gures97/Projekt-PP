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
            printf("\n\nUsunalem slowo.\n");
            break;
        case'4':
            printf("\n\nZapisalbym slownik do pliku.\n");
            break;
        case'5':
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

void UIpokaz_slownik(Lista beg, int ptr){
    char c;
    int i = 0;
    system("cls");
    if(beg == NULL){
        printf("Brak slow w slowniku\n");
    }
    while(beg != NULL){
        if(i == ptr)
            printf(">");
        wyswietl_slowo(beg);
        beg = beg->next;
        i++;
    }
    printf("ENTER aby wyjsc: ");
    fflush(stdin);
    getchar();
    //scanf("%c", &c);
}

void UIdodaj_slowo(Lista *slownik){
    char ang[MAX];
    char pol[3][MAX];
    char polbuf[MAX];
    int i, j;

    system("cls");
    printf("=====================\n");
    printf("     DODAJ SLOWO\n");
    printf("=====================\n\n\n");
    printf("Podaj slowo angielskie: ");
    fflush(stdin);
    gets(ang);
    for(i = 0; i < 3; i++){
        printf("Podaj %d polski odpowiednik (jesli wiecej nie ma - ENTER): ", i+1);
        fflush(stdin);
        gets(polbuf);
        if(!czy_jest_tab(polbuf,pol))
            strcpy(pol[i],polbuf);
        else
            strcpy(pol[i],"");
    }
    if(!czy_jest_ang(*slownik, ang))
        dodaj_slowo(slownik, ang, pol);
    else
        printf("juz jest takie slowo\n");

}

void UIusun_slowo(Lista *beg){
    char c, word[MAX];

    system("cls");
    printf("Usuwasz slowo angielskie(a) czy polskie(p)?: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c == 'a'){
        printf("Podaj slowo do usuniecia: ");
        fflush(stdin);
        gets(word);
        usun_slowo_ang(beg, word);
    }
}

int czy_jest_tab(char word[], char tab[][MAX]){
    int i;
    for(i = 0; i < 3; i++){
        if(!strcmp(word, tab[i]))
            return 1;
    }
    return 0;
}
