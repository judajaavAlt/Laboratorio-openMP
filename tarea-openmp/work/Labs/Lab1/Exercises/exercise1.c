#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads(10)
    {
        int thread_num = omp_get_thread_num();
        if (thread_num % 2 == 0)
        {
            printf("Hello from thread %d, i'm an even thread\n", thread_num);
        }
        else
        {
            printf("Hello from thread %d, i'm an odd thread\n", thread_num);
        }
    }
    return 0;
}