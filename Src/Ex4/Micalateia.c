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
//RETORNA UM PONTEIRO PARA UM NÓ EM DETERMINADO INDICE 
element * atPos(element * LISTA, int index){
	int c= 0;
	element * percorre = LISTA;

	while(percorre!=NULL){
		if(c==index){
			return percorre;
		}
		percorre = percorre-> prox;
		c++;
	}
}

//RETORNA O INDICE DE DETERMINADO NÓ
int indexOf(element * LISTA, element * Node){
	int c=0;
	while(LISTA != NULL){
		if(LISTA == Node) return c;
		LISTA = LISTA->prox;
		c++;
	}
}

//TROCA DOIS NÓS DE POSICAO
void node_swipe(element * LISTA, element * nodeA, element * nodeB){
	if(nodeA == nodeB) return;
	int indexA = indexOf(LISTA, nodeA); // INDEX NÓ A
	int indexB = indexOf(LISTA, nodeB); // INDEX NÓ B

	// PONTEIRO PARA O NÓ ANTERIOR AO A
	element * pa = atPos(LISTA, indexA-1); 
	// PONTEIRO PARA O NÓ ANTERIOR AO B
	element * pb = atPos(LISTA, indexB-1);

	pa->prox = nodeB; //ANTERIOR DE A APONTA PARA B
	pb->prox = nodeA; //ANTERIOR DE B APONTA PARA A

	element * aux = nodeA->prox; //SALVA O ENDEREÇO NO QUE A APONTA
	nodeA->prox = nodeB->prox; //A APONTA PARA O PROX DE B
	nodeB->prox = aux; //B APONTA PARA O PROX DE A
}

//BUBBLE SORT
void lista_ordena(element * LISTA){
	int i, j;
	int size = lista_size(LISTA);

	for(i = 0 ; i < size-1; i++){
		for(j = 0 ; j < size -i -1 ; j++){
			element * nodeJ = atPos(LISTA, j+2);
			element * nodeI = atPos(LISTA, j+1);
			if(nodeI->ligacoes < nodeJ->ligacoes){
				node_swipe(LISTA, nodeI, nodeJ);
			}
		}	
	}

}


int main(){
	element * LISTA = lista_inicia();
	lista_insere(LISTA, (char *)"Hermanoteu", (char *)"4523-2248", 300);
	lista_insere(LISTA, (char *)"Oolonéia", (char *)"4523-4887", 299);

	while(1){
		char op;
		char nome[20], tel[10];
		int qntLigacoes;

		scanf(" %c", &op);
		if(op == 'F'){
			lista_ordena(LISTA);
			//printf("\n\n");
			lista_imprime(LISTA);
			return 0;	
		} 
		else if(op == 'L'){
			scanf(" %s", nome);
			lista_liga(LISTA, nome);
		}
		else if(op == 'I'){
			scanf(" %s", nome);
			scanf(" %s", tel);
			scanf(" %d", &qntLigacoes);
			lista_insere(LISTA, nome, tel, qntLigacoes);
		}
		else if(op == 'R'){
			scanf("%s", nome);
			lista_remove(LISTA, nome);
		}
		else printf("OPÇÃO ERRADA!\n");
	}


}
