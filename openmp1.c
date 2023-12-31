#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif


int main(int argc,char* argv[]){
	
	int tid;
	
	#ifdef _OPENMP
		
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				tid = omp_get_thread_num();
				printf("Hello (%d)\n",tid);
			}
			
			#pragma omp section
			{
				tid = omp_get_thread_num();
				printf("World (%d)\n",tid);
			}
		}
	}
	#endif
	
	
	return 0;	
}