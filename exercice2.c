#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif

#define SIZE 100
#define CHUNK 10

int main(){
	
	int tid;
	
	double a[SIZE],b[SIZE],c[SIZE];
	
	for(size_t i=0;i<SIZE;i++){
		a[i] = b[i] = i;
	}
	
	#ifdef _OPENMP
	
		#pragma omp parallel private(tid)
		{
			tid = omp_get_thread_num();
			
			if(tid == 0){
				printf("Nb threads = %d\n",omp_get_num_threads());
			}
			
			printf("Thread %d starting...\n",tid);
			#pragma omp for schedule(static,CHUNK) 
			for(size_t i=0;i<SIZE;i++){
				c[i] = a[i] + b[i];
				printf("Thread %d: c[%2zu] = %g\n",tid,i,c[i]);
			}
		}
		
	#endif
	
	
	return 0;
}