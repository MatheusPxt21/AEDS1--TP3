#include "../Headers/Ordenacoes.h"

int Bubble_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX){

    
    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;

    Cria_LP(VAR_AUX);

    int size = var->ptrULTIMO_LP;

    for(int i = 0; i < size; i++){
        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);
    }
    
    
   
    for(int i = 0;i<size-1;i++){
        for(int j = 0;j<size-1;j++){
            contadorCOMPARACOES += 1;
            if(strcmp(VAR_AUX->array_word[j].PALAVRA,VAR_AUX->array_word[j+1].PALAVRA)>0){
                char *temp = (char*) malloc(strlen(var->array_word[j].PALAVRA)*sizeof(char));
                strcpy(temp,VAR_AUX->array_word[j].PALAVRA);
                strcpy(VAR_AUX->array_word[j].PALAVRA,VAR_AUX->array_word[j+1].PALAVRA);                
                strcpy(VAR_AUX->array_word[j+1].PALAVRA,temp);

                contadorMOVIMENTACOES += 1;

            }
        }
    }

    for(int i = 0;i<size;i++){
    
        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);
        
    }

    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0],contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0], contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");

    return contadorMOVIMENTACOES;
}

void Selection_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX){

    
    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;

    Cria_LP(VAR_AUX);

    int size = var->ptrULTIMO_LP,Min;
    

    for(int i = 0; i < size; i++){
        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);
    }

    for(int i = 0;i<size-1;i++){
        Min = i;
        for(int j = i+1;j<size;j++){
            contadorCOMPARACOES += 1;
            if(strcmp(VAR_AUX->array_word[j].PALAVRA,VAR_AUX->array_word[Min].PALAVRA)<0){
                Min = j;
            }
        }
        char *temp = (char*)malloc(strlen(VAR_AUX->array_word[Min].PALAVRA) * sizeof(char));
        strcpy(temp,VAR_AUX->array_word[Min].PALAVRA);
        strcpy(VAR_AUX->array_word[Min].PALAVRA,VAR_AUX->array_word[i].PALAVRA);
        strcpy(VAR_AUX->array_word[i].PALAVRA,temp);

        contadorMOVIMENTACOES += 1;
        
    }

    for(int i = 0;i<size;i++){

        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);

    }

    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0],contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0], contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");


}

void Insertion_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX){

    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;

    Cria_LP(VAR_AUX);

    int size = var->ptrULTIMO_LP, j;

    for(int i = 0; i < size; i++){
        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);
    }

    for(int i = 1;i<size;i++){
        char *temp = (char*)malloc(strlen(VAR_AUX->array_word[i].PALAVRA) * sizeof(char));
        strcpy(temp,VAR_AUX->array_word[i].PALAVRA);
        j = i - 1;
        while((j>=0)&&(((strcmp(temp,VAR_AUX->array_word[j].PALAVRA))<0))){
            contadorCOMPARACOES += 1;
            strcpy(VAR_AUX->array_word[j+1].PALAVRA,VAR_AUX->array_word[j].PALAVRA);
            contadorMOVIMENTACOES += 1;
            j--;
        }
        strcpy(VAR_AUX->array_word[j+1].PALAVRA,temp);
        contadorMOVIMENTACOES += 1;
    }

    for(int i = 0;i<size;i++){

        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);

    }

    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0],contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0], contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");

}

void ShellSort_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX){

    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;

    Cria_LP(VAR_AUX);

    int size = var->ptrULTIMO_LP;
    int h = 1, j;

    for(int i = 0; i < size; i++){
        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);
    }

    do h = h*3 +1; while(h<size);
    do{
        h = h/3;
        for(int i = h; i < size; i++){

            char *temp = (char*) malloc(strlen(VAR_AUX->array_word[i].PALAVRA)*sizeof(char));
            strcpy(temp,VAR_AUX->array_word[i].PALAVRA);
            j = i;
            while(strcmp(VAR_AUX->array_word[j-h].PALAVRA,temp)>0){
                contadorCOMPARACOES += 1;
                strcpy(VAR_AUX->array_word[j].PALAVRA,VAR_AUX->array_word[j-h].PALAVRA);
                contadorMOVIMENTACOES += 1;
                j -= h;
                if(j<h){
                    break;
                }
            }
            strcpy(VAR_AUX->array_word[j].PALAVRA,temp);
            contadorMOVIMENTACOES += 1;

        }

    }while(h!=1);

    for(int i = 0; i < size; i++){

        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);

    }

    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0],contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0], contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");

}


void Participacao_QuickSort(int esq,int dir,int *i,int *j,ListaPALAVRAS *var, int *COMPARACOES, int *MOVIMENTACOES){

    *i = esq;
    *j = dir;
    char *pivo = (char*) malloc(strlen(var->array_word[((*i+*j)/2)].PALAVRA)*sizeof(char)) ;
    strcpy(pivo,var->array_word[((*i+*j)/2)].PALAVRA);
    do{
        
        while((strcmp(pivo,var->array_word[*i].PALAVRA))>0){
            (*COMPARACOES) += 1;
            (*i)++;
        }
        while((strcmp(var->array_word[*j].PALAVRA,pivo))>0){
            (*COMPARACOES) += 1;
            (*j)--; 
        }
      
        if(*i<=*j){

            char *aux = (char*) malloc(strlen(var->array_word[(*i)].PALAVRA)*sizeof(char)) ;
            strcpy(aux,var->array_word[*i].PALAVRA);
            strcpy(var->array_word[*i].PALAVRA,var->array_word[*j].PALAVRA);
            strcpy(var->array_word[*j].PALAVRA,aux);
            (*MOVIMENTACOES) += 1;
            (*i)++;
            (*j)--;
        }
    }while(*i<=*j);

}

void Ordena_QuickSort(int esq,int dir,ListaPALAVRAS *var, int *COMPARACOES, int *MOVIMENTACOES){
    
    int i,j;
    Participacao_QuickSort(esq,dir,&i,&j,var, COMPARACOES, MOVIMENTACOES);
    if(esq<j)
        Ordena_QuickSort(esq,j,var, COMPARACOES, MOVIMENTACOES);
    if(i<dir)
        Ordena_QuickSort(i,dir,var, COMPARACOES, MOVIMENTACOES);
    
}

void QuickSort_ORDENACAO(ListaPALAVRAS *var,ListaPALAVRAS *VAR_AUX){
    
    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;

    Cria_LP(VAR_AUX);
    int size = var->ptrULTIMO_LP;
    for(int i = 0;i<size;i++){

        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);

    }

    Ordena_QuickSort(0,size-1,VAR_AUX, &contadorCOMPARACOES, &contadorMOVIMENTACOES);

    for(int i = 0;i<size;i++){

        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);

    }

    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0],contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a lista de letra [%c] =================: %d\n", VAR_AUX->array_word->PALAVRA[0], contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");

    
}


void Refaz_HeapSort(int esq,int dir,ListaPALAVRAS *VAR_AUX, int *COMPARACOES, int *MOVIMENTACOES){

    int j = esq * 2;
    char *aux = (char*) malloc(strlen(VAR_AUX->array_word[j].PALAVRA)*sizeof(char));
    (*MOVIMENTACOES) += 1;
    strcpy(aux,VAR_AUX->array_word[esq].PALAVRA);
    while(j<=dir){
        (*COMPARACOES) += 1;
        if((j<dir)&&((strcmp(VAR_AUX->array_word[j].PALAVRA,VAR_AUX->array_word[j+1].PALAVRA))<0)) j++;
        (*COMPARACOES) += 1;
        if((strcmp(aux,VAR_AUX->array_word[j].PALAVRA))>0)break;
        strcpy(VAR_AUX->array_word[esq].PALAVRA,VAR_AUX->array_word[j].PALAVRA);
        (*MOVIMENTACOES) += 1;
        esq = j;
        j = esq*2;
    }
    strcpy(VAR_AUX->array_word[esq].PALAVRA,aux);
    (*MOVIMENTACOES) += 1;

}

void Constroi(ListaPALAVRAS *VAR_AUX,int *n, int *COMPARACOES, int *MOVIMENTACOES){

    int esq;
    esq = *n / 2 + 1;
    while(esq>1){

        esq--;
        
        Refaz_HeapSort(esq,*n,VAR_AUX, COMPARACOES, MOVIMENTACOES);

    }

}

void Heapsort_ORDENACAO(ListaPALAVRAS *var,ListaPALAVRAS *VAR_AUX){
    
    int contadorMOVIMENTACOES = 0, contadorCOMPARACOES = 0;
    
    Cria_LP(VAR_AUX);
    int dir = var->ptrULTIMO_LP,esq = 1;
    
    InsereNovaPalavra_LP(VAR_AUX,"----",0);
    //ignora a primeira posicao
    for(int i = 0;i<var->ptrULTIMO_LP;i++){

        InsereNovaPalavra_LP(VAR_AUX,var->array_word[i].PALAVRA,0);
        
    }
    Constroi(VAR_AUX,&dir, &contadorCOMPARACOES, &contadorMOVIMENTACOES);
    while(dir>1){
        char *aux = (char*) malloc(strlen(VAR_AUX->array_word[1].PALAVRA)*sizeof(char));
        
        strcpy(aux,VAR_AUX->array_word[1].PALAVRA);
        strcpy(VAR_AUX->array_word[1].PALAVRA,VAR_AUX->array_word[dir].PALAVRA);
        strcpy(VAR_AUX->array_word[dir].PALAVRA,aux);
        dir--;
        Refaz_HeapSort(esq,dir,VAR_AUX, &contadorCOMPARACOES, &contadorMOVIMENTACOES);

    }

    for(int i = 1;i<var->ptrULTIMO_LP+1;i++){
        Imprime_Caracteres_TADPALAVRA(&VAR_AUX->array_word[i]);
       
    }

    
    printf("\n\n------------------------------------------------------------\n");
    printf("\n| Movimentacoes para a esta letra  =================: %d\n", contadorMOVIMENTACOES);
    printf("\n|   Comparacoes para a esta letra  =================: %d\n", contadorCOMPARACOES);
    printf("\n------------------------------------------------------------\n");

}
