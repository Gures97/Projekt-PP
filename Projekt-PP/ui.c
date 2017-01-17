#include "ui.h"
#include <stdio.h>


void komunikat(char napis[]){
    printf("\n\n%s\n", napis);

}

void UIpokaz_slownik(Lista beg, int ptr){
    char c;
    int i = 0;
    system("cls");
    if(beg == NULL){
        printf("Brak slow w slowniku.\n");
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
}

void UIdodaj_slowo(Lista *slownik){
    char ang[MAX], c;
    char pol[3][MAX];
    char polbuf[MAX];
    int i, j;
    Lista cur;

    system("cls");
    printf("=====================\n");
    printf("     DODAJ SLOWO\n");
    printf("=====================\n\n\n");
    printf("Usuwasz slowo angielskie(a) czy polskie(p)?: ");
    fflush(stdin);
    scanf("%c",&c);
    switch(c){
        case'a':{
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
                strcpy(tresc,"Juz jest takie slowo");break;
        }
        case'p':{
            printf("Podaj slowo polskie: ");
            fflush(stdin);
            gets(polbuf);
            printf("Podaj angielski odpowiednik: ");
            fflush(stdin);
            gets(ang);
            cur = czy_jest_ang(*slownik, ang);
            if(cur == NULL){
                strcpy(pol[0], polbuf);
                strcpy(pol[1], "");
                strcpy(pol[2], "");
                dodaj_slowo(slownik, ang, pol);
                strcpy(tresc, "Dodano nowe slowo.");
                return;
            }
            if(ile_pol(cur) > 2){
                strcpy(tresc, "Slowo ma pelna liste odpowiednikow.");
                return;
            }
            for(i = 0; i<3; i++){
                if(strlen(cur->word_pol[i]) == 0){
                    strcpy(cur->word_pol[i], polbuf);
                    strcpy(tresc, "Dodano nowe slowo.");
                    return;
                }
            }

            break;
        }

    }

}

void UIusun_slowo(Lista *beg){
    char c, word[MAX];

    system("cls");
    printf("Usuwasz slowo angielskie(a) czy polskie(p)?: ");
    fflush(stdin);
    scanf("%c",&c);
    switch(c){
        case'a':
            printf("Podaj slowo do usuniecia: ");
            fflush(stdin);
            gets(word);
            usun_slowo_ang(beg, word);
            strcpy(tresc, "Usunieto slowo.");break;
        case'p':
            printf("Podaj slowo do usuniecia: ");
            fflush(stdin);
            gets(word);
            usun_slowo_pol(beg, word);
            strcpy(tresc, "Usunieto slowo.");break;
        default:
            strcpy(tresc, "Nie rozpoznano polecenia.");
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

void UIzapisz(Lista beg){
    FILE * plik;
    Lista cur = beg;
    char nazwa[MAX];
    system("cls");
    printf("=====================\n");
    printf("     ZAPIS LISTY\n");
    printf("=====================\n\n\n");

    printf("Podaj nazwe pliku(bez rozszerzenia): ");
    fflush(stdin);
    gets(&nazwa);

    strcat(nazwa, ".txt");
    plik = fopen(nazwa, "w");
    if(plik == NULL){
        strcpy(tresc, "Blad tworzenia pliku txt.");
        return;
    }
    while(cur != NULL){
            fprintf(plik, "%s %s %s %s", cur->word_eng, cur->word_pol[0], cur->word_pol[1], cur->word_pol[2]);
            cur = cur->next;
    }
    strcpy(tresc, "Zapisano.");
    fclose(plik);

}

void UIwczytaj(Lista * beg){
    FILE * plik;
    Lista cur = beg;
    char c, nazwa[MAX], word_eng[MAX], word_pol[3][MAX];
    system("cls");
    printf("=====================\n");
    printf("   WCZYTANIE LISTY\n");
    printf("=====================\n\n\n");

    printf("Wykasowac wczesniejsza liste? (t/n): ");
    fflush(stdin);
    scanf("%c",&c);
    if(c == 't')
        destruktor(*beg);

    printf("Podaj nazwe pliku(z rozszerzeniem): ");
    fflush(stdin);
    gets(&nazwa);

    plik = fopen(nazwa, "r+");
    if(plik == NULL){
        strcpy(tresc, "Blad wczytania pliku.");
        return;
    }
    while(!feof(plik)){
            fscanf(plik, "%s %s %s %s", word_eng, word_pol[0], word_pol[1], word_pol[2]);
            dodaj_slowo(beg, word_eng, word_pol);
    }
    strcpy(tresc, "Wczytano.");
    fclose(plik);

}
