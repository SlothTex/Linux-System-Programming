/*wap to create a deamon proccess*/
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/fs.h>
int main(int argc,char *argv[])
{
pid_t pid;
int i;
//create a process
pid=fork();
if(pid==-1)
{
	return -1;
}
//create a new session and process group
if(setsid()==-1)
{
	return -1;
}
//set working dir to root dir
if(chdir("/")==-1)
{
return -1;
}
//close all open files--NR_OPEN is overkill
for(i=0;i< NR_OPEN;i++)
close(i);
//redirect fd's 0,1,2 to /dev/null
open("/dev/null",O_RDONLY);//stdin
dup(0);//stdout
dup(0);//stderr
return 0;
}
