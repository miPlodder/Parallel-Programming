#include<pthread.h>
#include<stdio.h>

void *thread(void *threadid){


}

int main(){

	int rc = 0 ;
	int counter = 0 ;
	pthread_t tid ;	
	
	while(rc == 0){	
		
		rc = pthread_create(&tid, NULL, thread, NULL);
		counter++;

	}
		
	printf("Maximum number of thread are %d", counter);

}
