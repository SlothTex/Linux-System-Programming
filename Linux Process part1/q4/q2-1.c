//process 2 n internal process 3
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int ret1=0,ret2=0,status1,status2,sret=0;
printf("in process 1 child...\n");
ret1=fork();
if(ret1==0)
{	
	printf("in process 2 child...\n");
	execl("./myexe2"," ",NULL);
}
else
{
 if ((ret2=fork())==0)
 {
 	printf("in process 3 child...\n");
	execl("./myexe3"," ",NULL);
 }
 else
 {
 	printf("parent process 3 running...\n");
	sret=wait(&status1);
	printf("parent 3 end with status:%d\n",sret);
 }
printf("parent process 2 running...\n");
sret=wait(&status2);
printf("parent 2 end with status:%d\n",sret);
}
return 0;
}
