#include"stdio.h"
#include"pthread.h"

int arr[100];
int p = -1;
void* push(){
for (int i =0;i<1000;i++){
if(p<1000){
p++;
arr[p] = i;
printf("%d pushed.\n",i);
}
else{
i--;
}
}
}
void* pop(){
for (int j=0;j<1000;j++){
if(p>=0){printf("%d poped.\n",arr[p]);
p--;
}
else{
j--;
}
}
}
int main(){
pthread_t pushThread, popThread;
pthread_create(&pushThread, NULL, push, NULL);
pthread_create(&popThread, NULL, pop, NULL);
pthread_join(pushThread, NULL);
pthread_join(popThread, NULL);
return 0;
}
