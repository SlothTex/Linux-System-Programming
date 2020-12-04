//create process 1 and process 2 and process 3 internally
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int ret1=0,ret2=0,ret3=0,status1,status2,sret=0;
if((ret1=fork())==0)//child 1
{	
	printf("in process 1 child...\n");
	execl("./myexe1"," ",NULL);
}
else//parent
{
 if ((ret2=fork())==0)//child 2
 {
 	printf("in process 2 child...\n");
	execl("./myexe2"," ",NULL);
 }
 else //parent
 {
 	if ((ret3=fork())==0)//child 3
 	{
 		printf("in process 3 child...\n");
		execl("./myexe3"," ",NULL);
 	}
 	else//parent
 	{	
 		printf("parent process 3 running...\n");
		//sret=wait(&status1);
		//printf("parent 3 end with status:%d\n",sret);
		printf("parent process 3 end with pid %d\tppid 	%d\tret3 %d\n",getpid(),getppid(),ret3);
 	}
 	printf("parent process 2 running...\n");
	//sret=wait(&status1);
	//printf("parent 3 end with status:%d\n",sret);
	printf("parent process 2 end with pid %d\tppid %d\tret2 %d\n",getpid(),getppid(),ret2);
 }
printf("parent process 1 running...\n");
//sret=wait(&status2);
//printf("parent 2 end with status:%d\n",sret);
printf("parent process 1 end with pid %d\tppid %d\tret1 %d\n",getpid(),getppid(),ret1);
}
return 0;
}
