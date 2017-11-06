#include <stdio.h>
#include <omp.h>
#include <time.h>

void main(){

	FILE *file;
	clock_t start, end;	

	char text[1000];
	int counter = 0 ;
	int i = 0 ;

	file = fopen("demo.txt","r");
	
	start = clock();
	#pragma do
	while(fgets(text,100,file) != NULL){
		
		int n = strlen(text);
		for(i = 0 ; i < n ; i++){

			if(text[i] == 'b' || text[i]=='b' || text[i]=='c' || text[i]=='d' || text[i]=='f' || text[i]=='g'|| text[i]=='h'|| text[i]=='j'|| text[i]=='k'|| text[i]=='l'|| 				text[i]=='m'|| text[i]=='n'|| text[i]=='p'|| text[i]=='q'|| text[i]=='r'|| text[i]=='s'|| text[i]=='t'|| text[i]=='v'|| text[i]=='w'|| text[i]=='x'|| text[i]=='y'|| text[i]=='z')
			

				counter++;	
			}

	}

	end = clock();

	printf("%d",(int)(end-start));
}
