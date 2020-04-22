#include "data.h"
#include <stdio.h>
#include <stdlib.h>
//funçoes

int inserirInLista(ELEMENTO **iniLista, PERGUNTA info) {
    ELEMENTO *novo=NULL;

    novo =(ELEMENTO *)calloc(1, sizeof(ELEMENTO));
    if(novo==NULL) {
        printf("Erro ao reservar memoria....");
        return -1;
    }

    novo->info=info;
    novo->seguintes=NULL;
    if(*iniLista ==NULL) {
        *iniLista=novo;
    } else {
        novo ->seguintes=*iniLista;
        *iniLista=novo;
    }

    return 0;
}



void printLista(ELEMENTO *iniLista) {
    ELEMENTO *aux=NULL;
    if(iniLista==NULL) {
        printf("Lista vazia\n");
        return;
    }


    for(aux=iniLista; aux!=NULL; aux=aux->seguintes) {
        printf("%i %i\n", aux->info.categoria, aux->info.tipo);
    }

}

void adicionarPergunta( ELEMENTO ***iniLista) {
    PERGUNTA aux;
    printf("Categoria:\n");
    scanf("%i",&aux.categoria);
    printf("Tipo:\n");
    scanf("%i", &aux.tipo);
    inserirInLista(&iniLista, aux);



}
