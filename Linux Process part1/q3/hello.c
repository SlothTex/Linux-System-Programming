#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
printf("child process 3 running with pid %d\tppid %d\n",getpid(),getppid());
return 0;
}
