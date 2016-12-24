#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    Lista lista = NULL;
    add(lista, 5);
    printf("Hello world!\n");
    printf("Ilosc elementow listy: %d", liczba_elementow(lista));
    return 0;
}
