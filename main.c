#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int vetor[], long int tam_vetor);
void merge_sort(int vetor[], long int p, long int r);
void intercala(int vetor[], long int p, long int q, long int r);
void imprimir_vetor(int vetor[], long int tam_vetor);

const long int NUM_BEM_ALTO = 100000;
const long int TAM_MAX_VETOR = 100000;

void main(){
    FILE *dados_csv = fopen("dados.csv", "w");

    fprintf(dados_csv, "entrada, t_insertion, t_merge\n");

    for(long int tam_vetor = 10; tam_vetor <= TAM_MAX_VETOR; tam_vetor += 50) {
        printf("fazendo para um vetor com n = %li\n", tam_vetor);
        fprintf(dados_csv, "%li, ", tam_vetor);

        int vetor_insertion[tam_vetor];
        int vetor_merge[tam_vetor];

        // popula o vetor
        for(long int j = 0; j < tam_vetor; j++) {
            vetor_insertion[j] = rand()%100 + 1;
            vetor_merge[j] = vetor_insertion[j];
        }

        // insertion sort
        clock_t t_insertion = clock();
        insertion_sort(vetor_insertion, tam_vetor);
        t_insertion = clock() - t_insertion;
        fprintf(dados_csv, "%li, ", t_insertion);

        // merge sort
        clock_t t_merge = clock();
        merge_sort(vetor_merge, 0, tam_vetor - 1);
        t_merge = clock() - t_merge;
        fprintf(dados_csv, "%li\n", t_merge);
    }

    printf("execucao finalizada!\n");
    fclose(dados_csv);
}

void insertion_sort(int vetor[], long int tam_vetor){
    for (long int j = 1; j < tam_vetor; j++){
        int chave = vetor[j];

        long int i = j - 1;
        while (i > -1 && vetor[i] > chave){
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }

        vetor[i + 1] = chave;  
    }
}

void merge_sort(int vetor[], long int p, long int r){
    if (p < r){
        long int q = (p + r)/2;
        merge_sort(vetor, p, q);
        merge_sort(vetor, q + 1, r);
        intercala(vetor, p, q, r);
    }
}

void intercala(int vetor[], long int p, long int q, long int r){
    long int n1 = q - p + 1;
    long int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];

    for (long int i = 0; i < n1; i++)
        L[i] = vetor[p + i];

    for (long int j = 0; j < n2; j++)
        R[j] = vetor[q + j + 1];
    
    L[n1] = R[n2] = NUM_BEM_ALTO;

    long int i = 0, j = 0;

    for (long int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            vetor[k] = L[i];
            i = i + 1;
        } else{
            vetor[k] = R[j];
            j = j + 1;
        }
    }
    
}

void imprimir_vetor(int vetor[], long int tam_vetor){
    for (long int i = 0; i < tam_vetor; i++){
        if(i == 0)
            printf("%i", vetor[i]);
        else
            printf(", %i", vetor[i]);
    }
    printf("\n");
}