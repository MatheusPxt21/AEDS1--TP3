#include "../Headers/Menu.h"


void Menu()
{   
    DICIONARIO Dictionary;
    Inicializa_DICIONARIO(&Dictionary);
    int repete = 1;


    int resposta_do_menu, resposta_tipo_de_ordenacao, respostaBubble;

    char nome_do_arquivo_de_texto[arquivotexto], letra_desejada;

    while(repete){

        printf("\n\t ==============================================================\n");
        printf("\t ||Selecione a opcao desejada:                               ||\n");
        printf("\t ||  ------------------------------------------------------- ||\n");
        printf("\t ||1 -- Criar Dicionario ----------------------------------- ||\n");
        printf("\t ||2 -- Imprimir Dicionario Completo Desordenadamente ------ ||\n");
        printf("\t ||3 -- Imprimir Dicionario Completo Ordenadamente --------- ||\n");
        printf("\t ||4 -- Imprimir Lista de Determinada Letra Desordenadamente ||\n");
        printf("\t ||5 -- Imprimir Lista de Determinada Letra Ordenadamente -- ||\n");
        printf("\t ||6 -- Encerrar programa ---------------------------------- ||\n");
        printf("\t ==============================================================\n\n");


        scanf("%d", &resposta_do_menu);
        
        switch (resposta_do_menu)
        {
        case 1:
            printf("\n\tOpcao de CRIACAO do Dicionario selecionada:\n");
            printf("Insira o nome completo do arquivo de texto (finalizando com .txt) que contem o texto:\n");
            setbuf(stdin, 0);
            scanf("%s", nome_do_arquivo_de_texto);

            Cria_DICIONARIO(&Dictionary, nome_do_arquivo_de_texto);       
            
            break;
        
        case 2:
            printf("\n\tOpcao de Impressao DESORDENADA do Dicionario selecionada:\n");

            DESORDENADOImprimeTUDO_DICIONARIO(&Dictionary);

            break;
        
        case 3:
            printf("\n\tOpcao de Impressao ORDENADA do Dicionario selecionada:\n");
            printf("Insira o tipo de ordenacao que deseja realizar:\n");

            printf("\n\t =================================\n");
            printf("\t ||Selecione a opcao desejada:  ||\n");
            printf("\t ||  -------------------------- ||\n");
            printf("\t ||1 -- Bubblesort ------------ ||\n");
            printf("\t ||2 -- Selection Sort -------- ||\n");
            printf("\t ||3 -- Insertion Sort -------- ||\n");
            printf("\t ||4 -- Shellsort ------------- ||\n");
            printf("\t ||5 -- Heapsort -------------- ||\n");
            printf("\t ||6 -- Quicksort ------------- ||\n");
            printf("\t ===============================\n\n");

            scanf("%d", &resposta_tipo_de_ordenacao);

            if(resposta_tipo_de_ordenacao == 1){
                printf("Voce tem certeza do que esta fazendo?!\n");
                printf("\t|1| - Sim, continuar com o BubbleSort\n");
                printf("\t|2| - Nao, so achei o nome legal ¯|_(ツ)_/¯\n");
                scanf("%d", &respostaBubble);
                if(respostaBubble == 1){
                    printf("\n\tEu avisei...\n");
                    
                }
                else{
                    break;
                }
                
            }

            ORDENADOImprimeTUDO_DICIONARIO(&Dictionary, resposta_tipo_de_ordenacao);

            


            break;
        
        case 4:
            printf("\n\tOpcao de Impressao de LISTA DESORDENADA selecionada:\n");
            printf("Insira a letra que deseja visualizar no dicionario:\n");
            setbuf(stdin, 0);
            scanf("%c", &letra_desejada);

            DESORDENADOImprimeDeterminadaLetra_DICIONARIO(&Dictionary, letra_desejada);

            break;

        case 5:

            printf("\n\tOpcao de Impressao de LISTA ORDENADA selecionada:\n");
            printf("Insira a letra que deseja visualizar no dicionario:\n");
            setbuf(stdin, 0);
            scanf("%c", &letra_desejada);

            printf("Insira o tipo de ordenacao que deseja realizar:\n");

            printf("\n\t =================================\n");
            printf("\t ||Selecione a opcao desejada:  ||\n");
            printf("\t ||  -------------------------- ||\n");
            printf("\t ||1 -- Bubblesort ------------ ||\n");
            printf("\t ||2 -- Selectio Sort --------- ||\n");
            printf("\t ||3 -- Insertion Sort -------- ||\n");
            printf("\t ||4 -- Shellsort ------------- ||\n");
            printf("\t ||5 -- Heapsort -------------- ||\n");
            printf("\t ||6 -- Quicksort ------------- ||\n");
            printf("\t ===============================\n\n");

            scanf("%d", &resposta_tipo_de_ordenacao);

            if(resposta_tipo_de_ordenacao == 1){
                printf("Voce tem certeza do que esta fazendo?!\n");
                printf("\t|1| - Sim, continuar com o BubbleSort\n");
                printf("\t|2| - Nao, so achei o nome legal ¯|_(ツ)_/¯\n");
                scanf("%d", &respostaBubble);
                if(respostaBubble == 1){
                    printf("\n\tEu avisei...\n");
                    
                }
                else{
                    break;
                }
            }

            ORDENADOImprimeDeterminadaLetra_DICIONARIO(&Dictionary, letra_desejada, resposta_tipo_de_ordenacao);

            break;
        
        case 6:
            printf("\nEncerrando o programa\n");
            printf(".\n");
            printf(".\n");
            printf(".\n");
            repete = 0;
            break;
        
        default:
            printf("\nOpcao Invalida, \nTente Novamente\n\n");
            break;
        }

    }
}