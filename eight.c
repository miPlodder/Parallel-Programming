#include "stdio.h"
#include "omp.h"
#include "string.h"

#define MAX_CHAR 1000

int main(){

	FILE *fp;
	char buffer[255];
	char text[10000];
	char search[7] = "Saksham";

	fp = fopen("demo.txt", "r");
	if(fp == NULL){
	
	printf("File not Found");
	return 0;
	}

	while(fgets(buffer, MAX_CHAR, fp) != NULL){

		strcat(text,buffer);
	}

	int result = 0;

	#pragma omp parallel
	{

		int i = 0 ;
		int max = sizeof(text);
		int counter = 0 ;		

		for(i = 0 ; i < max ; i++){

			if(text[i] == search[counter]){

				counter++;
				if(counter == sizeof(search)){
					
					result = result + 1;
					counter = 0 ;
									
				}
			}else{
				counter = 0;
			}


		}


	}

	printf("Occurances are %d", result);

}
