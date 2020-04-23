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

void listarPerguntas(ELEMENTO **iniLista){
    ELEMENTO *aux=NULL;

    if(iniLista==NULL){
        printf("Lista vazia\n");
    }
    printf("Categoria, Tipo\n");
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes){
        printf("%i- %i\n", aux->info.categoria, aux->info.tipo);
    }
}

int removerPerguntas(ELEMENTO **iniLista, int idPergunta){
    ELEMENTO *aux=NULL, *ant=NULL;
    aux=*iniLista;
    while(aux!=NULL && aux->info.tipo == idPergunta){
        ant=aux;
        aux=aux->seguintes;
    }
    if(aux==NULL){
        printf("A pergunta não existe\n");
        return -1;
    }
    if(ant ==NULL){ //remove o primeiro elemento da lista
        *iniLista=aux->seguintes;
    }
    else{
        ant->seguintes=aux->seguintes;
    }
    free(aux);
    return 0;
}
