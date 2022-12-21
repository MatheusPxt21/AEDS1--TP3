#include "../Headers/ListaPALAVRAS.h"


void Cria_LP(ListaPALAVRAS *lista_de_palavras)
{
   
    lista_de_palavras->ptrPRIMEIRO_LP = 0;
    lista_de_palavras->ptrULTIMO_LP = 0;
    

}


int InsereNovaPalavra_LP(ListaPALAVRAS *lista_de_palavras, char *newWORD, int newLINE)
{

    int i;


    for(i = 0; i < lista_de_palavras->ptrULTIMO_LP; i++){
        //se retornar 1 significa que a palavra comparada está na lista;
        if(strcmp(newWORD, lista_de_palavras->array_word[i].PALAVRA) == 0){
            //printf("Essa palavra ja esta na lista %s\n", newWORD);
            if(VerificaSeJaExiste_LISTALINHAS(&lista_de_palavras->array_word->LINHA_PALAVRA, newLINE) == 0){
                Insere_LISTALINHAS(&lista_de_palavras->array_word[i].LINHA_PALAVRA, newLINE); //caso não tenha a linha indicada ela é inserida;
            }
            return 0;
        }
    }

    
    //printf("\n\nEssa palavra NAO esta na lista %s\n", newWORD);
    //caso a palavra não exista na lista:
    int tamanho_da_palavra;
    TAD_PALAVRA T_Palavra;
    tamanho_da_palavra = strlen(newWORD);
    
    Inicializa_TADPALAVRA(&T_Palavra, tamanho_da_palavra);
    Insere_LISTALINHAS(&T_Palavra.LINHA_PALAVRA, newLINE);
    Preenche_Caracteres_TADPALAVRA(&T_Palavra, newWORD);

    lista_de_palavras->array_word[lista_de_palavras->ptrULTIMO_LP] = T_Palavra;

    lista_de_palavras->ptrULTIMO_LP++;


    

}

void Imprime_LP(ListaPALAVRAS *lista_de_palavras)
{

    int i;
    for(i = 0; i<lista_de_palavras->ptrULTIMO_LP; i++){
        Imprime_Caracteres_E_Linhas_TADPALAVRA(&lista_de_palavras->array_word[i]);

    }

}

