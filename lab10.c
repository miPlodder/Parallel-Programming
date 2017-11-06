#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(){
	
	int pid ;
	int number ;
	
	MPI_Init(NULL,NULL);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	if(pid == 0){

		number = 10;
		MPI_Send(&number, 1, MPI_INT, 1, 0 , MPI_COMM_WORLD);
	}

	if(pid == 1){

		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("%d",number);
	}	
	
	MPI_Finalize();

}
