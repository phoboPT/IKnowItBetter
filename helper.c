#include "data.h"
#include <stdio.h>
#include <stdlib.h>

char categorias[][CAT_TAM]= {"Geografia", "Hist�ria", "Cinema", "M�sica", "Desporto", "Inform�tica", "Biologia", "Agricultura", "Matem�tica","Cultura Geral"};

//fun�oes

void inserirInLista(ELEMENTO **iniLista, PERGUNTA info) {
    ELEMENTO *novo =NULL,*aux=NULL ;

    novo =(ELEMENTO *)calloc(1, sizeof(ELEMENTO));
    if(novo==NULL) {
        printf("Erro ao reservar memoria....");
        return -1;
    }
    novo->info=info;
    novo->seguinte=NULL;

    if(*iniLista == NULL) {

        *iniLista=novo;

    } else {

        aux=*iniLista;
        while(aux->seguinte!=NULL) {
            aux = aux->seguinte;
        }
        aux->seguinte = novo;
    }

    return 1;
}


void listarEscolhaMultipla(PERGUNTA pergunta) {

    printf("ID: %i\t Pergunta: %s Categoria: %s Resposta: %s Op��o 1: %s Op��o2: %s Op��o 3: %s Op��o4: %s \n", pergunta.id,pergunta.pergunta,categorias[pergunta.categoria], pergunta.resposta, pergunta.op1,pergunta.op2,pergunta.op3,pergunta.op4);
}

void listarVF(PERGUNTA pergunta) {
    printf("ID: %i\t Pergunta: %s Categoria: %s Resposta: %s  \n", pergunta.id,pergunta.pergunta,categorias[pergunta.categoria], pergunta.resposta);
}

void listarRespostaDireta(PERGUNTA pergunta) {

    printf("ID: %i\t Pergunta: %s Categoria: %s Resposta: %s  \n", pergunta.id,pergunta.pergunta,categorias[pergunta.categoria], pergunta.resposta);
}


void listarPerguntas(ELEMENTO *iniLista,int totRegistos) {
    ELEMENTO *aux=NULL;
    int opcao=0;

    if(iniLista==NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("ID - Titulo\n");

    do {
        for(aux=iniLista; aux!= NULL; aux=aux->seguinte) {

            printf("%i - %s\n", aux->info.id, aux->info.pergunta);
        }

        printf("Qual a pergunta que pretende ver em promenor?\n");
        scanf("%i",&opcao);
        fflush(stdin);
        if(opcao>totRegistos) {
            printf("ID inv�lido\n");
        }
    } while(opcao>totRegistos);

    for(aux=iniLista; aux!= NULL; aux = aux->seguinte) {

        if(aux->info.id==opcao) {
            if(aux->info.tipo==1) {
                listarEscolhaMultipla(aux->info);
            }
            if(aux->info.tipo==2) {
                listarRespostaDireta(aux->info);
            }
            if(aux->info.tipo==3) {
                listarVF(aux->info);
            }

            return;
        }
    }
}

void obterPergunta(ELEMENTO *iniLista,int totRegistos,PERGUNTA **pergunta){
     ELEMENTO *aux=NULL;
    int opcao=0;

    if(iniLista==NULL) {
        printf("Lista vazia\n");
        return;
    }


    do {
        for(aux=iniLista; aux!= NULL; aux=aux->seguinte) {
            printf("%i - %s\n", aux->info.id, aux->info.pergunta);
        }

        printf("Qual a pergunta que pretende editar?\n");
        scanf("%i",&opcao);
        fflush(stdin);
        if(opcao>totRegistos) {
            printf("ID inv�lido\n");
        }
    } while(opcao>totRegistos);

    for(aux=iniLista; aux!= NULL; aux = aux->seguinte) {

        if(aux->info.id==opcao) {
           *pergunta = &aux->info;
        }
    }


}

int gravarPerguntas(ELEMENTO *iniLista,int total) {
    ELEMENTO *aux=NULL;
    FILE *fp=NULL;
    fp=fopen("perguntas.dat", "wb");
    if(fp==NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    fwrite(&total, sizeof(int), 1, fp);
    for(aux=iniLista; aux!=NULL; aux=aux->seguinte) {
        fwrite(&(aux->info), sizeof(PERGUNTA), 1, fp);
    }

    fclose(fp);
    printf("gravou %i\n",total);
    printf("Ficheiro Guardado... \n");
    return 0;
}

int removerPerguntas(ELEMENTO **iniLista, int idPergunta) {
    ELEMENTO *aux=NULL, *ant=NULL;
    aux=*iniLista;
    while(aux!=NULL && aux->info.id == idPergunta) {
        ant=aux;
        aux=aux->seguinte;
    }
    if(aux==NULL) {
        printf("A pergunta n�o existe\n");
        return -1;
    }
    if(ant ==NULL) { //remove o primeiro elemento da lista
        *iniLista=aux->seguinte;
    } else {
        ant->seguinte=aux->seguinte;
    }
    free(aux);
    return 0;
}

int carregarPerguntas(ELEMENTO **iniLista) {
    FILE *fp = NULL;
    PERGUNTA info;
    int totRegistos = 0;
    int res =0;

    fp = fopen("perguntas.dat", "rb");

    if (fp == NULL) {
        printf("Nao abriu o ficheiro...\n");
        return ;
    }

    fread(&totRegistos, sizeof(int), 1, fp);

    printf("total perguntas: %i\n",totRegistos);

    if (totRegistos > 0) {

        for(int i=0; i<totRegistos; i++) {

            fread(&info, sizeof(PERGUNTA), 1, fp);
            ELEMENTO *novo =NULL,*aux=NULL ;
            novo = (ELEMENTO *)calloc(1, sizeof(ELEMENTO));

            if(novo==NULL) {
                printf("Erro ao reservar memoria....");
                return ;
            }
            novo->info=info;
            novo->seguinte=NULL;



            if(*iniLista == NULL) {

                *iniLista=novo;

            } else {

                aux=*iniLista;
                while(aux->seguinte!=NULL) {
                    aux = aux->seguinte;
                }
                aux->seguinte = novo;
            }

            if(info.id>res) {

                res=info.id;
            }

        }

    }


    return res;

    fclose(fp);
}

//Libertar memoria
void libertaMemoria(ELEMENTO **iniFila){
    ELEMENTO *aux=NULL, *seguinte=NULL;
    aux=*iniFila;
    *iniFila=NULL;

    while(aux!=NULL){
        seguinte=aux->seguinte;
        free(aux);
        aux=seguinte;
    }
}

