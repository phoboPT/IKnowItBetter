#include <stdio.h>
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

typedef struct elem {
    PERGUNTA info;
    struct elem *seguinte;
} ELEMENTO;

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




//Funções
void inserirInLista(ELEMENTO **iniLista, PERGUNTA info);
void listarPerguntas(ELEMENTO *iniLista, int totRegistos);
int removerPerguntas(ELEMENTO **iniLista, int idPergunta);
int gravarPerguntas(ELEMENTO *iniLista,int total);
int carregarPerguntas(ELEMENTO **iniLista);
void obterPergunta(ELEMENTO *iniLista,int totRegistos,PERGUNTA **pergunta);
void libertaMemoria(ELEMENTO **iniFila);


