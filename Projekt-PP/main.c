#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "ui.h"

int main()
{
    char q = 0;
    Lista slownik = NULL;
    while(q != 'q'){
        printf("=====================\n");
        printf("       SLOWNIK\n");
        printf("=====================\n\n\n");
        printf("Liczba elementow slownika: %d\n\n", liczba_elementow(slownik));

        printf("1. Zobacz slownik.\n");
        printf("2. Dodaj nowe slowo.\n");
        printf("3. Zapisz slownik do pliku.\n");
        printf("4. Wczytaj slownik z pliku.\n");
        printf("q. Wyjdz z programu.\n");

        komunikat(q);

        printf("Wybieram opcje: ");
        fflush(stdin);
        scanf("%c",&q);
        if(q != 'q')
            system("cls");
    }
    return 0;
}
