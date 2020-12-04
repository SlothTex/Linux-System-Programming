/*WAP which create a one child process.Wait till the child process ends*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int ret=0,status,sret=0;
ret=fork();
if(ret==0)
{
	execl("./myexe"," ",NULL);
}
else
{
printf("parent process running...\n");
sret=wait(&status);
printf("parent end with status:%d\n",sret);
}
}
