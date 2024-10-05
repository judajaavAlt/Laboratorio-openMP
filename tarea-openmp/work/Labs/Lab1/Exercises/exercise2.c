#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int avg;

    
    #pragma omp parallel for reduction(max:max) \
        reduction(min:min) reduction(+:avg) num_threads(100)
        for (i = 0; i < 100; i++)
        {    
            Array[i] = rand() % 10000;
            max = Array[i];
            min = Array[i];
            avg = Array[i];
        }
    avg /= 100;

    //imprime el resultado
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %d\n", avg);

    return 0;
}