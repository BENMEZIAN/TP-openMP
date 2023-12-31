#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif


int main(int argc,char* argv[]){
	
	int tid;
	int a = 5; // patagée
	
	#ifdef _OPENMP
	
		#pragma omp parallel
		{
			#pragma omp sections
			{
				#pragma omp section
				{
					tid = omp_get_thread_num();
					printf("Hello (%d)\n",tid);
					a+=5;
					printf("a = %d\n",a);
				}
				
				#pragma omp section
				{
					tid = omp_get_thread_num();
					printf("Hello (%d)\n",tid);
					printf("a = %d\n",a);
				}
			}
		}
		
	#endif
	
	
	return 0;
}