#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    Lista lista;
    lista = init_list(3);

    printf("Hello world!\n");
    printf("Ilosc elementow listy: %d", liczba_elementow(lista));

    return 0;
}
