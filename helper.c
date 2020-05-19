#include "data.h"



char categorias[][STRING_LENGHT] = {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemática", "Cultura Geral"};
char tipo[][STRING_LENGHT]= {"Escolha Multipla","Resposta Direta", "Verdadeito/Falso"};
//funçoes

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

void mostrarPertunta(PERGUNTA pergunta) {
    system("cls");
    printf("ID: %i\nPergunta: %s \nCategoria: %s \nResposta: %s \n",
           pergunta.id, pergunta.pergunta, categorias[pergunta.categoria],pergunta.resposta);
    if(pergunta.op1[0]!=NUL) {
        printf("Opcao 1: %s\n",pergunta.op1);
    }
    if(pergunta.op2[0]!=NUL) {
        printf("Opcao 2: %s\n",pergunta.op2);
    }
    if(pergunta.op3[0]!=NUL) {
        printf("Opcao 3: %s\n",pergunta.op3);
    }
    if(pergunta.op4[0]!=NUL) {
        printf("Opcao 4: %s\n",pergunta.op4);
    }
    system("pause");
}


void listarPerguntas(LISTAPERGUNTA *iniLista, int totRegistos) {
    LISTAPERGUNTA *aux = NULL;
    int opcao = 0,encontrou=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("ID     Titulo   \t\t\t  Tipo\n");

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("[%2i] - %-32s - %s\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1]);
    }

    do {
        printf("Qual a pergunta que pretende ver em promenor?\n");
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

    printf("ID     Titulo   \t\t\t  Tipo\n");

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("[%2i] - %-32s - %s\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1]);
    }
}

void editarPergunta(LISTAPERGUNTA *iniLista, int totRegistos) {
    LISTAPERGUNTA *aux = NULL;
    int opcao = 0,encontrou=0;

    if (iniLista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("ID     Titulo   \t\t\t  Tipo\n");

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        printf("[%2i] - %-32s - %s\n", aux->info.id, aux->info.pergunta,tipo[aux->info.tipo-1]);
    }

    do {
        printf("Qual a pergunta que pretende ver em promenor?\n");
        scanf("%i", &opcao);
        fflush(stdin);
        for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
            if (aux->info.id == opcao) {
                editar(&aux->info);
                encontrou=1;
                return;
            }
        }

        printf("ID inválido\n");
    } while(encontrou==0);
}

void editar(PERGUNTA *pergunta) {
    char alterar;
    system("cls");
    printf("Pergunta id: %i\n", pergunta->id);

    //alterar pergunta
    printf("Pergunta: %s\n",pergunta->pergunta);
    printf("Pretende alterar? s/n");
    scanf("%c", &alterar);
    fflush(stdin);
    printf("%c",alterar);
    if(alterar == 's') {
        printf("\nIntroduza a pergunta:");
        fgets(pergunta->pergunta, STRING_LENGHT, stdin);
        pergunta->pergunta[strlen(pergunta->pergunta) - 1] = NUL;
        fflush(stdin);
    }
    //alterar categoria
    printf("Pergunta: %s\n",categorias[pergunta->categoria]);
    printf("Pretende alterar? s/n");
    scanf("%c", &alterar);
    fflush(stdin);
    printf("%c",alterar);
    if(alterar == 's') {

        printf("\nIntroduza a pergunta:");
        fgets(pergunta->pergunta, STRING_LENGHT, stdin);
        pergunta->pergunta[strlen(pergunta->pergunta) - 1] = NUL;
        fflush(stdin);
    }
    //alterar resposta

}

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

int carregarPerguntas(LISTAPERGUNTA **iniLista) {
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

    printf("total perguntas: %i\n", totRegistos);

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

    printf("total jogadores: %i\n", totRegistos);

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

//Libertar memoria
void libertaMemoria(LISTAPERGUNTA **iniFila) {
    LISTAPERGUNTA *aux = NULL, *seguinte = NULL;
    aux = *iniFila;
    *iniFila = NULL;

    while (aux != NULL) {
        seguinte = aux->seguinte;
        free(aux);
        aux = seguinte;
    }
}

JOGADOR procurar(LISTAUTILIZADOR *iniLista,int totalUtilizadores) {
    LISTAUTILIZADOR *aux = NULL;
    JOGADOR jogador;

    char nome[STRING_LENGHT], pass[STRING_LENGHT];

    if (iniLista == NULL) {
        printf("Lista vazia\n\n");

        return jogador;
    }

    printf("Realize o seu Login\n");
    printf("Nome de utilizador:\n");
    fflush(stdin);
    scanf("%s", &nome);
    printf("Nome de password:\n");
    fflush(stdin);
    scanf("%s", &pass);
    fflush(stdin);

    for (aux = iniLista; aux != NULL; aux = aux->seguinte) {
        if(strcmp(strlwr(nome),strlwr(aux->info.username))==0 && strcmp(strlwr(pass),strlwr(aux->info.password))==0) {
            printf("entrou");
            jogador=aux->info;
        } else {
            jogador.tipo=0;
        }

    }
    return jogador;

}
