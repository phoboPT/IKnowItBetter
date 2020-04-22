#include "data.h"
//funçoes

int inserirInLista(ELEMENTO **iniLista, INFO info){
    ELEMENTO *novo=NULL;

    novo =(ELEMENTO *)calloc(1, sizeof(ELEMENTO));
    if(novo=NULL){
        printf("Erro ao reservar memoria....");
        return -1;
    }
    novo->info=info;
    novo->seguintes=NULL;
    if(*iniLista ==NULL){
        *iniLista=novo;
    }
    else{
        novo ->seguintes=*iniLista;
        *iniLista=novo;
    }
    return 0;
}
