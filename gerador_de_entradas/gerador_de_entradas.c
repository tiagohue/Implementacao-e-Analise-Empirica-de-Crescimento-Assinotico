#include <stdio.h>
#include <stdlib.h>

void main() {
    FILE *entrada_csv = fopen("entrada.csv", "w");
    fclose(entrada_csv);

    FILE *entrada_csv_a = fopen("entrada.csv", "a");

    for(long int i = 10; i <= 10000; i += 50) {
        for(long int j = 0; j < i; j++) {
            long int n_rand = rand()%100 + 1;
            if(j == 0)
                fprintf(entrada_csv_a, "%li", n_rand);
            else
                fprintf(entrada_csv_a, ",%li", n_rand);
        }
        fprintf(entrada_csv_a, "\n");
        printf("Gerando a entrada com n = %li\n", i);
    }

    printf("Gerou tudo \n");

    fclose(entrada_csv_a);
}