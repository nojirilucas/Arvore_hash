#include"d_hash_linear.h"

void criar_lista(Lista *lista){
	lista->primeiro = (Apontador) malloc(sizeof(Celula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->prox = NULL;
}
int vazia(Lista lista){
	return ((lista).primeiro == lista.ultimo);
}

void inicializar(Dicionario t){
	int i;
	for(i=0; i<M; i++){
		criar_lista(&t[i]); //função de listas lineares, para iniciar todas as posições do dicionario.
	}
}
Apontador pesquisar(Chave ch, peso p, Dicionario t){
	Indice i;
	Apontador ap;
	i=h(ch,p); //hash das chaves e dos pesos, e descobre o indice.
	if(vazia(t[i])){ //função de listas.
		return NULL; //pesquisa sem sucesso.
	}
	else{
		ap = t[i].primeiro;
		while(ap->prox->prox != NULL && strncmp(ch, ap->prox->item.chave,sizeof(Chave))) {
			ap = ap->prox;
		}
		if(!strncmp(ch, ap->prox->item.chave,sizeof(Chave))){
			return ap;
		}
		else{
			return NULL; //pesquisa sem sucesso.
		}
	}
}
void ins(Item x, Lista *Lista){
	Lista->ultimo->prox = (Apontador) malloc(sizeof(Celula));
	Lista->ultimo = Lista->ultimo->prox;
	Lista->ultimo->item = x;
	Lista->ultimo->prox = NULL;
}
void inserir(Item x, peso p, Dicionario t){
	if(pesquisar(x.chave, p, t) == NULL){
		ins(x, &t[h(x.chave, p)]); //inserir da lista encadeada.
	}
	else{
		printf("Registro ja esta presente\n");
	}
}
void ret(Apontador p, Lista *lista, Item *item){
	Apontador q;
	if (vazia(*lista) || p == NULL || p->prox == NULL) {
		printf(" Erro: Lista vazia ou posicao nao existe\n");
		return;
	}
	q = p->prox;
	*item = q->item;
	p->prox = q->prox;

	if (p->prox == NULL){
		lista->ultimo = p;
	}
	free(q);
}
void retirar(Item x, peso p, Dicionario t){
	Apontador ap;
	ap = pesquisar(x.chave, p, t);
	if(ap == NULL){
		printf("Registro nao esta presente\n");
	}
	else{
		ret(ap,&t[ h(x.chave,p)],&x); //retirar de lista encadeada.
	}
}
void imprime(Lista Lista){
	Apontador Aux;
	Aux = Lista.primeiro->prox;
	while (Aux != NULL) {
		printf("%s\n", Aux->item.chave);
		Aux = Aux->prox;
	}
}
int h(Chave chave , peso p){  //gerar um valor de 0 a m-1. mod é justamente um valor de 0 a m-1.  K%M, K%M se K<M é igual a K.
	unsigned int soma=0;					//evitar numeros primos a partida de 128^i + ou - j
	int comp = strlen(chave);
	for(int i=0; i < comp ;i++){
		soma +=(unsigned int)chave[i] * p[i];
	}
	return (soma % M);
}
void gerar_pesos( peso p){  
	struct timeval semente;
	gettimeofday(&semente,NULL);
	srand((int) (semente.tv_sec + 1000000 * semente.tv_usec) );   //27 min aula 21(20).
	for(int i =0; i< n; i++){
		p[i] = 1+(int) (10000.0 * rand()/(RAND_MAX +1) );
	}
}