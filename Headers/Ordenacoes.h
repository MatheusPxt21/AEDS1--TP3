#include "../Headers/ListaPALAVRAS.h"

void ShellSort_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX);
int Bubble_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX);
void Selection_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX);
void Insertion_ORDENACAO(ListaPALAVRAS *var, ListaPALAVRAS *VAR_AUX);

void QuickSort_ORDENACAO(ListaPALAVRAS *var,ListaPALAVRAS *VAR_AUX);
void Ordena_QuickSort(int esq,int dir,ListaPALAVRAS *var, int *COMPARACOES, int *MOVIMENTACOES);
void Participacao_QuickSort(int esq,int dir,int *i,int *j,ListaPALAVRAS *var, int *COMPARACOES, int *MOVIMENTACOES);

void Refaz_HeapSort(int esq,int dir,ListaPALAVRAS *VAR_AUX, int *COMPARACOES, int *MOVIMENTACOES);
void Constroi(ListaPALAVRAS *VAR_AUX,int *n, int *COMPARACOES, int *MOVIMENTACOES);
void Heapsort_ORDENACAO(ListaPALAVRAS *var,ListaPALAVRAS *VAR_AUX);