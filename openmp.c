#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif


int main(){
	
	int tid;
	
	#ifdef _OPENMP
	
	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		printf("Hello du thread (%d)\n",tid);
	}
	
	#endif
	
	
	return 0;	
}