#ifndef ENDERECAMENTO_H
#define ENDERECAMENTO_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/time.h>
#include<time.h>
#define VAZIO "!!!!!!!!!!"
#define RETIRADO "**********"
#define M 999
#define n 999 /* Tamanho da chave */
#define O 999

typedef unsigned int Apontador;
typedef char Chave[n];
typedef unsigned Peso[n];
typedef struct Item {
/* outros componentes */
Chave chave;
} Item;
typedef unsigned int Indice;
typedef Item Dicionario[M];
Dicionario Tabela;
Peso p;
Item Elemento;
int j, i;

void inicializar(Dicionario t);
Apontador pesquisar(Chave chave, Peso p, Dicionario t);
void inserir(Item x, Peso p, Dicionario t);
void retirar(Chave chave, Peso p, Dicionario t);
int h(Chave chave , Peso p);
void gerar_pesos( Peso p);
#endif /* __ENDERECAMENTO_H */