#include "data.h"
#include <stdio.h>
#include <stdlib.h>
//funçoes

int inserirInLista(ELEMENTO **iniLista, PERGUNTA info) {
    ELEMENTO *novo=NULL ;

    novo =(ELEMENTO *)calloc(1, sizeof(ELEMENTO));
    if(novo==NULL) {
        printf("Erro ao reservar memoria....");
        return -1;
    }
    novo->info=info;
    novo->seguintes=NULL;
    if(*iniLista ==NULL) {
        novo->info.id = 1;
        printf("%i", novo->info.id);
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
        printf("%i-%s\n", aux->info.id, aux->info.op1);
    }
    do {
        printf("Qual a pergunta que pretende ver em promenor?\n");
        scanf("%i",&opcao);
        if(opcao>totRegistos) {
            printf("ID inválido\n");
        }
    } while(opcao>totRegistos);
    i=0;

    for(aux=iniLista; aux!= NULL; aux = aux->seguintes) {
        i++;
        if(i==opcao) {
            printf("%i", aux->info.tipo);
            mostraPergunta(aux->info);
            return;
        }
    }
}


void mostraPergunta(PERGUNTA *pergunta) {
    printf("entrou");
    printf("%i ", &pergunta);
}


int gravarPerguntas(ELEMENTO *iniLista) {
    ELEMENTO *aux=NULL;
    FILE *fp = NULL;
    int totRegistos = 0;
    fp = fopen("perguntas.dat", "wb");
    if (fp == NULL) {
        printf("ERRO ao abrir o ficheiro\n");
        return -1;
    }
    if(iniLista==NULL) {
        printf("Sem dados para gravar\n");
    }
<<<<<<< HEAD
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
        totRegistos=totRegistos+1;
        printf("Totoal-%i\n", totRegistos);
    }
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {

        fwrite(&totRegistos, sizeof(int), 1, fp);
        fwrite(&aux->info, sizeof(PERGUNTA), totRegistos, fp);


        printf("Totoal-%i\n", totRegistos);
    }
    fclose(fp);
    return 0;
=======
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
        totRegistos=totRegistos+1;
    }
    fwrite(&totRegistos, sizeof(int), 1, fp);
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
        fwrite(&(aux->info), sizeof(PERGUNTA), 1, fp);
    }
    fclose(fp);
    printf("TOTREGISTOS: %i\n", totRegistos);
return 0;
>>>>>>> 5b75f548d8b0d89d8f2abeceb1b038859df180ec
}

int removerPerguntas(ELEMENTO **iniLista, int idPergunta) {
    ELEMENTO *aux=NULL, *ant=NULL;
    aux=*iniLista;
    while(aux!=NULL && aux->info.id == idPergunta) {
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

void carregarPerguntas(ELEMENTO **iniLista) {
    FILE *fp = NULL;
<<<<<<< HEAD
    PERGUNTA aux;


=======
    ELEMENTO *aux =NULL;
    //PERGUNTA *info=NULL;
>>>>>>> 5b75f548d8b0d89d8f2abeceb1b038859df180ec
    int totRegistos = 0;
    int res =0;
    fp = fopen("perguntas.dat", "rb");
    if (fp == NULL) {
        printf("Nao abriu o ficheiro...\n");
<<<<<<< HEAD
        return 0;
    }
    res = fread(&totRegistos, sizeof(int), 1, fp);
    printf("Totoal-%i\n", totRegistos);
    if (res > 0 && totRegistos >= 0) {
        fread(&aux, sizeof(PERGUNTA), totRegistos, fp);
        inserirInLista(&iniLista, aux);
    }
=======
        return;
    }
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
        totRegistos=totRegistos+1;
    }
    printf("totRegistos: %i\n", totRegistos);
    res= fread(&totRegistos, sizeof(int), 1, fp);
    if (res > 0 && totRegistos >= 0)
    {
    for(aux=iniLista; aux!= NULL; aux=aux->seguintes) {
            fread(&(aux->info), sizeof(PERGUNTA), 1, fp);
            }
            //inserirInLista(&iniLista, *info);
    }
    fclose(fp);
>>>>>>> 5b75f548d8b0d89d8f2abeceb1b038859df180ec
}

