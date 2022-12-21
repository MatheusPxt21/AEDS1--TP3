#include "../Headers/PALAVRA.h"


#define MAX_ListaPalavras 2000

typedef struct{
    TAD_PALAVRA array_word[MAX_ListaPalavras];
    int ptrPRIMEIRO_LP, ptrULTIMO_LP;
}ListaPALAVRAS;


void Cria_LP(ListaPALAVRAS *lista_de_palavras);


int InsereNovaPalavra_LP(ListaPALAVRAS *lista_de_palavras, char *newWORD, int newLINE);


void Imprime_LP(ListaPALAVRAS *lista_de_palavras);

