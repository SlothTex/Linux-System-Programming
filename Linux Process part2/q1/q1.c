/*WAP to 
create a process->create a demo.txt file->write all file names present on desktop in demo.txt file
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(int argc,char *argv[])
{
 int ret1=0,ret2=0,status;
 if((ret1=fork())==0)
 {
 	execl("myexe"," ",NULL);
 }
 else
 {
 	printf("parent process is running ret:%d\n",ret1);
 	printf("child pid:%d\n",getpid());
 	ret2=wait(&status);
 	printf("child terminated with ret:%d\n",ret2);
 	printf("parent process end");
 }
 return 0;
}
