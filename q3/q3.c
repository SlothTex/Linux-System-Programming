/*Create a process->Accept one dir name
rename all reg file with sequence no eg 1.txt 2.txt..
*/
#include"header.h"
int main(int argc,char argv[])
{
	int ret1=0,ret2=0,status;
	ret1=fork();
	if(ret1==0)
	{
		execl("./p1exe","eg",NULL);
	}
	else
	{
		printf("parent process running\n");
		ret2=wait(&status);
		printf("child pid:%d\tret2 :%d",getpid(),ret2);
		printf("parent process ends..\n");
	}
return 0;
}
