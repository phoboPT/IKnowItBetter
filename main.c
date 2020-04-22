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
    printf("2-Editar perguntas\n");
    printf("3-Remover perguntas\n");
    printf("0-Sair\n");
    scanf("%i", &adminOpcao);
    fflush(stdin);

    return adminOpcao;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    int opcao;
    char nome[100], pass[100];
    ELEMENTO * iniLista=NULL;





    do {
        opcao=mainMenu();
        switch (opcao)        {
        case 1: {
            opcao=adminMenu();
            switch(opcao) {
            case 1: {
                printf("case 1\n");
                adicionarPergunta(&iniLista);
                break;
            }
            case 2: {
                printf("case 2\n");
                  printLista(iniLista);
                break;
            }
            case 3: {
                printf("case 3\n");
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
