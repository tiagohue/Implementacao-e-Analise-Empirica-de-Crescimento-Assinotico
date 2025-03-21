#include <stdio.h>
#include <stdlib.h>

int calcular_tamanho_vetor() {

}

void main(){
    FILE* entrada_csv;
    char buffer[4];

    int tam_vetor = 0;

    if ((entrada_csv = fopen("../gerador_de_entradas/entrada.csv", "r")) != NULL){
        do{
            fread(buffer, sizeof(char), 3, entrada_csv);

            tam_vetor++;
        } while (buffer[2] != '\n');

        fclose(entrada_csv);
    } else
        perror("Erro ao ler o arquivo com as entradas");


    int vetor[tam_vetor];
    int index = 0;
    if ((entrada_csv = fopen("../gerador_de_entradas/entrada.csv", "r")) != NULL) {
        
        do{
            fread(buffer, sizeof(char), 3, entrada_csv);

            vetor[index] = atoi(buffer);
            index++;
        } while (buffer[2] != '\n');

        fclose(entrada_csv);
    } else
        perror("Erro ao ler o arquivo com as entradas");

    printf("%i", vetor[0]);
}