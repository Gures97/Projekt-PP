#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "ui.h"

int main()
{
    char q;
    Lista slownik = NULL;
    strcpy(tresc, "");
    do{
        printf("=====================\n");
        printf("       SLOWNIK\n");
        printf("=====================\n\n\n");
        printf("Liczba elementow slownika: %d\n\n", liczba_elementow(slownik));

        printf("1. Zobacz slownik.\n");
        printf("2. Wyszukaj slowo polskie.\n");
        printf("3. Dodaj nowe slowo.\n");
        printf("4. Usun slowo.\n");
        printf("5. Zapisz slownik do pliku.\n");
        printf("6. Wczytaj slownik z pliku.\n");
        printf("q. Wyjdz z programu.\n");

        komunikat(tresc);

        printf("Wybieram opcje: ");
        fflush(stdin);
        scanf("%c",&q);
        switch(q){
            case'1':
                UIpokaz_slownik(slownik, 0);
                break;
            case'2':
                break;
            case'3':
                UIdodaj_slowo(&slownik);
                break;
            case'4':
                UIusun_slowo(&slownik);
                break;
            case'5':
                UIzapisz(slownik);
                break;
            case'6':
                UIwczytaj(&slownik);
                break;
            case'q':
                break;
            case'\0':
                break;
            default:
                ;
        }

        if(q != 'q')
            system("cls");
    }while(q != 'q');
    destruktor(slownik);
    return 0;
}
