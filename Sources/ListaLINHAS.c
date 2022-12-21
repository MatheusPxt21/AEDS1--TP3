#include "../Headers/ListaLINHAS.h"

void Inicializa_LISTALINHAS(LISTA_LINHAS *lista_de_linhas)
{
    lista_de_linhas->ptrPRIMEIRO_LINHAS = 0;
    lista_de_linhas->ptrULTIMO_LINHAS = 0;
}
int VerificaSeEhVazia_LISTALINHAS(LISTA_LINHAS *lista_de_linhas)
{
    if(lista_de_linhas->ptrULTIMO_LINHAS = 0){
        return 1; //se for vazia retorna 1
    }
}
int Insere_LISTALINHAS(LISTA_LINHAS *lista_de_linhas, int new_line)
{
    if(lista_de_linhas->ptrULTIMO_LINHAS >= MAX_LINHAS){
        puts("\nErro!\nNumero maximo de linhas atingido\n");
        return 0; //se a posição ultimo for igual ao maximo permitido não insere uma nova linha;
    }

    lista_de_linhas->vetor_de_LINHAS[lista_de_linhas->ptrULTIMO_LINHAS].LINHA = new_line;

    lista_de_linhas->ptrULTIMO_LINHAS++;


    return 1;
}
void Imprime_LISTALINHAS(LISTA_LINHAS *lista_de_linhas)
{
    int i;
    for(i = 0; i<lista_de_linhas->ptrULTIMO_LINHAS; i++){
        printf("%d ", lista_de_linhas->vetor_de_LINHAS[i].LINHA);
    }
}


int VerificaSeJaExiste_LISTALINHAS(LISTA_LINHAS *lista_de_linhas, int linha_a_ser_verificada)
{
    int i;

    
    for(i = 0; i < lista_de_linhas->ptrULTIMO_LINHAS; i++){
        if(lista_de_linhas->vetor_de_LINHAS[i].LINHA == linha_a_ser_verificada){
            return 1;
        }
    }

    return 0;
    


}