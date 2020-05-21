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
//Inserir
void inserirListaPergunta(LISTAPERGUNTA **iniLista, PERGUNTA info);
void inserirListaUtilizador(LISTAUTILIZADOR **iniLista, JOGADOR info);
//Listar
void listarPerguntas(LISTAPERGUNTA *iniLista);
void listar(LISTAPERGUNTA *iniLista);
//remover
int removerPerguntas(LISTAPERGUNTA **iniLista, int idPergunta);
//Gravar em ficheiro
int gravarPerguntas(LISTAPERGUNTA *iniLista,int total);
int gravarUtilizador(LISTAUTILIZADOR *iniLista, int total);
//Carregar ficheiro para memoria
int carregarPerguntas(LISTAPERGUNTA **iniLista,int **totalPerguntas) ;
int carregarJogador(LISTAUTILIZADOR **iniLista);
//selecionar um elemento
void obterPergunta(LISTAPERGUNTA *iniLista,int totRegistos,PERGUNTA **pergunta);
JOGADOR procurar(LISTAUTILIZADOR *iniLista);
//Libertar memoria
void libertaMemoriaPerguntas(LISTAPERGUNTA **iniFila);
void libertaMemoriaJogadores(LISTAUTILIZADOR **iniFila);



#endif // HELPER
