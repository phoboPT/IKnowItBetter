#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#define STRING_LENGHT 100
//Estruturas
typedef struct pergunta {
    int tipo;
    int categoria;
} PERGUNTA;

typedef struct Elem {
    PERGUNTA info;
    struct Elem *seguintes;
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




int inserirInLista(ELEMENTO **iniLista, PERGUNTA info);

#endif // HELPER_H_INCLUDED
