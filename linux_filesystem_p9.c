//write a program which accepts a filename and open that file 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int args,char*argv[])
{
int fd=0;
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("file unable to open\n");
return -1;
}
else
{
printf("file successfully gets open with fd %d",fd);
}
return 0;
} 
