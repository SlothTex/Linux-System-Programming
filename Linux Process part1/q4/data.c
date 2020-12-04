#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
printf("child process 2 running with pid %d\n",getpid());
return 0;
}
