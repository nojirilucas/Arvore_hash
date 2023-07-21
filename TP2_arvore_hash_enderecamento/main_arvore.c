#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "arvore.h"

int main(){
	FILE *chave = fopen("br-com-trema-latin1.txt","r");
	Dicionario T = NULL;

	int i = 0;
	inicializar(&T);

	Registro r1;
	r1.chave = 5;
	r1.nome = "RAIZ";

	inserir(r1,&T);

	Registro r2;
	
	char *line = NULL;
	size_t len, read; 

	while( (read = getline(&line,&len,chave)) != -1 ){
		//x.chave = strdup(line);
		if(i > M ){
			break;
		}
		r2.chave = i;
		r2.nome = line;
		inserir(r2,&T);
		i++;
	}
	fclose(chave);

	pesquisar(&r2,T);
	retirar(r2,&T); //Retirando o registro 2
	pesquisar(&r2,T); //Pesquisando se o registro 2 ainda existe na arvore
	
}