/*WAP which creates
process1->create process2->internally create process2 and wait for all the child process to terminate before there parent
*/
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
	execl("./myexe1"," ",NULL);
}
else
{
printf("parent process 1 running...\n");
sret=wait(&status);
printf("parent process 1  end with status:%d\n",sret);
}
}
