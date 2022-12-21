#include "../Headers/Dicionario.h"

void Inicializa_DICIONARIO(DICIONARIO *dictionary)
{

   dictionary->ptrPRIMEIRO = (Apontador_Dicionario)malloc(sizeof(TCelula_Dicionario));
   dictionary->ptrULTIMO = dictionary->ptrPRIMEIRO;
   dictionary->ptrPRIMEIRO->ptrPROX = NULL;
   dictionary->ptrPRIMEIRO->Letra_que_inicia_a_palavra = 0; 


}

void Cria_DICIONARIO(DICIONARIO *dictionary, char *nome_do_arquivo_de_entrada)
{
    
    FILE *arquivo;
    arquivo = fopen(nome_do_arquivo_de_entrada, "rt");

    if(arquivo == NULL){
        printf("\nErro na abertura do arquivo!!!\n");
        printf("\nTente novamente: \n");
        return;
    }
    else{
        int line = 1; //inicializa a linha em 1 já que o arquivo txt começa com linha = 1
        char palavra[MAX_TAM_PALAVRA], caractere;
        while(!feof(arquivo)){
            
            caractere = fgetc(arquivo);

            if(caractere == '\n'){
                line++;
            }

            fscanf(arquivo, "%s", palavra);

            InserePalavra_DICIONARIO(dictionary, palavra, line);
            

        }
    }

    fclose(arquivo);

}

ListaPALAVRAS* Insere_Nova_Lista_DICIONARIO(DICIONARIO *dicionary, char letra)
{

    ListaPALAVRAS aux_lp;
    ListaPALAVRAS *LP;
    Cria_LP(&aux_lp);
    Apontador_Dicionario Auxiliar_ordenacao, Auxiliar_endereco;

    if(Verifica_Lista_DICIONARIO(dicionary, letra) != 0){
        //printf("ja existe");
        return 0;
    }
    else{
        if(dicionary->ptrPRIMEIRO == dicionary->ptrULTIMO){
            dicionary->ptrPRIMEIRO->ptrPROX = (Apontador_Dicionario)malloc(sizeof(TCelula_Dicionario));
            dicionary->ptrULTIMO = dicionary->ptrPRIMEIRO->ptrPROX;
            dicionary->ptrULTIMO->ptrPROX = NULL;
            dicionary->ptrULTIMO->LP_DIC = aux_lp;
            LP = &dicionary->ptrULTIMO->LP_DIC;

        }
        else if(letra < dicionary->ptrPRIMEIRO->ptrPROX->Letra_que_inicia_a_palavra){
            Auxiliar_ordenacao = dicionary->ptrPRIMEIRO->ptrPROX;
            dicionary->ptrPRIMEIRO->ptrPROX = (Apontador_Dicionario)malloc(sizeof(TCelula_Dicionario));
            dicionary->ptrPRIMEIRO->ptrPROX->ptrPROX = Auxiliar_ordenacao;
            dicionary->ptrPRIMEIRO->ptrPROX->LP_DIC = aux_lp;
            dicionary->ptrPRIMEIRO->ptrPROX->Letra_que_inicia_a_palavra = letra;
            LP = &dicionary->ptrPRIMEIRO->ptrPROX->LP_DIC;
        }
        else{
            Auxiliar_ordenacao = dicionary->ptrPRIMEIRO;
            while(Auxiliar_ordenacao->ptrPROX && letra > Auxiliar_ordenacao->ptrPROX->Letra_que_inicia_a_palavra){
                Auxiliar_ordenacao = Auxiliar_ordenacao->ptrPROX;
            }

            Auxiliar_endereco = Auxiliar_ordenacao->ptrPROX;
            Auxiliar_ordenacao->ptrPROX = (Apontador_Dicionario)malloc(sizeof(TCelula_Dicionario));
            Auxiliar_ordenacao->ptrPROX->ptrPROX = Auxiliar_endereco;
            Auxiliar_ordenacao->ptrPROX->LP_DIC = aux_lp;
            Auxiliar_ordenacao->ptrPROX->Letra_que_inicia_a_palavra = letra;
            LP = &Auxiliar_ordenacao->ptrPROX->LP_DIC;
        }

        return LP;
    }
    

}

Apontador_Dicionario Verifica_Lista_DICIONARIO(DICIONARIO *dictionary, char letra)
{

    Apontador_Dicionario ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO;
    ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO = dictionary->ptrPRIMEIRO->ptrPROX;

    while(ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO != NULL){
        if(ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO->Letra_que_inicia_a_palavra == letra){
            return ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO;
        }

        ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO = ptrAUXILIAR_PERCORRER_DICIONARIO_VERIFICACAO->ptrPROX;

    }

    return 0;


}

void InserePalavra_DICIONARIO(DICIONARIO *dictionary, char *palavra_a_ser_inserida, int linha_da_palavra_a_ser_inserida)
{
    if(Verifica_Lista_DICIONARIO(dictionary, palavra_a_ser_inserida[0]) == 0){
        //se a lista com a determinada letra nao existe, a lista é criada e a palavra inserida posteriormente
        InsereNovaPalavra_LP(Insere_Nova_Lista_DICIONARIO(dictionary, palavra_a_ser_inserida[0]), palavra_a_ser_inserida, linha_da_palavra_a_ser_inserida);
    }
    else{
        //caso a lista com a determinada letra exista a palavra é inserida na lista que foi localizada
        InsereNovaPalavra_LP(&Verifica_Lista_DICIONARIO(dictionary, palavra_a_ser_inserida[0])->LP_DIC, palavra_a_ser_inserida, linha_da_palavra_a_ser_inserida);
    }
}

void DESORDENADOImprimeTUDO_DICIONARIO(DICIONARIO *dictionary)
{

    Apontador_Dicionario ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO;

    ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO = dictionary->ptrPRIMEIRO->ptrPROX;

    while(ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO != NULL){

        printf("\n=========================================================================\n");
        printf("\tLetra: %c\n", ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->Letra_que_inicia_a_palavra);
        Imprime_LP(&ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->LP_DIC);
        printf("\n=========================================================================\n\n");


        ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO = ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->ptrPROX;
    }


}
void DESORDENADOImprimeDeterminadaLetra_DICIONARIO(DICIONARIO *dictionary, char letra)
{
    Apontador_Dicionario ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO;

    ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO = dictionary->ptrPRIMEIRO->ptrPROX;

    while(ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO != NULL){

        if(ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->Letra_que_inicia_a_palavra == letra){
            printf("\n\t===================================================\n");
            printf("\tLetra: %c\n", letra);
            Imprime_LP(&ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->LP_DIC);
            printf("\n\t===================================================\n\n");

            return;
        }

        ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO = ptrAUXILIAR_PERCORRE_DIC_IMPRESSAO->ptrPROX;

    }
    //caso nao ocorra o return significa que nao existe lista com tal letra e o algoritmo passará por aqui
    printf("A letra nao foi encontrada na lista");

}

void ORDENADOImprimeTUDO_DICIONARIO(DICIONARIO *dictionary, int Resposta_Ordenacao)
{
    int contador_Media_Movimentacoes = 0, divisor_para_o_calculo_da_media_de_movimentacoes = 0;
    float Media_movimentacoes;

    clock_t tempoINICIAL_ORDENACAO_COMPLETA, tempoFINAL_ORDENACAO_COMPLETA, tempoTOTAL_ORDENACAO_COMPLETA;


    ListaPALAVRAS Copia_da_Lista_de_Palavras_Para_Ordenacao;
    Apontador_Dicionario ptrAUX;

    ptrAUX = dictionary->ptrPRIMEIRO->ptrPROX;


    tempoINICIAL_ORDENACAO_COMPLETA = clock();
    while(ptrAUX != NULL){

        switch (Resposta_Ordenacao)
        {
            case 1:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                contador_Media_Movimentacoes += Bubble_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                break;
            
            case 2:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                Selection_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                
                break;
            
            case 3:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                Insertion_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                break;

            case 4:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                ShellSort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                break;

            case 5:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                Heapsort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                break;

            case 6:
                printf("\n========================================\n");
                printf("LETRA: [%c]\n", ptrAUX->Letra_que_inicia_a_palavra);
                QuickSort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                printf("\n-----------------------------------------\n");
                printf("========================================\n");
                break;
            
            default:
                break;
        }
        
        ptrAUX = ptrAUX->ptrPROX;
    }

    tempoFINAL_ORDENACAO_COMPLETA = clock();
    tempoTOTAL_ORDENACAO_COMPLETA = ((tempoFINAL_ORDENACAO_COMPLETA - tempoINICIAL_ORDENACAO_COMPLETA) / (CLOCKS_PER_SEC / 1000));


    printf("\n\nTempo total gasto no processo de ORDENACAO: %3.ld segundos\n", tempoTOTAL_ORDENACAO_COMPLETA);

    for(int i = 0; i<ptrAUX->LP_DIC.ptrULTIMO_LP; i++){
        divisor_para_o_calculo_da_media_de_movimentacoes += 1;
    }

    printf("\n%d \n", contador_Media_Movimentacoes);
    Media_movimentacoes = contador_Media_Movimentacoes / divisor_para_o_calculo_da_media_de_movimentacoes;
    printf("\nA media de movimentacoes para essa ordenacao foi: %.2f\n", Media_movimentacoes);

}
void ORDENADOImprimeDeterminadaLetra_DICIONARIO(DICIONARIO *dictionary, char letra, int Resposta_Ordenacao)
{
    
    clock_t tempoINICIAL_ORDENACAO_LISTA, tempoFINAL_ORDENACAO_LISTA, tempoTOTAL_ORDENACAO_LISTA;

    tempoINICIAL_ORDENACAO_LISTA = clock();

    Apontador_Dicionario ptrAUX;

    ptrAUX = dictionary->ptrPRIMEIRO->ptrPROX;

    while(ptrAUX != NULL){

        if(ptrAUX->Letra_que_inicia_a_palavra == letra){
            ListaPALAVRAS Copia_da_Lista_de_Palavras_Para_Ordenacao;


            printf("\n=========================================================================\n");
            printf("\tLetra: [%c]\n", letra);
            switch (Resposta_Ordenacao)
            {
                case 1:
                    Bubble_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;
                
                case 2:
                    Selection_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;
                
                case 3:
                    Insertion_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;

                case 4:
                    ShellSort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;

                case 5:
                    Heapsort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;

                case 6:
                    QuickSort_ORDENACAO(&ptrAUX->LP_DIC, &Copia_da_Lista_de_Palavras_Para_Ordenacao);
                    break;
                
                default:
                    break;
            }
            printf("\n=========================================================================\n\n");

            
            tempoFINAL_ORDENACAO_LISTA = clock();
            tempoTOTAL_ORDENACAO_LISTA = ((tempoFINAL_ORDENACAO_LISTA - tempoINICIAL_ORDENACAO_LISTA) / (CLOCKS_PER_SEC / 1000));

            printf("\n\nTempo total gasto no processo de ORDENACAO: %.3ld segundos\n", tempoTOTAL_ORDENACAO_LISTA);
            return;
        }

        ptrAUX = ptrAUX->ptrPROX;

    }
    //caso nao ocorra o return significa que nao existe lista com tal letra e o algoritmo passará por aqui
    printf("A letra nao foi encontrada na lista");

}
