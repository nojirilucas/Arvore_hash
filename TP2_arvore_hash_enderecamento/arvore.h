#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define M 9999

typedef long Chave;

typedef struct Registro {
Chave chave;
char *nome;
} Registro;

typedef struct No * Apontador;

typedef struct No {
Registro registro;
Apontador esq, dir;
} No;

typedef Apontador Dicionario;

void antecessor(Apontador q, Apontador *r);
void pesquisar(Registro *x, Apontador p);
void inserir(Registro x, Apontador *p);
void inicializar(Apontador *dicionario);
void retirar(Registro x, Apontador *p);
void central(Apontador p);