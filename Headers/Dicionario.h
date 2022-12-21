#include "../Headers/Ordenacoes.h"

typedef struct Celula_Dicionario* Apontador_Dicionario;

typedef struct Celula_Dicionario{
    ListaPALAVRAS LP_DIC;
    char Letra_que_inicia_a_palavra;
    Apontador_Dicionario ptrPROX;
}TCelula_Dicionario;

typedef struct{
    Apontador_Dicionario ptrPRIMEIRO, ptrULTIMO;
}DICIONARIO;

void Inicializa_DICIONARIO(DICIONARIO *dictionary);

void Cria_DICIONARIO(DICIONARIO *dictionary, char *nome_do_arquivo_de_entrada);

ListaPALAVRAS* Insere_Nova_Lista_DICIONARIO(DICIONARIO *dicionary, char letra);

Apontador_Dicionario Verifica_Lista_DICIONARIO(DICIONARIO *dictionary, char letra);

void InserePalavra_DICIONARIO(DICIONARIO *dictionary, char *palavra_a_ser_inserida, int linha_da_palavra_a_ser_inserida);

void DESORDENADOImprimeTUDO_DICIONARIO(DICIONARIO *dictionary);
void DESORDENADOImprimeDeterminadaLetra_DICIONARIO(DICIONARIO *dictionary, char letra);

void ORDENADOImprimeTUDO_DICIONARIO(DICIONARIO *dictionary, int Resposta_Ordenacao);
void ORDENADOImprimeDeterminadaLetra_DICIONARIO(DICIONARIO *dictionary, char letra, int Resposta_Ordenacao);