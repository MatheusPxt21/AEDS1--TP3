#include "../Headers/ListaLINHAS.h"

#define MAX_TAM_PALAVRA 46

typedef struct{
    char *PALAVRA;
    LISTA_LINHAS LINHA_PALAVRA;
}TAD_PALAVRA;

void Inicializa_TADPALAVRA(TAD_PALAVRA *WORD, int Tamanho_da_palavra);
void Preenche_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD, char *palavra);
char* Retorna_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD);
void Imprime_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD);
void Imprime_Caracteres_E_Linhas_TADPALAVRA(TAD_PALAVRA *WORD);
