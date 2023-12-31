#include <stdio.h>
#include <omp.h>

#define num_steps 10000000

int main() {
    double step = 1.0 / num_steps;
    double sum_critical = 0.0;
    double sum_reduction = 0.0;
    double x;

    // Version 1: Utiliser la clause critical pour calculer la somme
    #pragma omp parallel for private(x) shared(step)
    for (int i = 0; i < num_steps; i++) {
        double x = (i + 0.5) * step;
        double partial_sum = 4.0 / (1.0 + x * x);
        
        #pragma omp critical
        sum_critical += partial_sum;
    }

    double pi_critical = step * sum_critical;
    printf("Approximation of pi using critical: %f\n", pi_critical);

    // Version 2: Utiliser la clause reduction pour calculer la somme
    #pragma omp parallel for private(x) reduction(+:sum_reduction)
    for (int i = 0; i < num_steps; i++) {
        double x = (i + 0.5) * step;
        sum_reduction += 4.0 / (1.0 + x * x);
    }

    double pi_reduction = step * sum_reduction;
    printf("Approximation of pi using reduction: %f\n", pi_reduction);

    return 0;
}
