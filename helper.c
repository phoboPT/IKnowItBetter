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
        info.id=1;
        printf("%i",info.id);
        *iniLista=novo;
    } else {
        novo -> seguintes=*iniLista;
        *iniLista=novo;
    }

    return 0;
}

void listarPerguntas(ELEMENTO *iniLista) {
    ELEMENTO *aux=NULL;
    int i=0,opcao=0,totRegistos=0;

    if(iniLista==NULL) {
        printf("Lista vazia\n");
    }
    printf("ID - Titulo\n");
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {


        totRegistos++;
        printf("%i- %s\n", aux->info.id,aux->info.pergunta);
    }
    do{
    printf("Qual a pergunta que pretende ver em promenor?\n");
    scanf("%i",&opcao);
    if(opcao>totRegistos){
        printf("ID inválido\n");
    }
    }while(opcao>totRegistos);
    i=0;

    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
        i++;
        if(i==opcao) {

            printf("%i- %s\n", i,aux->info.pergunta);
            return;
        }
    }
}

int removerPerguntas(ELEMENTO **iniLista, int idPergunta) {
    ELEMENTO *aux=NULL, *ant=NULL;
    aux=*iniLista;
    while(aux!=NULL && aux->info.tipo == idPergunta) {
        ant=aux;
        aux=aux->seguintes;
    }
    if(aux==NULL) {
        printf("A pergunta não existe\n");
        return -1;
    }
    if(ant ==NULL) { //remove o primeiro elemento da lista
        *iniLista=aux->seguintes;
    } else {
        ant->seguintes=aux->seguintes;
    }
    free(aux);
    return 0;
}
