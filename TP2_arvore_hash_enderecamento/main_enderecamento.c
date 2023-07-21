#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "enderecamento.h"

int main(){
	FILE *chave = fopen("br-com-trema-latin1.txt","r");
	Dicionario t;
	Item x;
	Peso p;
	int i=0;
	gerar_pesos(p);
	inicializar(t);

	char *line = NULL;
	size_t len, read; 

	while( (read = getline(&line,&len,chave)) != -1 ){
		//x.chave = strdup(line);
		if(i > O){
			break;
		}
		strcpy (x.chave,line);
		inserir(x, p, t);
		i++;
	}
	fclose(chave);

	// for(int i = 0; i < M; i++){
	// 	if(t[i].chave != VAZIO) {
	// 		printf("%s\n",t[i].chave);
	// 	}
	// }
	
	//REMOVER ULTIMA PALAVRA ADICIONADA
	retirar(x.chave, p, t);
	
	// for(int i = 0; i < M; i++){
	// 	if(t[i].chave != VAZIO) {
	// 		printf("%s\n",t[i].chave);
	// 	}
	// }
}