#include<stdio.h>
#include<pthread.h>
#define NUM_THREAD 2

void *print1(void *threadid){

	int i;
	for(i = 2 ; i < 500 ; i++){
		
		int j;
		int counter = 0 ;
		for(j = 2; j <= i/2 ; j++){

			if(i%j==0){
			
				counter++;
			}		
			
		}
		
		if(counter == 0)
			printf("%d\n",i);
	
	}



}


void *print2(void *threadid){

	int i ;
	for(i = 0 ; i < 5000; i++){

		if(i%2 == 0)
			printf("%d\n",i);	

	}

}

int main(){

	pthread_t thread[NUM_THREAD];
	int rc ;
	int t = 0 ;
	
	rc = pthread_create(&thread[t], NULL, print1, (void *)t);
	if(rc)
		printf("ERROR, return code from pthread_create() is %d\n",rc);

	t = t + 1;
	
	printf("Printing EVEN Numbers\n");
	rc = pthread_create(&thread[t], NULL, print2, (void *)t);
	if(rc)
		printf("ERROR, return code from pthread_create() is %d\n",rc);

	pthread_exit(NULL);



}
