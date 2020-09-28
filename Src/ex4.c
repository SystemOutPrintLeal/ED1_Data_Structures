#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element{
	int ligacoes;
	char nome[20], tel[10];
	struct Element * prox;
};

typedef struct Element element;

element * lista_inicia();
void lista_liga(element * LISTA, char * nome);
void lista_insere(element * LISTA, const char * nome, const char * numero, int qnt);
void lista_remove(element * LISTA, char * nome);
void lista_imprime(element * LISTA);
element * atPos(element * LISTA, int index);
void node_swipe(element * LISTA, element * nodeA, element * nodeB);
int indexOf(element * LISTA, element * Node);
void lista_ordena(element * LISTA);

//INICIA UM NÓ APONTANDO PARA NULL
element * lista_inicia(){
	element * LISTA = (element*)malloc(sizeof(element));
	if(!LISTA){
		printf("Não alocada!\n");
		exit(1);
	}
	LISTA->prox = NULL;
	return LISTA;
}

//AUMENTA UM NAS LIGACOES DO NÓ EM QUE HÁ O NOME
void lista_liga(element * LISTA, char * nome){
	element * percorre = LISTA->prox;
	while(percorre!=NULL){
		if(strcmp(percorre->nome, nome) == 0){
			percorre->ligacoes++;
			break;
		}
		percorre = percorre->prox;
	}
}
//INSERE NA LISTA
void lista_insere(element * LISTA, const char * nome, const char * numero, int qnt){
	element * percorre = LISTA;
	element * novo = lista_inicia();

	while(percorre->prox != NULL) percorre = percorre->prox;

	percorre->prox = novo;
	memcpy(novo->nome, nome, strlen(nome)+1);
	memcpy(novo->tel, numero, strlen(numero)+1);
	novo->ligacoes = qnt;
}

//REMOVE DA LISTA
void lista_remove(element * LISTA, char * nome){
	element * atual = LISTA->prox;
	element * anterior = LISTA;

	while(atual!=NULL){
		if(strcmp(atual->nome, nome)==0){
			anterior->prox = atual->prox;
			free(atual);
			break;
		}
		anterior = atual;
		atual = atual -> prox;
	}
}

//IMPRIME LISTA
void lista_imprime(element * LISTA){
	element * percorre = LISTA->prox;

	while(percorre!=NULL){
		printf("%s - %s\n", percorre->nome, percorre->tel);
		percorre = percorre->prox;
	}
}

//RETORNA O TAMANHO DA LISTA
int lista_size(element * LISTA){
	int c=0;
	while(LISTA->prox!=NULL){
		LISTA = LISTA->prox;
		c++;
	}
	return c;
}