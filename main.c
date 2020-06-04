#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include "data.h"
#define NUL '\0'
#define CAT_TAM 50
#define CAT_NUM 10

int mainMenu() {
    int opcao = 0;
    printf("------Bem-Vindo ao IKnowItBetter------\n\n");
    printf("1 - Administra��o \n");
    printf("2 - Entrar no Jogo\n");
    printf("0 - Sair\n");
    do {
        printf("Selecione uma op��o: ");
        scanf("%i", &opcao);
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
        printf("Selecione uma op��o: ");
        scanf("%i", &opcaoAdmin);
        fflush(stdin);
    } while (opcaoAdmin < 0 || opcaoAdmin > 4);

    return opcaoAdmin;
}

//---------Jogador menu---------
int jogadorMenu() {
    int opcaoJogador = 0;

    //system("cls");
    printf("------Vamos Come�ar a Jogar------\n");
    printf("1 - Come�ar a jogar\n");
    printf("2 - Ver Saldo\n");
    printf("3 - Ver as ultimas 50 partidas\n");
    printf("4 - Listar Jogadores\n");
    printf("5 - Top 80 de jogadores com mais dinheiro\n");
    printf("0 - Sair\n");
    do {
        printf("Selecione uma op��o: ");
        scanf("%i", &opcaoJogador);
        fflush(stdin);
    } while (opcaoJogador < 0 || opcaoJogador > 8);

    return opcaoJogador;
}

int escolherCategoria(char categorias[][CAT_TAM]) {
    int opcao = 0;
    for (int i = 0; i < CAT_NUM; i++) {
        printf("%i - %s\n", i + 1, categorias[i]);
    }
    do {
        printf("Selecione uma op��o: ");
        scanf("%i", &opcao);
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
        printf("Selecione uma op��o: ");
        scanf("%i", &opcao);
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

        printf("\nIntroduza a op��o A: ");
        fgets(pergunta.op1, STRING_LENGHT, stdin);
        pergunta.op1[strlen(pergunta.op1) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a op��o B: ");
        fgets(pergunta.op2, STRING_LENGHT, stdin);
        pergunta.op2[strlen(pergunta.op2) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a op��o C: ");
        fgets(pergunta.op3, STRING_LENGHT, stdin);
        pergunta.op3[strlen(pergunta.op3) - 1] = NUL;
        fflush(stdin);

        printf("\nIntroduza a op��o D: ");
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
    printf("--------------Utilizador n�o existe-------------------\n\n");
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


//    printf("Introduza o tipo: ");
//    scanf("%i",&jogador.tipo);
//
//    fflush(stdin);

    jogador.tipo=1;

    jogador.valorAcomulado=0;
    strcpy(jogador.data,"");
    (*totalUtilizadores)++;


    return jogador;

}


int getNumPergunta(int perguntasFeitas[],int count,int totalPerguntas) {
    int valor=0,existe=0,sair=0;

    if(count==0) {
        valor=(rand()%totalPerguntas);

        return valor;
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

void printPergunta(PERGUNTA pergunta,char categorias[][CAT_TAM]) {

    printf("Categoria %s\n",categorias[pergunta.categoria]);
    printf("%s\n",pergunta.pergunta);

    if(pergunta.tipo==1) {

        printf("A - %s\n",pergunta.op1);
        printf("B - %s\n",pergunta.op2);
        printf("C - %s\n",pergunta.op3);
        printf("D - %s\n",pergunta.op4);

    }
    if(pergunta.tipo==2) {
        printf("Resposta directa\n");
    }
    if(pergunta.tipo==3) {
        printf("Resposta V/F \n");
    }


}

int responder(JOGADOR *util1,JOGADOR *util2,PERGUNTA pergunta,char char1,char char2,char categorias[][CAT_TAM]) {
    char jogador="";
    int tentativas=0;

    printPergunta(pergunta,categorias);

    do {
        printf("Introduza o carater  \n ");
        scanf("%c",&jogador);
        fflush(stdin);

    } while(!(jogador==char1 || jogador==char2));

    do {
        char aux="";

        if (jogador==char1) {

            printf("Introduza a resposta %s \n",util1->nome);
        } else {
            printf("Introduza a resposta %s \n",util2->nome);
        }
        char resposta[10];

        scanf("%s",resposta);
        fflush(stdin);


        //Acertou
        if(strcmp(strlwr(pergunta.resposta), strlwr(resposta))==0) {
            if (jogador==char1) {
                if(tentativas==0) {

                    util1->valorAcomulado+=250;
                } else {
                    util1->valorAcomulado+=300;
                }

            } else {
                if(tentativas==0) {

                    util2->valorAcomulado+=250;
                } else {
                    util2->valorAcomulado+=300;
                }
            }

            return 1;
        }

        if(tentativas!=1) {

            if (jogador==char1) {

                printf("Errou a pergunta, o %s pode responder\n",util2->nome);
            } else {
                printf("Errou a pergunta, o %s pode responder\n",util1->nome);
            }
        }

        aux=char1;
        char1=char2;
        char2=aux;
        tentativas++;


    } while(tentativas!=2);
    return 2;
}


int responderUltima(PERGUNTA *iniListaPergunta,JOGADOR *util1,JOGADOR *util2,char char1,char char2,char categorias[][CAT_TAM],int *valorCaixa) {
    PERGUNTA pergunta;
    char jogador="",resposta[10];
    int tentativas=0,aposta1=0,aposta2=0,categoria=0;


    if(util1->valorAcomulado<500) {
        printf("N�o tem dinheiro suficiente para apostar %s, tem neste momento %i, e ser� apostado tudo\n",util1->nome,util1->valorAcomulado);

        aposta1=util1->valorAcomulado;
    } else {
        printf("Quanto gostaria de apostar %s, tem neste momento %i\n",util1->nome,util1->valorAcomulado);
        scanf("%i",&aposta1);
    }
    if(util2->valorAcomulado<500) {
        printf("N�o tem dinheiro suficiente para apostar %s, tem neste momento %i, e ser� apostado tudo\n",util2->nome,util2->valorAcomulado);
        aposta2=util2->valorAcomulado;
    } else {
        printf("Quanto gostaria de apostar %s, tem neste momento %i\n",util2->nome,util2->valorAcomulado);
        scanf("%i",&aposta2);
    }



    if(util1->valorAcomulado >= util2->valorAcomulado) {
        printf("Qual e a categoria que quer selecionar %s\n",util1->nome);
        categoria=escolherCategoria(categorias);

    } else {
        printf("Qual e a categoria que quer selecionar %s\n",util2->nome);
        categoria=escolherCategoria(categorias);

    }

    pergunta=procurarPerguntaCategoria(iniListaPergunta,categoria);
    printPergunta(pergunta,categorias);

    do {
        printf("Introduza o carater  \n ");
        scanf("%c",&jogador);
        fflush(stdin);

    } while(!(jogador==char1 || jogador==char2));


    do {
        char aux="";

        if (jogador==char1) {

            printf("Introduza a resposta %s \n",util1->nome);
        } else {
            printf("Introduza a resposta %s \n",util2->nome);
        }

        char resposta[10];

        scanf("%s",resposta);
        fflush(stdin);

        //Acertou
        if(strcmp(strlwr(pergunta.resposta), strlwr(resposta))==0) {

            if (jogador==char1) {
                (* valorCaixa)-=aposta1;
                util1->valorAcomulado+=aposta1;
            } else {
                (* valorCaixa)-=aposta2;
                util2->valorAcomulado+=aposta2;
            }
            return 0;
        }

        if(tentativas!=1) {

            if (jogador==char1) {

                printf("Errou a pergunta, o %s pode responder\n",util2->nome);
            } else {
                printf("Errou a pergunta, o %s pode responder\n",util1->nome);
            }
        }

        aux=char1;
        char1=char2;
        char2=aux;
        tentativas++;

    } while(tentativas!=2);

    return 2;

}

int main() {
    setlocale(LC_ALL,"Portuguese");
    char categorias[][CAT_TAM] = {"Geografia", "Hist�ria", "Cinema", "M�sica", "Desporto", "Inform�tica", "Biologia", "Agricultura", "Matem�tica", "Cultura Geral"},data[15];
    int opcao = 0, opcaoAdmin = 0, opcaoJogador = 0, idPergunta, totalPerguntas = 0,totalUtilizadores=0,totalJogos=0;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(data, sizeof(data)-1, "%Y %m %d", t);

    LISTAPERGUNTA *iniListaPergunta = NULL;
    LISTAUTILIZADOR *iniListaUtilizador = NULL;
    LISTAJOGO *iniListaJogo=NULL;

    JOGADOR utilizador1,utilizador2;

    idPergunta = carregarPerguntas(&iniListaPergunta,&totalPerguntas);
    totalUtilizadores=carregarJogador(&iniListaUtilizador);
    totalJogos=carregarJogo(&iniListaJogo);

    srand(time(NULL));

    do {
        opcao = mainMenu();
        switch (opcao) {
        //Administra��o
        case 1: {



            JOGADOR utilizador;
            utilizador=procurarJogador(iniListaUtilizador);
            if (utilizador.tipo!=0) {
                printf("N�o tem permiss�es de administrador \n");
                system("pause");
                break;

            }
            do {
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
                    printf("Escolha uma nova op��o\n");
                    break;
                }


            } while(opcaoAdmin!=0);
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
            do {
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
                    system("pause");
                    //Responder perguntas

                    do {
                        system("cls");
                        PERGUNTA pergunta;
                        int idPerguntaAtual=0,acertou=0;
                        printf("Valor em caixa: %i\n",valorCaixa);
                        printf("Valor do %s: %i\n",utilizador1.nome,utilizador1.valorAcomulado);
                        printf("Valor do %s: %i\n\n",utilizador2.nome,utilizador2.valorAcomulado);

                        //Obter pergunta
                        do {
                            idPerguntaAtual=getNumPergunta(perguntasFeitas,count,totalPerguntas);

                            pergunta=procurarPergunta(iniListaPergunta,idPerguntaAtual);


                        } while(pergunta.id==0);

                        if(numeroPerguntas==1) {

                            responderUltima(iniListaPergunta,&utilizador1,&utilizador2,char1,char2,categorias,&valorCaixa);
                            acertou=0;
                        } else {
                            acertou = responder(&utilizador1,&utilizador2,pergunta,char1,char2,categorias);
                        }

                        perguntasFeitas[count]=idPerguntaAtual;


                        if(acertou==2) {
                            valorCaixa+=300;
                        }
                        acertou=0;
                        count++;
                        numeroPerguntas--;
                        system("pause");

                    } while(numeroPerguntas!=0);

                    if(utilizador1.valorAcomulado>utilizador2.valorAcomulado) {

                        printf("Jogador %s ganhou o jogo com %i, parab�ns\n",utilizador1.nome,   utilizador1.valorAcomulado);

                    } else {

                        printf("Jogador %s ganhou o jogo com %i, parab�ns\n",utilizador2.nome,   utilizador2.valorAcomulado);

                    }
                    JOGO novoJogo;
                    //Jogo

                    strcpy(novoJogo.jogador1,utilizador1.nome);
                    strcpy(novoJogo.jogador2,utilizador2.nome);
                    novoJogo.valorJog1=utilizador1.valorAcomulado;
                    novoJogo.valorJog2=utilizador2.valorAcomulado;
                    novoJogo.valorCaixa=valorCaixa;
                    strcpy(utilizador1.data,data);
                    strcpy(novoJogo.data,data);
                    inserirListaJogos(&iniListaJogo,novoJogo);

                    //Jogador
                    utilizador1.somatorioTotal+=utilizador1.valorAcomulado;
                    utilizador1.valorAcomulado=0;
                    utilizador2.somatorioTotal+=utilizador2.valorAcomulado;
                    utilizador2.valorAcomulado=0;
                    strcpy(utilizador2.data,data);

                    editaJogador(iniListaUtilizador,utilizador1);
                    editaJogador(iniListaUtilizador,utilizador2);
                    totalJogos++;
                    gravarJogo(iniListaJogo,totalJogos);
                    gravarUtilizador(iniListaUtilizador, totalUtilizadores);

                    break;
                }
                //Saldo
                case 2: {


                    printf("Valor acumulado do jogador 1 �: %i\n",utilizador1.valorAcomulado);
                    printf("Valor acumulado do jogador 2 �: %i\n",utilizador2.valorAcomulado);
                    break;
                }

                case 3: {
                    system("cls");

                    printf("---------------------------------Listar Jogos--------------------------------\n\n");
                    int opcaoOrder=0;
                    printf("1 - Ordenar por valor de caixa\n");
                    printf("2 - Ordenar por data decrescente\n");
                    printf("3 - Ordenar por data crescente\n");
                    scanf("%i",&opcaoOrder);

                    switch(opcaoOrder) {


                    case 1: {
                        system("cls");
                        printf("---------------------------------Jogos ordenados por valor da caixa--------------------------------\n\n");
                        ordenarJogoValor(iniListaJogo);
                        listarJogos(iniListaJogo);
                        system("pause");
                        break;
                    }
                    case 2: {
                        system("cls");
                        printf("---------------------------------Jogos ordenados por data decrescente--------------------------------\n\n");
                        ordenarJogoDataDec(iniListaJogo);
                        listarJogos(iniListaJogo);
                        system("pause");
                        break;
                    }
                    case 3: {
                        system("cls");
                        printf("---------------------------------Jogos ordenados por data decrescente--------------------------------\n\n");
                        ordenarJogoDataCres(iniListaJogo);
                        listarJogos(iniListaJogo);
                        system("pause");
                        break;
                    }


                    }
                    break;
                }
                case 4: {
                    int opcaoOrder=0;
                    system("cls");

                    printf("---------------------------------Listar Jogadoress--------------------------------\n\n");
                    printf("1 - Ordenar por nome\n");
                    printf("2 - Ordenar por valor acumulado decrescente\n");
                    printf("3 - Ordenar por valor acumulado crescente\n");
                    scanf("%i",&opcaoOrder);

                    switch(opcaoOrder) {


                    case 1: {
                        system("cls");
                        printf("---------------------------------Jogadores ordenados por nome--------------------------------\n\n");
                        ordenarUtilizadores(iniListaUtilizador);
                        listarJogadores(iniListaUtilizador);
                        system("pause");
                        break;
                    }
                    case 2: {
                        system("cls");
                        printf("---------------------------------Jogadores ordenados por valor ganho crescente--------------------------------\n\n");
                        ordenarUtilizadoresValorCres(iniListaUtilizador);
                        listarJogadores(iniListaUtilizador);
                        system("pause");
                        break;
                    }
                    case 3: {
                        system("cls");
                        printf("---------------------------------Jogadores ordenados por valor ganho decrescente--------------------------------\n\n");
                        ordenarUtilizadoresValorDec(iniListaUtilizador);
                        listarJogadores(iniListaUtilizador);
                        system("pause");
                        break;
                    }


                    }
                    break;
                }

                case 0: {
                    printf("A Sair do Login do jogador...\n");

                    break;
                }
                default: {
                    printf("Escolha uma nova op��o\n");
                    break;
                }
                }
            } while(opcaoJogador!=0);

        }
        case 0: {
            printf("A terminar o jogo...\n");
            libertaMemoriaPerguntas(&iniListaPergunta);
            libertaMemoriaJogadores(&iniListaUtilizador);
            libertaMemoriaJogo(&iniListaJogo);
            break;
        }
        default: {
            printf("op��o n�o existente...\n");
        }
        }

    } while (opcao != 0);

    return 0;
}
