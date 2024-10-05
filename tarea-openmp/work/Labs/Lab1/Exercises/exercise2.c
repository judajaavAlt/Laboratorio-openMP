#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int avg;

    //rellena el array
    #pragma omp parallel for num_threads(100)
        for (i = 0; i < 100; i++)
        {    
        Array[i] = rand() % 10000;
        }

    //busca el maximo
    #pragma omp parallel for reduction(max:max) num_threads(100)
        for (i = 0; i < 100; i++)
        {
            max = Array[i];
        }

    //busca el minimo
    #pragma omp parallel for reduction(min:min) num_threads(100)
        for (i = 0; i < 100; i++)
        {
            min = Array[i];
        }

    //busca el promedio
    #pragma omp parallel for reduction(+:avg) num_threads(100)
        for (i = 0; i < 100; i++)
        {
            avg = Array[i];
        }
    avg /= 100;

    //imprime el resultado
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %d\n", avg);

    return 0;
}