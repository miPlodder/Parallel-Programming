#include "omp.h"
#include "stdio.h"

void main(){

int i, j ;
int a[500][500];
int b[500][500];

for(i = 0 ; i < 500 ; i++){

	for(int j = 0 ; j < 500 ; j++){

		a[i][j] = 100 + j ;
		b[i][j] = 50 + j ;
	}
}

#pragma omp parallel
{

int i, j , p;
int c[500][500];

#pragma omp for

for(i = 0 ; i < 500 ; i++){
	for(j = 0 ; j < 500 ; j++){
	
	p = omp_get_thread_num();

	c[i][j] = a[i][j] + b[i][j];
	
	printf("c[%d][%d] = %d \t thread id:%d\n",i,j,c[i][j],p);
	}
}

}


}

