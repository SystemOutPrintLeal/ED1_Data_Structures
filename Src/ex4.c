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