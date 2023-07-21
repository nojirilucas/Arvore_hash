#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<sys/time.h>
#include<time.h>
#define n 999
#define M 999 //deve ser um numero primo
#define O 9999

typedef char Chave[n];
typedef unsigned int peso[n];

typedef struct Item{
	/*outros componentes*/
	Chave chave; 
}Item;
typedef unsigned int Indice;
typedef struct Celula* Apontador;
typedef struct Celula{
	Item item;
	Apontador prox;
}Celula;
typedef struct Lista{
	Celula *primeiro, *ultimo;
}Lista;

typedef Lista Dicionario[M];
Dicionario tabela;
Item elemento;
peso p;
Apontador i;

void inicializar(Dicionario t);
Apontador pesquisar(Chave ch, peso p, Dicionario t);
int vazia(Lista lista);
void criar_lista(Lista *lista);
void ins(Item x, Lista *lista);
void inserir(Item x, peso p, Dicionario t);
void ret(Apontador p, Lista *lista, Item *item);
void retirar(Item x, peso p, Dicionario t);
void imprime(Lista Lista);
int h(Chave chave , peso p);
void gerar_pesos( peso p);