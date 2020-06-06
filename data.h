#ifndef	DATA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUL '\0'
#define CAT_TAM 50
#define STRING_LENGHT 100
#define TOTAL_CATEGORIAS 10

//Estruturas
typedef struct pergunta {
    int id;
    char resposta[STRING_LENGHT];
    char pergunta[STRING_LENGHT];
    int tipo;
    int categoria;
    char op1[STRING_LENGHT];
    char op2[STRING_LENGHT];
    char op3[STRING_LENGHT];
    char op4[STRING_LENGHT];
} PERGUNTA;

typedef struct jogador {
    char nome[STRING_LENGHT];
    char password[STRING_LENGHT];
    int tipo;
    int idade;
    char username[STRING_LENGHT];
    char nacionalidade[STRING_LENGHT];
    char data[STRING_LENGHT];
    int valorAcomulado;
    int somatorioTotal;
} JOGADOR;

typedef struct jogo {
    char jogador1[STRING_LENGHT];
    char jogador2[STRING_LENGHT];
    int valorJog1;
    int valorJog2;
    char data[STRING_LENGHT];
    int valorCaixa;
} JOGO;

typedef struct elemPergunta {
    PERGUNTA info;
    struct elem *seguinte;
} LISTAPERGUNTA;


typedef struct elemUtilizador {
    JOGADOR info;
    struct elem *seguinte;
} LISTAUTILIZADOR;

typedef struct elemJogo {
    JOGO info;
    struct elem *seguinte;
} LISTAJOGO;

//Funções
//Inserir
void inserirListaPergunta(LISTAPERGUNTA **iniLista, PERGUNTA info);
void inserirListaUtilizador(LISTAUTILIZADOR **iniLista, JOGADOR info);
void inserirListaJogos(LISTAJOGO **iniLista, JOGO info);
//Listar
void listarPerguntas(LISTAPERGUNTA *iniLista);
void listar(LISTAPERGUNTA *iniLista);
void listarJogos(LISTAJOGO *iniLista);
void listarJogadores(LISTAUTILIZADOR *iniLista);
//editar
void editaJogador(LISTAUTILIZADOR *iniLista,JOGADOR jogador);
void editarPergunta(LISTAPERGUNTA *iniLista);
//remover
int removerPerguntas(LISTAPERGUNTA **iniLista, int idPergunta);
//Gravar em ficheiro
int gravarPerguntas(LISTAPERGUNTA *iniLista,int total);
int gravarUtilizador(LISTAUTILIZADOR *iniLista, int total);
int gravarJogo(LISTAJOGO *iniLista, int total) ;
//Carregar ficheiro para memoria
int carregarPerguntas(LISTAPERGUNTA **iniLista,int **totalPerguntas);
int carregarJogador(LISTAUTILIZADOR **iniLista);
int carregarJogo(LISTAJOGO **iniLista);
//selecionar um elemento
PERGUNTA procurarPergunta(LISTAPERGUNTA *iniLista,int id);
PERGUNTA procurarPerguntaCategoria(LISTAPERGUNTA *iniLista,int categoria);
JOGADOR  procurarJogador(LISTAUTILIZADOR *iniLista);
//Libertar memoria
void libertaMemoriaPerguntas(LISTAPERGUNTA **iniFila);
void libertaMemoriaJogadores(LISTAUTILIZADOR **iniFila);
void libertaMemoriaJogo(LISTAJOGO **iniFila);
//Ordenar
void ordenarUtilizadores( LISTAUTILIZADOR *iniLista);
void ordenarUtilizadoresValorDec(LISTAUTILIZADOR *iniLista);
void ordenarUtilizadoresValorCres(LISTAUTILIZADOR *iniLista);
void ordenarJogoDataCres(LISTAJOGO *iniLista);
void ordenarJogoDataDec(LISTAJOGO *iniLista);
void ordenarJogoValor(LISTAJOGO *iniLista);
#endif // HELPER
