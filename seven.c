#include "omp.h"
#include "stdio.h"

void main(){

	int i, j ;

	int a[50][50], b[50][50];
	for(i = 0 ; i < 50 ; i++){

		for(j = 0 ; j < 50 ; j++){

			a[i][j] = 100 + j ;
			b[i][j] = 50 + j;
		}
	}

	#pragma omp parallel
	{

		int i,j,k,p;
		int result[50][50];
		p = omp_get_thread_num();
		
		#pragma omp for
		for(i = 0 ; i < 50 ; i++){
			for(j = 0 ; j < 50 ; j++){
				for(k = 0 ; k < 50 ; k++){	
				
				result[i][j] += a[i][k] + b[k][j];				
				       
		}
				printf("result[%d][%d] = %d, Thread Id = %d\n", i,j,result[i][j]);			
	}
	
	}		



	}




}
