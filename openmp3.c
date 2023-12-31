#include <stdio.h>
#include <unistd.h> // for sleep
#ifdef _OPENMP
#include <omp.h>
#endif

int main(int argc, char *argv[]) {
    
    int tid;
    int a = 5; // private
    
    #ifdef _OPENMP
    
        #pragma omp parallel private(a)
        {
            #pragma omp sections 
            {
                #pragma omp section
                {
                    tid = omp_get_thread_num();
                    a += 5;
                    printf("Thread %d: a = %d\n", tid, a);
                    sleep(1); // Delay to slow down execution
                }
                
                #pragma omp section
                {
                    tid = omp_get_thread_num();
                    printf("Thread %d: a = %d\n", tid, a);
                    sleep(1); // Delay to slow down execution
                }
            }
        }
        
    #endif
    
    return 0;
}
