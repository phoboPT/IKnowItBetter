#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "data.h"
#define NUL '\0'
#define CAT_TAM 50
#define CAT_NUM 10

int mainMenu() {
    int opcao = 0;
    printf("------Bem-Vindo ao IKnowItBetter------\n\n");
    printf("1 - Administracão \n");
    printf("2 - Entrar no Jogo\n");
    printf("0 - Sair\n");
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
    } while (opcao < 0 || opcao > 2);
    return opcao;
}

//---------Admin menu---------
int adminMenu() {
    int opcaoAdmin = 0;

    system("cls");
    printf("------Parte Administrativa------\n");
    printf("1 - Criar perguntas\n");
    printf("2 - Listar perguntas\n");
    printf("3 - Editar perguntas\n");
    printf("4 - Remover perguntas\n");
    printf("0 - Sair\n");
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &opcaoAdmin);
        fflush(stdin);
    } while (opcaoAdmin < 0 || opcaoAdmin > 4);

    return opcaoAdmin;
}

//---------Jogador menu---------
int jogadorMenu() {
    int opcaoJogador = 0;

    system("cls");
    printf("------Vamos Começar a Jogar------\n");
    printf("1 - Começar a jogar\n");
    printf("2 - Ver Saldo\n");
    printf("3 - Ver as ultimas 50 partidas\n");
    printf("4 - Top 80 de jogadores com mais dinheiro\n");
    printf("0 - Sair\n");
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &opcaoJogador);
        fflush(stdin);
    } while (opcaoJogador < 0 || opcaoJogador > 4);

    return opcaoJogador;
}

int escolherCategoria(char categorias[][CAT_TAM]) {
    int opcao = 0;
    for (int i = 0; i < CAT_NUM; i++) {
        printf("%i - %s\n", i + 1, categorias[i]);
    }
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
    } while (opcao < 1 || opcao > CAT_NUM);
    return opcao - 1;
}

PERGUNTA adicionarPergunta(char categorias[][CAT_TAM], int *totalPerguntas) {
    PERGUNTA pergunta;

    pergunta.op1[0]=NUL;
    pergunta.op2[0]=NUL;
    pergunta.op3[0]=NUL;
    pergunta.op4[0]=NUL;

    int opcao = 0;
    system("cls");
    printf("1 - Escolha multipla   2 - Resposta Direta   3 - Verdadeiro/Falso\n");
    do {
        printf("Selecione uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
    } while (opcao < 1 || opcao > CAT_NUM);

    pergunta.tipo = opcao;
    pergunta.categoria = escolherCategoria(categorias);
    fflush(stdin);
    printf("\nIntroduza a pergunta: ");
    fgets(pergunta.pergunta, STRING_LENGHT, stdin);
    pergunta.pergunta[strlen(pergunta.pergunta) - 1] = NUL;
    fflush(stdin);

    //Escolha Multipla
    if (pergunta.tipo == 1) {

        printf("\nIntroduza a opção A: ");
        fgets(pergunta.op1, STRING_LENGHT, stdin);
        pergunta.op1[strlen(pergunta.op1) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a opção B: ");
        fgets(pergunta.op2, STRING_LENGHT, stdin);
        pergunta.op2[strlen(pergunta.op2) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a opção C: ");
        fgets(pergunta.op3, STRING_LENGHT, stdin);
        pergunta.op3[strlen(pergunta.op3) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a opção D: ");
        fgets(pergunta.op4, STRING_LENGHT, stdin);
        pergunta.op4[strlen(pergunta.op4) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a resposta A - B - C - D: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);

        (*totalPerguntas)++;
        pergunta.id = *totalPerguntas;
    }

    //Resposta Direta
    if (pergunta.tipo == 2) {

        printf("\nResposta: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);

        (*totalPerguntas)++;
        pergunta.id = *totalPerguntas;
    }
    //Verdadeiro Falso
    if (pergunta.tipo == 3) {

        printf("\nResposta V/F: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);

        (*totalPerguntas)++;
        pergunta.id = *totalPerguntas;
    }

    return pergunta;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char categorias[][CAT_TAM] = {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemástica", "Cultura Geral"};
    int opcao = 0, opcaoAdmin = 0, opcaoJogador = 0, idPergunta, totalPerguntas = 0;
    char nome[100], pass[100];
    ELEMENTO *iniLista = NULL;
    PERGUNTA aux;
    totalPerguntas = carregarPerguntas(&iniLista);

    do {
        opcao = mainMenu();
        switch (opcao) {
        case 1: {
            opcaoAdmin = adminMenu();
            switch (opcaoAdmin) {
            case 1: {
                char escolha;
                do {
                    aux = adicionarPergunta(categorias, &totalPerguntas);
                    inserirInLista(&iniLista, aux);
                    printf("Pretende inserir mais? S/N");
                    scanf("%c", &escolha);
                    fflush(stdin);

                } while (escolha == 's');
                gravarPerguntas(iniLista, totalPerguntas);
                break;
            }
            case 2: {
                listarPerguntas(iniLista, totalPerguntas);
                break;
            }
            case 3: {
                editarPergunta(iniLista,totalPerguntas);

                gravarPerguntas(iniLista, totalPerguntas);
                break;
            }
            case 4: {
                printf("Qual e o id que deseja remover:\n");
                scanf("%i", &idPergunta);
                fflush(stdin);
                removerPerguntas(&iniLista, idPergunta);
                printf("A remover pergunta...\n");
                gravarPerguntas(iniLista, totalPerguntas);
                break;
            }
            case 0: {
                printf("A Sair da parte administrativa...\n");
                libertaMemoria(&iniLista);
                break;
            }
            default:
                printf("Escolha uma nova opção\n");
            }
            break;
        }
        case 2: {
            printf("Realize o seu Login\n");
            printf("Nome de utilizador:\n");
            fflush(stdin);
            scanf("%s", &nome);
            printf("Nome de password:\n");
            fflush(stdin);
            scanf("%s", &pass);
            if (strcmp(nome, "nome") == 0 && (strcmp(pass, "pass") == 0)) {
                opcaoJogador = jogadorMenu();
                switch (opcaoJogador) {
                case 1: {
                    printf("Entrou na 1\n");
                }
                break;
                case 2: {
                    printf("Entrou na 2\n");
                }
                break;
                case 3: {
                    printf("Entrou na 3\n");
                }
                break;
                case 0: {
                    printf("A Sair do Login do jogador...\n");
                    libertaMemoria(&iniLista);
                    break;
                }
                default:
                    printf("Escolha uma nova opção\n");
                }
                break;
            }
        }
        case 0: {
            printf("A terminar o jogo...\n");
            libertaMemoria(&iniLista);
            break;
        }
        default: {
            printf("opção não existente...\n");
        }
        }

    } while (opcao != 0);

    return 0;
}
