//accept afile name from user and read that whole file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int args,char*argv[])
{
int fd=0;
char buff[100];
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("file unable to open \n");
}
else
{
printf("file successfully gets opened with fd %d",fd);
}

read(fd,buff,sizeof(buff));
close(fd);
return 0;
}
