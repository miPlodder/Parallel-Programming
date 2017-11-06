#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(){


	int pid;
	char *ch;

	MPI_Init(NULL, NULL);

		MPI_Comm_rank(MPI_COMM_WORLD, &pid);
		if(pid == 0){
			
			strcpy(ch, "saksham");
			printf("%c", ch);
			MPI_Send(&ch, 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
	
		}

		if(pid == 1){


			MPI_Recv(ch, 1, MPI_CHAR, 0 , 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%c", ch);
		
		}


	MPI_Finalize();

	return 0;
}

