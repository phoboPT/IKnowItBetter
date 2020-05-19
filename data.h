#ifndef	HELPER


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

typedef struct elemPergunta {
    PERGUNTA info;
    struct elem *seguinte;
} LISTAPERGUNTA;



typedef struct jogador {
    char nome[STRING_LENGHT];
    char password[STRING_LENGHT];
    int tipo;
    int idade;
    char username[STRING_LENGHT];
    char nacionalidade[STRING_LENGHT];
    char data[STRING_LENGHT];
    int valorAcomulado;
} JOGADOR;
typedef struct elemUtilizador {
    JOGADOR info;
    struct elem *seguinte;
} LISTAUTILIZADOR;



//Funções
void inserirListaPergunta(LISTAPERGUNTA **iniLista, PERGUNTA info);
void inserirListaUtilizador(LISTAUTILIZADOR **iniLista, JOGADOR info);
void listarPerguntas(LISTAPERGUNTA *iniLista, int totRegistos);
int removerPerguntas(LISTAPERGUNTA **iniLista, int idPergunta);
int gravarPerguntas(LISTAPERGUNTA *iniLista,int total);
int gravarUtilizador(LISTAUTILIZADOR *iniLista, int total);
int carregarPerguntas(LISTAPERGUNTA **iniLista);
int carregarJogador(LISTAUTILIZADOR **iniLista);
void obterPergunta(LISTAPERGUNTA *iniLista,int totRegistos,PERGUNTA **pergunta);
void libertaMemoria(LISTAPERGUNTA **iniFila);
void listar(LISTAPERGUNTA *iniLista);
JOGADOR procurar(LISTAUTILIZADOR *iniLista, int totalUtilizadores);

#endif // HELPER
