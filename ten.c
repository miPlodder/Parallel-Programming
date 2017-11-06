#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

void main(){

	int matrix[1000][1000];
	int i, j ;
	clock_t start, end ;
	for(i = 0 ; i < 1000 ; i++){
		for(j = 0 ; j < 1000 ; j++){
		
			matrix[i][j] = (rand()%1000000);
		}
	}

	int sum = 0 ;
	
	start = clock();

	//#pragma omp parallel for 
	#pragma omp parallel for collapse(2)
	//#pragma omp parallel for reduction(+:sum) collapse(2)
	for( i = 0 ; i < 1000 ; i++){
		for(j = 0 ; j < 1000 ; j++){
			
			sum += matrix[i][j];
		}
	}
	
	end = clock();
	printf("%f",(double)(end - start));
			

}
