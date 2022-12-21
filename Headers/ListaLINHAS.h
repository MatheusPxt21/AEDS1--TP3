#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_LINHAS 30

typedef struct{
    int LINHA;
}TAD_LINHA;

typedef struct LISTA_LINHAS{
    TAD_LINHA vetor_de_LINHAS[MAX_LINHAS];
    int ptrPRIMEIRO_LINHAS, ptrULTIMO_LINHAS;
}LISTA_LINHAS;

void Inicializa_LISTALINHAS(LISTA_LINHAS *lista_de_linhas);
int VerificaSeEhVazia_LISTALINHAS(LISTA_LINHAS *lista_de_linhas);
int Insere_LISTALINHAS(LISTA_LINHAS *lista_de_linhas, int new_line);
void Imprime_LISTALINHAS(LISTA_LINHAS *lista_de_linhas);
int VerificaSeJaExiste_LISTALINHAS(LISTA_LINHAS *lista_de_linhas, int linha_a_ser_verificada);

