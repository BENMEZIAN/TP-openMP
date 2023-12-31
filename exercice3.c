#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <time.h>

#define N 100

int main() {
	
    int A[N][N], B[N][N], result[N][N];

    // Initialize matrices A and B (you may use your own initialization logic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i;
            B[i][j] = j;
        }
    }

    #ifdef _OPENMP
    double start_time_static = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic) reduction(+:result[:N][:N])
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_time_static = omp_get_wtime();
    printf("Dynamic schedule time: %f seconds\n", end_time_static - start_time_static);
    #endif

    return 0;
}
