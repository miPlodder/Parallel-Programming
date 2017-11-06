#include<stdio.h>

int main(int argc, char** argv){

	FILE *f1, *f2;

	char text[256], ch;

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "w");
	
	//fgets(text, 256, f1); 
   	//printf("String read from file new.txt: %s\n", text);    
	//fclose(f1); 	

	while(true){

		ch = fgetc(f1);

		if(ch == EOF){
			break;
		}	

		fputc(ch, f2);
		
	}
	
	fclose(f1);
	fclose(f2);
}
