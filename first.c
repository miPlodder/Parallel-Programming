#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 2

void *print1(void *threadid){
	
	int i = 0;
	for(i = 0 ; i < 5000 ; i++ ){
		
		printf("%d\n", i);
	}

}

void *print2(void *threadid){

	int i = 0 ;
	for(i = 5000 ; i < 10000 ; i++){
	
		printf("%d\n", i);

	}
}

int main(){

	pthread_t threads[NUM_THREADS];
	int rc;
	long t = 1;
	printf("Printing Thread 1");
	
	rc = pthread_create(&threads[t], NULL, print1, (void *)t);
	if(rc)
		printf("ERROR, return code from pthread_create() is %d\n",rc);

	t = t + 1;

	printf("Printing Thread 2");
	
	rc = pthread_create(&threads[t], NULL, print2, (void *)t);
	if(rc)
		printf("ERROR, return code from pthread_create() is %d\n", rc);
	
	pthread_exit(NULL);
}

