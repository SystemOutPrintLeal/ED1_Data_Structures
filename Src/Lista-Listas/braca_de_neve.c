#include <stdio.h>
#include <stdlib.h>

typedef int Color;


typedef struct Element{
    Color color;
    struct Element* next;

} Anao_toca;

typedef Anao_toca* Anoes_t;


int inserir_a(Anoes_t* d, Color c){

    Anao_toca** anao = (Anao_toca**) d;

    while(*anao)
        anao = (Anao_toca**) &(*anao)->next;

    Anao_toca* new_dwarf = (Anao_toca*)  malloc(sizeof(Anao_toca));
    if(!new_dwarf) return -1;

    new_dwarf->color = c;
    new_dwarf->next = NULL;

    *anao = new_dwarf;

    return 0;
}

int FrequenciaDaCor(Anoes_t d, int start, int end, int numb_colors, unsigned int* mostFrequentColor){
    int i;
    int colorsCounter[numb_colors];


    for(i = 0; i < numb_colors; i++)
        colorsCounter[i] = 0;

    i = 1;
    while(d && i <= end)
    {
        if(i >= start)
        {
            colorsCounter[d->color - 1]++;
        }
        d = d->next;
        i++;
    }

    int mfc = 0;

    for(i = 0; i < numb_colors; i++)
    {
        if(colorsCounter[i] > mfc)
        {
            *mostFrequentColor = i + 1;
            mfc = colorsCounter[i];
        }
    }


    return mfc;
}

int killDwarfs(Anoes_t* d){

    Anao_toca** anao = (Anao_toca**) d;
    Anao_toca* dw;

    while(*anao)
    {
        dw = *anao;
        anao = (Anao_toca**) &(*anao)->next;
        free(dw);

    }

    *d = NULL;
}


int main(){

    Anoes_t d = NULL;

    unsigned int t, i, c, m, most_frequent_color;
    unsigned int start, end;
    int cd, numb_dwarfs, numb_colors;

    scanf("%u", &t);

    while(t--)
    {
        scanf("%d %d", &numb_dwarfs, &numb_colors);

        for(i = 0; i < numb_dwarfs; i++)
        {
            scanf("%u", &c);
            inserir_a(&d, c);
        }

        scanf("%u", &m);

        while(m--)
        {
            scanf("%u %u", &start, &end);
            cd = FrequenciaDaCor(d, start, end, numb_colors, &most_frequent_color);

            cd > (end - start + 1)/2 ? printf("bonita %u\n", most_frequent_color) : printf("feia\n");

        }
        killDwarfs(&d);

    }

    return 0;
}
