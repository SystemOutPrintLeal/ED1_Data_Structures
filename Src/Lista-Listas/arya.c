#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef  int boolean;

boolean final = FALSE;

typedef struct Elemento{

    int id;
    struct Elemento* link;

} Elemento_t;



typedef Elemento_t* Lista;

Lista arya = NULL;
void Iniciar(int p, int e, boolean init){

    Elemento_t* novo_elemento;

    if(arya == NULL)
    {
        novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));

        novo_elemento->id = p;
        novo_elemento->link = NULL;

        arya = novo_elemento;

        if(!init) printf("inserido %d\n", p);
        return;
    }

    Elemento_t* atual = (Elemento_t*) arya;

        while(atual)
        {

           if(atual->id == e)
           {

                novo_elemento = (Elemento_t*) malloc(sizeof(Elemento_t));

                novo_elemento->id = p;
                novo_elemento->link = atual->link;

                atual->link = novo_elemento;
                if(!init) printf("inserido %d\n", p);
                return;
           }

           atual = atual->link;
        }

        return;
};



void Remove(int p){

    Elemento_t* anterior = NULL;
    Elemento_t* atual = (Elemento_t*) arya;

    while(atual != NULL && atual->id != p){

        anterior = atual;
        atual = atual->link;

    }


    if(atual->id==p){


        if(anterior == NULL){
            arya = atual->link;
            free(atual);
            printf("removido %d\n", p);
        }else{
            anterior->link = atual->link;
            free(atual);
            printf("removido %d\n", p);
        }

    }


}



void C(int a, int b){
    Elemento_t* elemento = (Elemento_t*) arya;

    int distancia = 0;
    int e = 0;


    while(elemento)
    {
        if(a == elemento->id || b == elemento->id)
            e++;

        e && distancia++ ;

        if( e >= 2)
            break;


        elemento = elemento->link;
    }

    printf("quantidade %d\n", distancia - 2);

}


void M(){
    if(!arya)
        printf("lista vazia");
    else
        printf("lista ");

    Elemento_t* e = (Elemento_t*) arya;

    while(e)
    {
        printf("%d ", e->id);
        e = e->link;
    }
    printf("\n");


}


void F(){

    final = TRUE;
    printf("fim");

}


int main(){

    int n, p, e, i = 0;


    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &p);
        Iniciar(p, i, TRUE);
        i = p;
    }

    char funcao;
    int p1, p2;

    while(!final)
    {
        scanf("%c", &funcao);

        switch (funcao)
        {
            case 'F':
                F();
                break;
            case 'R':
                scanf("%d", &p1);
                Remove(p1);
                break;
            case 'I':
                scanf("%d %d", &p1, &p2);
                Iniciar(p1, p2, FALSE);
                break;
            case 'C':
                scanf("%d %d", &p1, &p2);
                C(p1, p2);
                break;
            case 'M':
                M();
            default:
                break;
        }

    }




    return 0;
}
