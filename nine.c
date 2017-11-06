#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

clock_t t;
t = clock();
int r = 1000;
int c = 1000;
int i=0;
int j=0;
int **matrix1 = (int **)malloc(r*sizeof(int *));
for(i=0;i<=r;i++)
{
matrix1[i] = (int *)malloc(c * sizeof(int));
}
int **matrix3 = (int **)malloc(r*sizeof(int *));
for(i=0;i<=r;i++)
{
matrix3[i] = (int *)malloc(c * sizeof(int));
}
for(i=0;i<=r;i++)
{
for(j=0;j<=c;j++)
{
matrix1[i][j] = i*j;
}
}
for(i=0;i<=r;i++)
{
for(j=0;j<=c;j++)
{
matrix3[i][j] = i*j;
}
}
FILE *f = fopen("file1.txt","wb");
for(i=0;i<=r;i++)
{fprintf(f,"\n");
for(j=0;j<=c;j++)
{
fprintf(f,"%d\t",matrix1[i][j]);
}}
fclose(f);
FILE *fn = fopen("file2.txt","wb");
for(i=0;i<=r;i++)
{fprintf(fn,"\n");
for(j=0;j<=c;j++)
{
fprintf(fn,"%d\t",matrix3[i][j]);
}
}
//fwrite(matrix1, sizeof(int),sizeof(matrix1), f);
fclose(fn);
int **matrix2 = (int **)malloc(r*sizeof(int *));
for(i=0;i<=r;i++)
{
matrix2[i] = (int *)malloc(c * sizeof(int));
}
int **matrix4 = (int **)malloc(r*sizeof(int *));
for(i=0;i<=r;i++)
{
matrix4[i] = (int *)malloc(c * sizeof(int));
}
FILE *ifp = fopen("file1.txt","rb");
for(i=0;i<=r;i++)
{fscanf(ifp,"\n");
for(j=0;j<=c;j++)
{
fscanf(ifp,"%d\t",&matrix2[i][j]);
}
}
fclose(ifp);
FILE *ifp2 = fopen("file1.txt","rb");
for(i=0;i<=r;i++)
{fscanf(ifp,"\n");
for(j=0;j<=c;j++)
{
fscanf(ifp2,"%d\t",&matrix4[i][j]);
}
}
fclose(ifp);
int k =0;
int **matrix5 = (int **)malloc(r*sizeof(int *));
for(i=0;i<=r;i++)
{
matrix5[i] = (int *)malloc(c * sizeof(int));
}
for(i=0;i<=r;i++)
{
for(j=0;j<=c;j++)
{
matrix5[i][j] = matrix2[i][j]+matrix4[i][j];}
}
FILE *fnn = fopen("result.txt","wb");
for(i=0;i<=r;i++)
{fprintf(fnn,"\n");
for(j=0;j<=c;j++)
{
fprintf(fnn,"%d\t",matrix5[i][j]);
}
}
t = clock() - t;
double time_taken = ((double)t)/CLOCKS_PER_SEC;
printf("Program took %f seconds to execute matrix of size %d",time_taken,r);
}
