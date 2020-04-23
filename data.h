#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#define STRING_LENGHT 100
#include <stdio.h>

//Estruturas
typedef struct pergunta {
    int tipo;
    int categoria;
} PERGUNTA;

typedef struct elem {
    PERGUNTA info;
    struct elem *seguintes;
} ELEMENTO;

typedef struct opcao {
    char op1[STRING_LENGHT];
    char op2[STRING_LENGHT];
    char op3[STRING_LENGHT];
    char op4[STRING_LENGHT];

} OPCAO;

typedef struct escolaM {
    OPCAO opcao;
    int resposta;
    char pergunta[STRING_LENGHT];
} ESCOLHAM;

typedef struct jogador{
    char nome[STRING_LENGHT];
    char password[STRING_LENGHT];
    int tipo;
    int idade;
    char username[STRING_LENGHT];
    char nacionalidade[STRING_LENGHT];
    char data[STRING_LENGHT];
    int valorAcomulado;

}JOGADOR;


int inserirInLista(ELEMENTO **iniLista, PERGUNTA info);
void listarPerguntas(ELEMENTO **iniLista);
int removerPerguntas(ELEMENTO **iniLista, int idPergunta);

#endif // HELPER_H_INCLUDED
