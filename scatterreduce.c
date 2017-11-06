#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 MPI_Init(NULL,NULL);
 int size,rank;
 MPI_Comm_size(MPI_COMM_WORLD,&size);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 int global[100];
 int local[25];
 int local_sum=0;
 int global_sum=0;
 if(rank==0)
 {
  int i;
  for(i=0;i<100;i++)
  {
   global[i]=1;
  }
 }
 MPI_Scatter(global,25,MPI_INT,local,25,MPI_INT,0,MPI_COMM_WORLD);
  int j;
  for(j=0;j<25;j++)
  {
   local_sum=local_sum+local[j];
  }
  printf("id-%d,sum-%d\n",rank,local_sum);
 MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
 if(rank==0)
 {
  printf("sum:%d",global_sum);
 }
 MPI_Finalize();
}
