#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxchar 30

struct Element
{
    char nomeNeto[maxchar], sentido[maxchar];
    struct Element *prox;
};

typedef struct Element element;

element *IniciaLista()
{
    element *Neto = (element *)malloc(sizeof(element));
    if (!Neto)
    {
        printf("Não alocada!\n");
        return NULL;
    }
    Neto->prox = NULL;
    return Neto;
}

void InsereLista(element *Neto, char *Nome)
{
    element *percorre = Neto;
    element *novoNeto = IniciaLista();

    while (percorre->prox != NULL)
        percorre = percorre->prox;

    percorre->prox = novoNeto;
    memcpy(novoNeto->nomeNeto, Nome, strlen(Nome) + 1);
}

void main()
{

    element *Neto = IniciaLista();
}