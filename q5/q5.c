/*print priority of current process*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
int main()
{
	//fork() inherits all nice values of parent process
	int which=PRIO_PROCESS;
	//#define PRIO_PROCESS (process identifier)
	//#define PRIO_PGRP 1	(process group identifier)
	//#define PRIO_USER 2	(process user id)
	id_t pid,ppid;
	int ret1,ret2;
	int newpid,newppid;
	printf("process running...\n");
	ppid=getppid();
	pid=getpid();
	ret1=getpriority(which,pid);
	ret2=getpriority(which,ppid);
	printf("PI\tNI\n");
	printf("%d\t%d\n%d\t%d\n\n\n",getppid(),ret2,getpid(),ret1);
	setpriority(which,pid,ret1-5);
	newpid=getpriority(which,pid);
	setpriority(which,ppid,ret2-5);
	newppid=getpriority(which,ppid);
	printf("PI\tNI\n");
	sleep(50);
	printf("%d\t%d\n%d\t%d\n",getppid(),newppid,getpid(),newpid);
	printf("process end..\n");
	return 0;
}
//cmd ps -eo pid,ppid,ni,comm 
//view pid ppid niceness command of a process
