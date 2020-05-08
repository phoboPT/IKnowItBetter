#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "data.h"
#define NUL '\0'
#define CAT_TAM 50
#define CAT_NUM 10

int mainMenu() {
    int opcao=0;
    printf("------Bem-Vindo ao IKnowItBetter------\n\n");
    printf("1 - Administraçâo das perguntas\n");
    printf("2 - Comecar a jogar\n");
    printf("0 - Sair\n");
    scanf("%i", &opcao);
    fflush(stdin);
    return opcao;
}

//---------Admin menu---------
int adminMenu() {
    int adminOpcao=0;

    //system ("cls");
    printf("------Parte Administrativa------\n");
    printf("1 - Criar perguntas\n");
    printf("2 - Listar perguntas\n");
    printf("3 - Remover perguntas\n");
    printf("0 - Sair\n");
    scanf("%i", &adminOpcao);
    fflush(stdin);

    return adminOpcao;
}

int escolherCategoria(char categorias[][CAT_TAM]) {
    int opcao=0;
    for(int i =0; i<CAT_NUM; i++) {
        printf("%i - %s\n",i+1, categorias[i]);
    }
    scanf("%i", &opcao);
    return opcao-1;
}

PERGUNTA adicionarPergunta(char categorias[][CAT_TAM],int *totalPerguntas) {
    PERGUNTA pergunta;

    //system ("cls");
    printf("1 - Escolha multipla   2 - Resposta Direta   3 - Verdadeiro/Falso");

    scanf("%i", &pergunta.tipo);
    pergunta.categoria=escolherCategoria(categorias);

    //Escolha Multipla
    if(pergunta.tipo==1) {
        fflush(stdin);

        printf("\nIntroduza a pergunta: ");
        fgets(pergunta.pergunta, STRING_LENGHT, stdin);
        pergunta.pergunta[strlen(pergunta.pergunta) - 1] = NUL;
        fflush(stdin) ;
        printf("%s",pergunta.pergunta);

        printf("\nIntroduza a opção A: ");
        fgets(pergunta.op1, STRING_LENGHT, stdin);
        pergunta.op1[strlen(pergunta.op1) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.op1);

        printf("\nIntroduza a opção B: ");
        fgets(pergunta.op2, STRING_LENGHT, stdin);
        pergunta.op2[strlen(pergunta.op2) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.op2);

        printf("\nIntroduza a opção C: ");
        fgets(pergunta.op3, STRING_LENGHT, stdin);
        pergunta.op3[strlen(pergunta.op3) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.op3);

        printf("\nIntroduza a opção D: ");
        fgets(pergunta.op4, STRING_LENGHT, stdin);
        pergunta.op4[strlen(pergunta.op4) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.op4);

        printf("\nIntroduza a resposta A - B - C - D: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.resposta);

        (*totalPerguntas)++;
        pergunta.id=*totalPerguntas;
    }

      //Resposta Direta
    if(pergunta.tipo==2) {
        fflush(stdin);
        printf("\nIntroduza a pergunta: ");
        fgets(pergunta.pergunta, STRING_LENGHT, stdin);
        pergunta.pergunta[strlen(pergunta.pergunta) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.pergunta);

        printf("\nResposta: ");
        fgets(pergunta.op1, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.resposta);
        (*totalPerguntas)++;
        pergunta.id=*totalPerguntas;
    }
    //Verdadeiro Falso
    if(pergunta.tipo==3) {
        fflush(stdin);

        printf("\nIntroduza a pergunta: ");
        fgets(pergunta.pergunta, STRING_LENGHT, stdin);
        pergunta.pergunta[strlen(pergunta.pergunta) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.pergunta);

        printf("\nResposta V/F: ");
        fgets(pergunta.op1, STRING_LENGHT, stdin);
        pergunta.op1[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);
        printf("%s",pergunta.op1);
        (*totalPerguntas)++;
        pergunta.id=*totalPerguntas;


    }


    return pergunta;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char categorias[][CAT_TAM]= {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemática","Cultura Geral"};
    int opcao=0, idPergunta,totalPerguntas=0;
    char nome[100], pass[100];
    ELEMENTO *iniLista=NULL;
    PERGUNTA aux;
    totalPerguntas=carregarPerguntas(&iniLista);


    do {
        opcao=mainMenu();
        switch (opcao) {
        case 1: {
            opcao=adminMenu();
            switch(opcao) {
            case 1: {
                char escolha;
                do {
                    aux = adicionarPergunta(categorias,&totalPerguntas);
                    inserirInLista(&iniLista, aux);
                    printf("Pretende inserir mais? S/N");
                    scanf("%c", &escolha);
                    fflush(stdin);
                    gravarPerguntas(iniLista,totalPerguntas);

                } while(escolha == "s");
                break;
            }
            case 2: {

                listarPerguntas(iniLista,totalPerguntas);

                break;
            }
            case 3: {
                printf("Qual e o id que deseja remover:\n");
                scanf("%i", &idPergunta);
                fflush(stdin);
                removerPerguntas(&iniLista, idPergunta);
                printf("A remover pergunta...\n");
                break;
            }
            default: {


            }
            }
            break;
        }
        case 2: {
            printf("Vamos la começar a  jogar\n");
            printf("Realize o login do jogador:\n");
            break;
        }
        case 0: {
            printf("A terminar o pograma...\n");
            break;
        }
        default: {
            printf("Opção não existente...\n");

        }
        }
    } while(opcao!=0);

    return 0;
}

