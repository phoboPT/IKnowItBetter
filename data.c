#include "data.h"
#define CAT_NUM 10

char categorias[][STRING_LENGHT] = {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemática", "Cultura Geral"};
char tipo[][STRING_LENGHT]= {"Escolha Multipla","Resposta Direta", "Verdadeito/Falso"};
//funçoes

//Inserir nas listas
void inserirListaPergunta(LISTAPERGUNTA **iniLista, PERGUNTA info) {
    LISTAPERGUNTA *novo = NULL, *aux = NULL;

    novo = (LISTAPERGUNTA *)calloc(1, sizeof(LISTAPERGUNTA));
    if (novo == NULL) {
        printf("Erro ao reservar memoria....");
        return;
    }
    novo->info = info;
    novo->seguinte = NULL;

    if (*iniLista == NULL) {

        *iniLista = novo;
    } else {

        aux = *iniLista;
        while (aux->seguinte != NULL) {
            aux = aux->seguinte;
        }
        aux->seguinte = novo;
    }

}

void inserirListaUtilizador(LISTAUTILIZADOR **iniLista, JOGADOR info) {
    LISTAUTILIZADOR *novo = NULL, *aux = NULL;

    novo = (LISTAUTILIZADOR *)calloc(1, sizeof(LISTAUTILIZADOR));
    if (novo == NULL) {
        printf("Erro ao reservar memoria....");
        return;
    }
    novo->info = info;
    novo->seguinte = NULL;

    if (*iniLista == NULL) {

        *iniLista = novo;
    } else {

        aux = *iniLista;
        while (aux->seguinte != NULL) {
            aux = aux->seguinte;
        }
        aux->seguinte = novo;
    }
}

void inserirListaJogos(LISTAJOGO **iniLista, JOGO info) {
    LISTAJOGO *novo = NULL, *aux = NULL;

    novo = (LISTAJOGO *)calloc(1, sizeof(LISTAJOGO));
    if (novo == NULL) {
        printf("Erro ao reservar memoria....");
        return;
    }
    novo->info = info;
    novo->seguinte = NULL;

    if (*iniLista == NULL) {

        *iniLista = novo;
    } else {

        aux = *iniLista;
        while (aux->seguinte != NULL) {
            aux = aux->seguinte;
        }
        aux->seguinte = novo;
    }

}

//Listagens
void mostrarPertunta(PERGUNTA pergunta) {

    system("cls");
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t----------------------------------------------------Detalhes da pergunta-----------------------------------------------------------\n");
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t|| ID   |Titulo   \t\t\t\t\t\t       |Tipo                  |Categoria        |Resposta        ||\n");
    printf("\t--------|--------------------------------------------------------------|----------------------|-----------------|------------------\n");
    printf("\t|| [%2i] | %-60s | %-20s | %-15s | %-15s||\n",pergunta.id, pergunta.pergunta,tipo[pergunta.tipo-1], categorias[pergunta.categoria],pergunta.resposta);
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
    if(pergunta.op1[0]!=NUL) {
        printf("\t||Opções de resposta \t\t\t\t\t\t\t\t\t\t\t\t\t\t ||\n");
        printf("\t||Opcao 1: %-60s \t\t\t\t\t\t\t ||\n",pergunta.op1);
    }
    if(pergunta.op2[0]!=NUL) {
        printf("\t||Opcao 2: %-60s \t\t\t\t\t\t\t ||\n",pergunta.op2);
    }
    if(pergunta.op3[0]!=NUL) {
        printf("\t||Opcao 3: %-60s \t\t\t\t\t\t\t ||\n",pergunta.op3);
    }
    if(pergunta.op4[0]!=NUL) {
        printf("\t||Opcao 4: %-60s \t\t\t\t\t\t\t ||\n",pergunta.op4);
        printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
    }

    system("pause");
}


void listarPerguntas(LISTAPERGUNTA *iniLista) {
    LISTAPERGUNTA *aux = NULL;
    int opcao = 0,encontrou=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    system("cls");
    printf("\n\n\t------------------------------------------------------------------------------------------------------------------\n");
    printf("\t-----------------------------------------Listagem de todas as perguntas-------------------------------------------\n");
    printf("\t------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");
    printf("\t|| ID   | Titulo  \t\t\t\t\t\t       | Tipo                 | Categoria      || \n");
    printf("\t--------|--------------------------------------------------------------|----------------------|------------------\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("\t|| [%2i] | %-60s | %-20s | %-15s||\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1],categorias[aux->info.categoria]);
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");

    do {
        printf("\tQual a pergunta que pretende ver em promenor?\n");
        scanf("%i", &opcao);
        fflush(stdin);
        for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
            if (aux->info.id == opcao) {
                mostrarPertunta(aux->info);
                encontrou=1;
                return;
            }
        }

        printf("ID inválido\n");
    } while(encontrou==0);
}

void listar(LISTAPERGUNTA *iniLista) {
    LISTAPERGUNTA *aux = NULL;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    system("cls");
    printf("\n\n\t------------------------------------------------------------------------------------------------------------------\n");
    printf("\t-----------------------------------------Listagem de todas as perguntas-------------------------------------------\n");
    printf("\t------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");
    printf("\t|| ID   | Titulo  \t\t\t\t\t\t       | Tipo                 | Categoria      || \n");
    printf("\t--------|--------------------------------------------------------------|----------------------|------------------\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("\t|| [%2i] | %-60s | %-20s | %-15s||\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1],categorias[aux->info.categoria]);
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");
}

void listarJogos(LISTAJOGO *iniLista) {
    LISTAJOGO *aux = NULL;
    int opcao = 0,encontrou=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }


    printf("\t----------------------------------------------------------------------------------------------\n");
    printf("\t||Jogador 1 \t  | Valor Ganho | Jogador 2 \t  | Valor Ganho | Valor caixa | Data        ||\n");
    printf("\t||----------------|-------------|-----------------|-------------|-------------|-------------||\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("\t||%-15s | %10i$ | %-15s | %10i$ | %10i$ | %-10s  ||\n", aux->info.jogador1, aux->info.valorJog1, aux->info.jogador2,aux->info.valorJog2,aux->info.valorCaixa,aux->info.data);
    }
    printf("\t----------------------------------------------------------------------------------------------\n");
}

void listarJogadores(LISTAUTILIZADOR *iniLista) {
    LISTAUTILIZADOR *aux = NULL;
    int opcao = 0,encontrou=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("\t-------------------------------------------------------------------------------\n");
    printf("\t||Jogador  \t  | Idade | Nacionalidade   | Total Ganho | Data Ultimo Jogo ||\n");
    printf("\t||----------------|-------|-----------------|-------------|------------------||\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("\t||%-15s | %-4i  | %-15s | %10i$ | %16s ||\n", aux->info.nome, aux->info.idade,aux->info.nacionalidade,aux->info.somatorioTotal,aux->info.data);
    }
    printf("\t-------------------------------------------------------------------------------\n");
}

//Editar
void editarPergunta(LISTAPERGUNTA *iniLista) {
    LISTAPERGUNTA *aux = NULL;
    int opcao = 0,encontrou=0;
    char edit;

    if (iniLista == NULL) {
        printf("\tLista vazia\n");
        return;
    }

    system("cls");
    printf("\n\n\t------------------------------------------------------------------------------------------------------------------\n");
    printf("\t-----------------------------------------Listagem de todas as perguntas-------------------------------------------\n");
    printf("\t------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");
    printf("\t|| ID   | Titulo  \t\t\t\t\t\t       | Tipo                 | Categoria      || \n");
    printf("\t--------|--------------------------------------------------------------|----------------------|------------------\n");
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("\t|| [%2i] | %-60s | %-20s | %-15s||\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1],categorias[aux->info.categoria]);
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------\n");
    printf("\tPretende alterar alguma pergunta? s/n: ");
    scanf("%c",&edit);

    if(edit != 's') {
        return;
    }

    do {
        printf("\n\tQual é a pergunta que pretende editar?\n");
        scanf("%i", &opcao);
        fflush(stdin);
        for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
            if (aux->info.id == opcao) {
                editar(&aux->info);
                encontrou=1;
                return;
            }
        }
        printf("\tID inválido\n");
    } while(encontrou==0);
}

void editar(PERGUNTA *pergunta) {
    char alterar;
    int categoria=0;
    system("cls");
    printf("\tPergunta id: %i\n", pergunta->id);

    //alterar pergunta
    printf("\tPergunta: %s\n",pergunta->pergunta);
    printf("\tPretende alterar? s/n: ");
    scanf("%c", &alterar);
    fflush(stdin);

    if(alterar == 's') {
        printf("\n\tIntroduza a pergunta: ");
        fgets(pergunta->pergunta, STRING_LENGHT, stdin);
        pergunta->pergunta[strlen(pergunta->pergunta) - 1] = NUL;
        fflush(stdin);
    }
    //alterar categoria
    printf("\tCategoria: %s\n",categorias[pergunta->categoria]);
    printf("\tPretende alterar? s/n: ");
    scanf("%c", &alterar);
    fflush(stdin);

    if(alterar == 's') {
        for (int i = 0; i < CAT_NUM; i++) {
            printf("\t%i - %s\n", i + 1, categorias[i]);
        }
        do {
            printf("\tSelecione uma opção: ");
            scanf("%i", &categoria);
            fflush(stdin);
        } while (categoria < 1 || categoria > 10);
        pergunta->categoria=categoria-1;
    }
    //alterar resposta
    //Tipo escolha multipla
    if(pergunta->tipo==1) {
        //Pergunta 1
        printf("\tResposta A: %s\n",pergunta->op1);
        printf("\tPretende alterar? s/n: ");

        fflush(stdin);

        if(alterar == 's') {
            printf("\n\tIntroduza a pergunta:");
            fgets(pergunta->op1, STRING_LENGHT, stdin);
            pergunta->op1[strlen(pergunta->op1) - 1] = NUL;
            fflush(stdin);
        }
        //Pergunta 2
        printf("\tResposta B: %s\n",pergunta->op2);
        printf("\tPretende alterar? s/n: ");
        scanf("%c", &alterar);
        fflush(stdin);

        if(alterar == 's') {
            printf("\n\tIntroduza a pergunta:");
            fgets(pergunta->op2, STRING_LENGHT, stdin);
            pergunta->op2[strlen(pergunta->op2) - 1] = NUL;
            fflush(stdin);
        }
        //Pergunta 3
        printf("\tResposta C: %s\n",pergunta->op3);
        printf("\tPretende alterar? s/n: ");
        scanf("%c", &alterar);
        fflush(stdin);

        if(alterar == 's') {
            printf("\n\tIntroduza a pergunta:");
            fgets(pergunta->op3, STRING_LENGHT, stdin);
            pergunta->op3[strlen(pergunta->op3) - 1] = NUL;
            fflush(stdin);
        }
        //Pergunta 4
        printf("\tResposta D: %s\n",pergunta->op4);
        printf("\tPretende alterar? s/n: ");
        scanf("%c", &alterar);
        fflush(stdin);

        if(alterar == 's') {
            printf("\n\tIntroduza a pergunta:");
            fgets(pergunta->pergunta, STRING_LENGHT, stdin);
            pergunta->op4[strlen(pergunta->op4) - 1] = NUL;
            fflush(stdin);
        }

    }
    //Tipo V/F e resposta direta
    else {
        printf("\tResposta: %s\n",pergunta->resposta);
        printf("\tPretende alterar? s/n: ");
        scanf("%c", &alterar);
        fflush(stdin);

        if(alterar == 's') {
            printf("\n\tIntroduza a resposta:");
            fgets(pergunta->pergunta, STRING_LENGHT, stdin);
            pergunta->pergunta[strlen(pergunta->pergunta) - 1] = NUL;
            fflush(stdin);
        }
    }

}

void editaJogador(LISTAUTILIZADOR *iniLista,JOGADOR jogador) {
    LISTAUTILIZADOR *aux = NULL;
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        if(strcmp(strlwr(jogador.username),strlwr(aux->info.username))==0 && strcmp(strlwr(jogador.password),strlwr(aux->info.password))==0) {
            aux->info=jogador;
        }
    }

}

//Gravar para ficheiro
int gravarPerguntas(LISTAPERGUNTA *iniLista, int total) {
    LISTAPERGUNTA *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("perguntas.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    fwrite(&total, sizeof(int), 1, fp);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        fwrite(&(aux->info), sizeof(PERGUNTA), 1, fp);
    }

    fclose(fp);
    printf("Gravou %i\n", total);
    printf("Ficheiro Guardado... \n");
    return 0;
}

int gravarUtilizador(LISTAUTILIZADOR *iniLista, int total) {
    LISTAUTILIZADOR *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("jogador.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    fwrite(&total, sizeof(int), 1, fp);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {

        fwrite(&(aux->info), sizeof(JOGADOR), 1, fp);
    }

    fclose(fp);
    printf("Gravou %i\n", total);
    printf("Ficheiro Guardado... \n");
    return 0;
}

int gravarJogo(LISTAJOGO *iniLista, int total) {
    LISTAJOGO *aux = NULL;
    FILE *fp = NULL;
    fp = fopen("jogos.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return -1;
    }
    fwrite(&total, sizeof(int), 1, fp);
    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        fwrite(&(aux->info), sizeof(JOGO), 1, fp);
    }

    fclose(fp);
    printf("Gravou %i\n", total);
    printf("Ficheiro Guardado... \n");
    return 0;
}

//Remover da lista
int removerPerguntas(LISTAPERGUNTA **iniLista, int idPergunta) {
    LISTAPERGUNTA *aux = NULL, *ant = NULL;
    aux = *iniLista;
    while (aux != NULL && (aux->info.id != idPergunta)) {
        ant = aux;
        aux = aux->seguinte;
    }
    if (aux == NULL) {
        printf("A pergunta não existe\n");
        return -1;
    }
    if (ant == NULL) {
        //remove o primeiro elemento da lista
        *iniLista = aux->seguinte;
    } else {
        ant->seguinte = aux->seguinte;
    }
    free(aux);
    return 0;
}

//Carregar para memoria do ficheiro
int carregarPerguntas(LISTAPERGUNTA **iniLista, int **totalPerguntas) {
    FILE *fp = NULL;
    PERGUNTA info;
    int totRegistos = 0;
    int res = 0;

    fp = fopen("perguntas.dat", "rb");
    if (fp == NULL) {
        printf("Nao abriu o ficheiro...\n");
        return 0;
    }

    fread(&totRegistos, sizeof(int), 1, fp);

    (*totalPerguntas)=totRegistos;

    if (totRegistos > 0) {
        for (int i = 0; i < totRegistos; i++) {
            fread(&info, sizeof(PERGUNTA), 1, fp);
            LISTAPERGUNTA *novo = NULL, *aux = NULL;
            novo = (LISTAPERGUNTA *)calloc(1, sizeof(LISTAPERGUNTA));
            if (novo == NULL) {
                printf("Erro ao reservar memoria....");
                return 0;
            }
            novo->info = info;
            novo->seguinte = NULL;

            if (*iniLista == NULL) {

                *iniLista = novo;
            } else {

                aux = *iniLista;
                while (aux->seguinte != NULL) {
                    aux = aux->seguinte;
                }
                aux->seguinte = novo;
            }

            if (info.id > res) {
                res = info.id;
            }
        }
    }

    return res;

    fclose(fp);
}

int carregarJogador(LISTAUTILIZADOR **iniLista) {
    FILE *fp = NULL;
    JOGADOR info;
    int totRegistos = 0;
    int res = 0;

    fp = fopen("jogador.dat", "rb");

    if (fp == NULL) {
        printf("Nao abriu o ficheiro...\n");
        return 0;
    }

    fread(&totRegistos, sizeof(int), 1, fp);

    if (totRegistos > 0) {

        for (int i = 0; i < totRegistos; i++) {

            fread(&info, sizeof(JOGADOR), 1, fp);
            LISTAUTILIZADOR *novo = NULL, *aux = NULL;
            novo = (LISTAUTILIZADOR *)calloc(1, sizeof(LISTAUTILIZADOR));

            if (novo == NULL) {
                printf("Erro ao reservar memoria....");
                return 0;
            }
            novo->info = info;
            novo->seguinte = NULL;

            if (*iniLista == NULL) {

                *iniLista = novo;
            } else {

                aux = *iniLista;
                while (aux->seguinte != NULL) {
                    aux = aux->seguinte;
                }
                aux->seguinte = novo;
            }

            res++;
        }
    }

    return res;

    fclose(fp);
}

int carregarJogo(LISTAJOGO **iniLista) {
    FILE *fp = NULL;
    JOGO info;
    int totRegistos = 0;
    int res = 0;

    fp = fopen("jogos.dat", "rb");

    if (fp == NULL) {
        printf("Nao abriu o ficheiro...\n");
        return 0;
    }

    fread(&totRegistos, sizeof(int), 1, fp);

    if (totRegistos > 0) {

        for (int i = 0; i < totRegistos; i++) {

            fread(&info, sizeof(JOGO), 1, fp);
            LISTAJOGO *novo = NULL, *aux = NULL;
            novo = (LISTAJOGO *)calloc(1, sizeof(LISTAJOGO));

            if (novo == NULL) {
                printf("Erro ao reservar memoria....");
                return 0;
            }
            novo->info = info;
            novo->seguinte = NULL;

            if (*iniLista == NULL) {

                *iniLista = novo;
            } else {

                aux = *iniLista;
                while (aux->seguinte != NULL) {
                    aux = aux->seguinte;
                }
                aux->seguinte = novo;
            }

            res++;
        }
    }

    return res;

    fclose(fp);
}

//Libertar memoria
void libertaMemoriaPerguntas(LISTAPERGUNTA **iniFila) {
    LISTAPERGUNTA *aux = NULL, *seguinte = NULL;
    aux = *iniFila;
    *iniFila = NULL;

    while (aux != NULL) {
        seguinte = aux->seguinte;
        free(aux);
        aux = seguinte;
    }
}

void libertaMemoriaJogadores(LISTAUTILIZADOR **iniFila) {
    LISTAUTILIZADOR *aux = NULL, *seguinte = NULL;
    aux = *iniFila;
    *iniFila = NULL;

    while (aux != NULL) {
        seguinte = aux->seguinte;
        free(aux);
        aux = seguinte;
    }
}

void libertaMemoriaJogo(LISTAJOGO **iniFila) {
    LISTAJOGO *aux = NULL, *seguinte = NULL;
    aux = *iniFila;
    *iniFila = NULL;

    while (aux != NULL) {
        seguinte = aux->seguinte;
        free(aux);
        aux = seguinte;
    }
}

//Selecionar
JOGADOR procurarJogador(LISTAUTILIZADOR *iniLista) {
    LISTAUTILIZADOR *aux = NULL;
    JOGADOR  jogador;
    char nome[STRING_LENGHT], pass[STRING_LENGHT];
    jogador.tipo=2;
    if (iniLista == NULL) {
        printf("Lista vazia\n\n");
        return jogador;
    }

    printf("\n\tTem de fazer Login para poder continuar\n");
    printf("\tUsername:");
    fflush(stdin);
    scanf("%s", &nome);
    printf("\tPassword:");
    fflush(stdin);
    scanf("%s", &pass);
    fflush(stdin);

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        if(strcmp(strlwr(nome),strlwr(aux->info.username))==0 && strcmp(strlwr(pass),strlwr(aux->info.password))==0) {
            return aux->info;
        }
    }
    return jogador;

}

PERGUNTA procurarPergunta(LISTAPERGUNTA *iniLista,int id) {
    LISTAPERGUNTA *aux = NULL;
    PERGUNTA pergunta;

    pergunta.id=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n\n");
        return pergunta;
    }

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        if(aux->info.id==id) {
            printf("Sim");
            return aux->info;

        }
    }
    printf("hey");
    printf("%i",pergunta.id);
    return pergunta;
}


PERGUNTA procurarPerguntaCategoria(LISTAPERGUNTA *iniLista,int categoria) {
    LISTAPERGUNTA *aux = NULL;
    PERGUNTA pergunta;

    if (iniLista == NULL) {
        printf("Lista vazia\n\n");
        return pergunta;
    }


    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        if(aux->info.categoria==categoria) {
            return aux->info;
        }

    }

    return pergunta;
}

//Ordenação
void ordenarUtilizadores(LISTAUTILIZADOR *iniLista) {
    int swapped, i;
    LISTAUTILIZADOR *ptr1;
    LISTAUTILIZADOR *ptr2;
    LISTAUTILIZADOR *lptr = NULL;

    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;
        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (strcmp(ptr1->info.nome, ptr2->info.nome)>0) {
                swapUtilizador(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarUtilizadoresValorDec(LISTAUTILIZADOR *iniLista) {
    int swapped, i;
    LISTAUTILIZADOR *ptr1;
    LISTAUTILIZADOR *ptr2;
    LISTAUTILIZADOR *lptr = NULL;

    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;

        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (ptr1->info.somatorioTotal < ptr2->info.somatorioTotal) {
                swapUtilizador(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}


void ordenarUtilizadoresValorCres(LISTAUTILIZADOR *iniLista) {
    int swapped, i;
    LISTAUTILIZADOR *ptr1;
    LISTAUTILIZADOR *ptr2;
    LISTAUTILIZADOR *lptr = NULL;

    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;
        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (ptr1->info.somatorioTotal > ptr2->info.somatorioTotal) {
                swapUtilizador(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarJogoDataCres(LISTAJOGO *iniLista) {
    int swapped, i;
    LISTAJOGO *ptr1;
    LISTAJOGO *ptr2;
    LISTAJOGO *lptr = NULL;

    /* Checking for empty list */
    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;
        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (strcmp(ptr1->info.data, ptr2->info.data)>0) {
                swapJogo(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}


void ordenarJogoDataDec(LISTAJOGO *iniLista) {
    int swapped, i;
    LISTAJOGO *ptr1;
    LISTAJOGO *ptr2;
    LISTAJOGO *lptr = NULL;

    /* Checking for empty list */
    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;
        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (strcmp(ptr1->info.data, ptr2->info.data)<0) {
                swapJogo(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarJogoValor(LISTAJOGO *iniLista) {
    int swapped, i;
    LISTAJOGO *ptr1;
    LISTAJOGO *ptr2;
    LISTAJOGO *lptr = NULL;

    /* Checking for empty list */
    if (iniLista == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = iniLista;
        while (ptr1->seguinte != lptr) {
            ptr2=ptr1->seguinte;
            if (ptr1->info.valorCaixa > ptr2->info.valorCaixa) {
                swapJogo(ptr1, ptr1->seguinte);
                swapped = 1;
            }
            ptr1 = ptr1->seguinte;
        }
        lptr = ptr1;
    } while (swapped);
}

void swapJogo( LISTAJOGO *a,  LISTAJOGO *b) {
    JOGO temp = a->info;
    a->info = b->info;
    b->info = temp;
}

/* function to swap data of two nodes a and b*/
void swapUtilizador( LISTAUTILIZADOR *a,  LISTAUTILIZADOR *b) {
    JOGADOR temp = a->info;
    a->info = b->info;
    b->info = temp;
}
