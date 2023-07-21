#include "enderecamento.h"

void inicializar(Dicionario t) {
int i;
	for (i = 0; i < M; i++)
		memcpy(t[i].chave, VAZIO, n);
}

Apontador pesquisar(Chave chave, Peso p, Dicionario t) {
unsigned int i = 0;
unsigned int inicial;	
inicial = h(chave, p);
	while (strcmp(t[(inicial + i) % M].chave,VAZIO) != 0 &&
		strcmp(t[(inicial + i) % M].chave, chave) != 0 &&
		i < M)
		i++;
		if (strcmp(t[(inicial + i) % M].chave, chave) == 0){
			return ((inicial + i) % M);
		}
		else{
			return M; /* pesquisa sem sucesso */
		}
}

void inserir(Item x, Peso p, Dicionario t) {
unsigned int i = 0;
unsigned int inicial;
	if (pesquisar(x.chave, p, t) < M) {
		printf("Elemento ja esta presente\n");
		return;
	}
	inicial = h(x.chave, p);
	while ( strcmp ( t[(inicial + i) % M].chave,VAZIO) != 0 &&
		strcmp ( t[(inicial + i) % M].chave, RETIRADO) != 0 && i < M)
			i++;
	if (i < M) {
		strcpy (t[(inicial + i) % M].chave, x.chave);
	/* Copiar os demais campos de x, se existirem */
	}
	else{
		printf(" Tabela cheia\n");
	}
	
}

void retirar(Chave chave, Peso p, Dicionario t) {
Indice i;
	i = pesquisar(chave, p, t);
	if (i < M){
		memcpy(t[i].chave, RETIRADO, n);
	}
	else{
		printf("Registro nao esta presente\n");
	}
}
int h(Chave chave , Peso p){  //gerar um valor de 0 a m-1. mod é justamente um valor de 0 a m-1.  K%M, K%M se K<M é igual a K.
	unsigned int soma=0;					//evitar numeros primos a partida de 128^i + ou - j
	int comp = strlen(chave);
	for(int i=0; i < comp ;i++){
		soma +=(unsigned int)chave[i] * p[i];
	}
	return (soma % M);
}
void gerar_pesos( Peso p){  
	struct timeval semente;
	gettimeofday(&semente,NULL);
	srand((int) (semente.tv_sec + 1000000 * semente.tv_usec) );
	for(int i =0; i< n; i++){
		p[i] = 1+(int) (10000.0 * rand()/(RAND_MAX +1) );
	}
}