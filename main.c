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

    //system("cls");
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

JOGADOR criarUtilizador(int *totalUtilizadores) {
    JOGADOR jogador;
    system("cls");
    printf("--------------Utilizador não existe-------------------\n\n");
    printf("--------------Criar Utilizador-------------------\n\n");
    printf("Introduza o seu nome: ");
    fgets(jogador.nome, STRING_LENGHT, stdin);
    jogador.nome[strlen(jogador.nome) - 1] = NUL;
    fflush(stdin);

    printf("Introduza o username: ");
    fgets(jogador.username, STRING_LENGHT, stdin);
    jogador.username[strlen(jogador.username) - 1] = NUL;
    fflush(stdin);

    printf("Introduza o password: ");
    fgets(jogador.password, STRING_LENGHT, stdin);
    jogador.password[strlen(jogador.password) - 1] = NUL;
    fflush(stdin);

    printf("Introduza a sua nacionalidade: ");
    fgets(jogador.nacionalidade, STRING_LENGHT, stdin);
    jogador.nacionalidade[strlen(jogador.nacionalidade) - 1] = NUL;
    fflush(stdin);

    printf("Introduza a sua idade: ");
    scanf("%i",&jogador.idade);

    fflush(stdin);

    //printf("Introduza o tipo: ");
    //scanf("%i",&jogador.tipo);

//    fflush(stdin);

    jogador.tipo=2;

    (*totalUtilizadores)++;


    return jogador;

}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char categorias[][CAT_TAM] = {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemática", "Cultura Geral"};
    int opcao = 0, opcaoAdmin = 0, opcaoJogador = 0, idPergunta, totalPerguntas = 0,totalUtilizadores;

    LISTAPERGUNTA *iniListaPergunta = NULL;
    LISTAUTILIZADOR *iniListaUtilizador = NULL;

    totalPerguntas = carregarPerguntas(&iniListaPergunta);
    totalUtilizadores=carregarJogador(&iniListaUtilizador);

    do {
        opcao = mainMenu();
        switch (opcao) {
        case 1: {
            opcaoAdmin = adminMenu();
            switch (opcaoAdmin) {
            case 1: {
                char escolha;
                do {
                    PERGUNTA aux;
                    aux = adicionarPergunta(categorias, &totalPerguntas);
                    inserirListaPergunta(&iniListaPergunta, aux);
                    printf("Pretende inserir mais? S/N");
                    scanf("%c", &escolha);
                    fflush(stdin);

                } while (escolha == 's');
                gravarPerguntas(iniListaPergunta, totalPerguntas);
                break;
            }
            case 2: {
                listarPerguntas(iniListaPergunta, totalPerguntas);
                break;
            }
            case 3: {
                editarPergunta(iniListaPergunta,totalPerguntas);
                gravarPerguntas(iniListaPergunta, totalPerguntas);
                break;
            }
            case 4: {
                int removeuPergunta=0;
                listar(iniListaPergunta);
                printf("Qual e o id que deseja remover:\n");
                scanf("%i", &idPergunta);
                fflush(stdin);
                removeuPergunta= removerPerguntas(&iniListaPergunta, idPergunta);
                if(removeuPergunta==0) {
                    printf("A remover pergunta...\n");
                    gravarPerguntas(iniListaPergunta, totalPerguntas);
                }
                break;
            }
            case 0: {
                printf("A Sair da parte administrativa...\n");
                libertaMemoria(&iniListaPergunta);
                break;
            }
            default:
                printf("Escolha uma nova opção\n");
            }
            break;
        }
        case 2: {
            JOGADOR utilizador;

            utilizador = procurar(iniListaUtilizador,totalUtilizadores);
            printf("%i",utilizador.tipo);

            if (utilizador.tipo !=0) {
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
                    libertaMemoria(&iniListaPergunta);
                    break;
                }
                default:
                    printf("Escolha uma nova opção\n");
                }
                break;
            } else {
                JOGADOR utilizador;
                utilizador=criarUtilizador(&totalUtilizadores);
                inserirListaUtilizador(&iniListaUtilizador,utilizador);
                gravarUtilizador(iniListaUtilizador, totalUtilizadores);

            }
            break;
        }
        case 0: {
            printf("A terminar o jogo...\n");
            libertaMemoria(&iniListaPergunta);
            break;
        }
        default: {
            printf("opção não existente...\n");
        }
        }

    } while (opcao != 0);

    return 0;
}
