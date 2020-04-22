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

    do {
        opcao=mainMenu();
        switch (opcao)

        {
        case 1:
            printf("Parte administrativa:\n");
            printf("Realize o seu Login:\n");
            break;
        case 2:
            printf("Vamos la começar a  jogar\n");
            printf("Realize o login do jogador:\n");
            break;
        case 0:
            printf("A terminar o pograma...\n");
            break;

        default:
            printf("Opção não existente...\n");
        }
    } while(opcao!=0);

    return 0;
}
