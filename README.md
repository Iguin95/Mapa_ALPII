Cola de como imprimir um vetor e depois ordena-lo:

#include <stdio.h>
#define MAX 5
int ordenar(int vetor[MAX]);
void imprimir(int vetor[MAX]);

void main(void) {
    int A[MAX] = {8, 5, 9, 4, 15};
    printf("\nVetor Original");
    imprimir(A);
    ordenar(A);
    printf("\nVetor Ordenado");
    imprimir(A);
}
int ordenar(int vetor[MAX])
{
    int i, j, aux;
    for (i=0; i<MAX; i++){
        for (j=0; j<i; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];    
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;    
            }
        }
    }
}
void imprimir(int vetor[MAX]){
    int i;
    for (i=0; i<MAX; i++) printf("\n[%d] = %d", i, vetor[i]);
}
