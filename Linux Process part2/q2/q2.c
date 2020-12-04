/*wap to create 
process1->count no of letters from demo.txt file
process2->count no of letters from hello.txt file
write output in count.txt file
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
ret1=fork();
if(ret1==0)
{
	execl("./p1exe","demo.txt",NULL);
}
else
{	
	printf("parent in else of process1...\n");
	printf("processs1 ret :%d\n",ret1);
	printf("process1 pid :%d\n",getpid());
	printf("process1 ppid :%d\n",getppid());
	ret2=fork();
	if(ret2==0)
	{
		execl("./p2exe","hello.txt",NULL);
	}
	else
	{
		printf("parent in else of process2...\n");
		printf("processs2 ret :%d\n",ret2);
		printf("process2 pid :%d\n",getpid());
		printf("process2 ppid :%d\n",getppid());
		ret2=wait(&status);
		printf("process 2 ended with status:%d\n",ret2);	
	}
	ret1=wait(&status);
	printf("process 1 ended with status:%d\n",ret1);
	printf("End of parent process... \n");
}
return 0;
}
