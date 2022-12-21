#include "../Headers/PALAVRA.h"

void Inicializa_TADPALAVRA(TAD_PALAVRA *WORD, int Tamanho_da_palavra)
{

    WORD->PALAVRA = (char*)malloc(Tamanho_da_palavra * sizeof(char));

    Inicializa_LISTALINHAS(&WORD->LINHA_PALAVRA);

}
void Preenche_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD, char *palavra)
{

    strcpy(WORD->PALAVRA, palavra);


}
char* Retorna_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD)
{

    return WORD->PALAVRA;


}
void Imprime_Caracteres_TADPALAVRA(TAD_PALAVRA *WORD)
{

    printf("\n-----------------------------------------\n");
    printf("Palavra: %s\n", WORD->PALAVRA);


}
void Imprime_Caracteres_E_Linhas_TADPALAVRA(TAD_PALAVRA *WORD)
{

    Imprime_Caracteres_TADPALAVRA(WORD);
    Imprime_LISTALINHAS(&WORD->LINHA_PALAVRA);

}