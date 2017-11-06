#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define BUF_SIZE 100
void main(void)
{
int i=0;
char buf[BUF_SIZE];
while(fork()>0){i++;
}
printf("%d\n",i);
}
