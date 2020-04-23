#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "data.h"

int mainMenu() {
    int opcao=0;
    printf("------Bem-Vindo ao IKnowItBetter------\n");
    printf("1-Administração das perguntas\n");
    printf("2-Comecar a jogar\n");
    printf("0-Sair\n");
    scanf("%i", &opcao);
    fflush(stdin);
    return opcao;
}
//---------Admin menu---------
int adminMenu() {
    int adminOpcao=0;
    printf("------Parte Administrativa------\n");
    printf("1-Criar perguntas\n");
    printf("2-Listar perguntas\n");
    printf("3-Remover perguntas\n");
    printf("0-Sair\n");
    scanf("%i", &adminOpcao);
    fflush(stdin);

    return adminOpcao;
}

PERGUNTA adicionarPergunta() {
    PERGUNTA aux;
    printf("1-Escolha multipla   2- Resposta Direta   3-Verdadeiro/Falso\n");
    printf("Categoria:\n");
    scanf("%i",&aux.categoria);
    printf("Tipo:\n");
    scanf("%i", &aux.tipo);
    }

int main() {
    setlocale(LC_ALL,"Portuguese");
    int opcao, idPergunta;
    char nome[100], pass[100];
    ELEMENTO *iniLista=NULL;
    PERGUNTA aux;

    do {
        opcao=mainMenu();
        switch (opcao)        {
        case 1: {
            opcao=adminMenu();
            switch(opcao) {
            case 1: {
                printf("case 1\n");
                aux = adicionarPergunta();
                inserirInLista(&iniLista, aux);
                break;
            }
            case 2: {
                printf("case 2\n");
                  listarPerguntas(iniLista);
                break;
            }
            case 3: {
                printf("Qual e o id que dejesa reover:\n");
                scanf("%i", &idPergunta);
                removerPerguntas(&iniLista, idPergunta);
                printf("A remover pergunta...\n");
                break;
            }
            default: {
                printf("default\n");
                break;
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
            break;
        }
        }
    } while(opcao!=0);

    return 0;
}
