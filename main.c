#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "data.h"


int main() {
    setlocale(LC_ALL,"Portuguese");
    ELEMENTO *iniLista=NULL;
    PERGUNTA aux;
    printf("Introduza os dados:\n 1-Nome\n");

    printf("Tipo:\n");
    scanf("%i",&aux.tipo);
    printf("Categoria:\n");
    scanf("%i",&aux.categoria);

    inserirInLista(&iniLista, aux);

    printLista(iniLista);

    return 0;
}
