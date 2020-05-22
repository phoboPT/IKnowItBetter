#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
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

PERGUNTA adicionarPergunta(char categorias[][CAT_TAM], int *totalPerguntas,int *idPergunta) {
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
        (*idPergunta)++;
        pergunta.id = *idPergunta;
    }

    //Resposta Direta
    if (pergunta.tipo == 2) {

        printf("\nResposta: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);

        (*totalPerguntas)++;
        (*idPergunta)++;
        pergunta.id = *idPergunta;
    }
    //Verdadeiro Falso
    if (pergunta.tipo == 3) {

        printf("\nResposta V/F: ");
        fgets(pergunta.resposta, STRING_LENGHT, stdin);
        pergunta.resposta[strlen(pergunta.resposta) - 1] = NUL;
        fflush(stdin);

        (*totalPerguntas)++;
        (*idPergunta)++;
        pergunta.id = *idPergunta;
    }

    return pergunta;
}

JOGADOR criarUtilizador(int *totalUtilizadores) {
    JOGADOR jogador;
    //system("cls");
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

    //fflush(stdin);

    jogador.tipo=1;

    (*totalUtilizadores)++;


    return jogador;

}


int getNumPergunta(int perguntasFeitas[],int count,int max,int totalPerguntas) {
    int valor=0,existe=0,sair=0;


    if(count==0) {

        return rand()%totalPerguntas;
    }

    do {
        valor=(rand()%totalPerguntas)+1;
        sair=0,existe=0;
        for (int i=0; i<count; i++) {

            if(perguntasFeitas[i]==valor) {

                existe=1;
                break;
            }
        }

        if(existe!=1) {
            sair=1;

        }

    } while(sair!=1);

    return valor;

}



void responder(JOGADOR *util1,JOGADOR *util2,PERGUNTA pergunta,char char1,char char2) {
    char jogador="";
    printf("%s\n",pergunta.pergunta);
    printf("%c",char1);
    if(pergunta.tipo==1) {

        printf("Opção 1\n",pergunta.op1);
        printf("Opção 2\n",pergunta.op2);
        printf("Opção 3\n",pergunta.op3);
        printf("Opção 4\n",pergunta.op4);

    }

    do {
        printf("Introduza o carater  \n ");
        scanf("%c",&jogador);
        fflush(stdin);

    } while(!(jogador==char1 || jogador==char2));




}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char categorias[][CAT_TAM] = {"Geografia", "História", "Cinema", "Música", "Desporto", "Informática", "Biologia", "Agricultura", "Matemática", "Cultura Geral"};
    int opcao = 0, opcaoAdmin = 0, opcaoJogador = 0, idPergunta, totalPerguntas = 0,totalUtilizadores;

    LISTAPERGUNTA *iniListaPergunta = NULL;
    LISTAUTILIZADOR *iniListaUtilizador = NULL;

    JOGADOR utilizador1,utilizador2;


    idPergunta = carregarPerguntas(&iniListaPergunta,&totalPerguntas);
    printf("\n%i",totalPerguntas);
    totalUtilizadores=carregarJogador(&iniListaUtilizador);

    do {
        opcao = mainMenu();
        switch (opcao) {
        //Administração
        case 1: {
            opcaoAdmin = adminMenu();
            switch (opcaoAdmin) {
            //Inserir perguntas
            case 1: {
                char escolha;
                do {
                    PERGUNTA aux;
                    aux = adicionarPergunta(categorias, &totalPerguntas, &idPergunta);
                    inserirListaPergunta(&iniListaPergunta, aux);
                    printf("Pretende inserir mais? S/N");
                    scanf("%c", &escolha);
                    fflush(stdin);

                } while (escolha == 's');
                printf("\n%i",totalPerguntas);
                gravarPerguntas(iniListaPergunta, totalPerguntas);
                break;
            }
            //Listar perguntas
            case 2: {
                listarPerguntas(iniListaPergunta);
                break;
            }
            //Editar perguntas
            case 3: {
                editarPergunta(iniListaPergunta);
                gravarPerguntas(iniListaPergunta, totalPerguntas);
                break;
            }
            //Remover perguntas
            case 4: {
                int removeuPergunta=0;
                listar(iniListaPergunta);
                printf("Qual e o id que deseja remover:\n");
                scanf("%i", &idPergunta);
                fflush(stdin);
                removeuPergunta= removerPerguntas(&iniListaPergunta, idPergunta);
                if(removeuPergunta==0) {
                    totalPerguntas--;
                    printf("A remover pergunta...\n");
                    gravarPerguntas(iniListaPergunta, totalPerguntas);
                }
                break;
            }
            case 0: {
                printf("A Sair da parte administrativa...\n");

                break;
            }
            default:
                printf("Escolha uma nova opção\n");
            }
            break;
        }

        //Login
        case 2: {
            int comecar=0;
            system("cls");
            //jogador 1
            utilizador1 = procurarJogador(iniListaUtilizador);
            if(utilizador1.tipo==2) {
                JOGADOR utilizador;
                utilizador1=criarUtilizador(&totalUtilizadores);
                inserirListaUtilizador(&iniListaUtilizador,utilizador1);
                gravarUtilizador(iniListaUtilizador, totalUtilizadores);
            }

            printf("\nJogador 2\n");
            //jogaodor 2
            do {
                utilizador2=procurarJogador(iniListaUtilizador);

                if(utilizador2.tipo==2) {
                    JOGADOR utilizador;
                    utilizador2=criarUtilizador(&totalUtilizadores);
                    inserirListaUtilizador(&iniListaUtilizador,utilizador2);
                    gravarUtilizador(iniListaUtilizador, totalUtilizadores);
                }
                printf("O jogador 2 tem de ser diferente do jogador 1\n");
            } while(strcmp(utilizador1.username,utilizador2.username)==0);

            //Se jogador existir
            opcaoJogador = jogadorMenu();
            switch (opcaoJogador) {
            //Jogar
            case 1: {
                int valorCaixa=900,numeroPerguntas=0,count=0;
                char char1="",char2="";

                //setup das variaveis
                utilizador1.valorAcomulado=0;
                utilizador2.valorAcomulado=0;


                do {
                    printf("Quantas perguntas deseja que o jogo tenha? ");
                    scanf("%i",&numeroPerguntas);
                    fflush(stdin);
                } while(numeroPerguntas>=totalPerguntas);

                printf("%s introduza o seu caracter\n",utilizador1.nome);
                scanf("%c",&char1);
                fflush(stdin);
                do {
                    printf("%s introduza o seu caracter\n",utilizador2.nome);
                    scanf("%c",&char2);
                    fflush(stdin);
                } while(char1==char2);

                printf("Categorias existentes\n");
                int perguntasFeitas[numeroPerguntas];

                //Mostrar categorias
                for (int i = 0; i < CAT_NUM; i++) {
                    printf("%i - %s\n", i + 1, categorias[i]);
                }

                //Responder perguntas

                do {
                    PERGUNTA pergunta;
                    int idPerguntaAtual=0;
                    printf("Valor em caixa: %i\n",valorCaixa);
                    printf("Valor do %s: %i\n",utilizador1.nome,utilizador1.valorAcomulado);
                    printf("Valor do %s: %i\n",utilizador2.nome,utilizador2.valorAcomulado);

                    //Obter pergunta
                    do {
                        idPerguntaAtual=getNumPergunta(perguntasFeitas,count,numeroPerguntas,totalPerguntas);
                        pergunta=procurarPergunta(iniListaPergunta,idPerguntaAtual);
                    } while(pergunta.id==0);

                    responder(&utilizador1,&utilizador2,pergunta,char1,char2);


                    if(numeroPerguntas==1) {
                        printf("ultima pergunta\n");
                    }
                    system("pause");
                    perguntasFeitas[count]=idPerguntaAtual;

                    count++;
                    numeroPerguntas--;

                } while(numeroPerguntas!=0);


                break;
            }
            //Saldo
            case 2: {
                int opcao=0;

                printf("Valor acumulado do jogador 1 é: %i\n",utilizador1.valorAcomulado);
                printf("Valor acumulado do jogador 2 é: %i\n",utilizador2.valorAcomulado);


                break;
            }

            case 3: {
                printf("Entrou na 3\n");

                break;
            }
            case 0: {
                printf("A Sair do Login do jogador...\n");

                break;
            }
            default:
                printf("Escolha uma nova opção\n");

                break;
            }



            break;
        }
        case 0: {
            printf("A terminar o jogo...\n");
            libertaMemoriaPerguntas(&iniListaPergunta);
            libertaMemoriaJogadores(&iniListaUtilizador);
            break;
        }
        default: {
            printf("opção não existente...\n");
        }
        }

    } while (opcao != 0);

    return 0;
}
