//wap to accept a file name and mode fron user and open that file in that mode
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int args,char*argv[])
{
int fd=0,mode=0;

if(strcmp(argv[2],"read")==0)
{
mode =O_RDONLY;
}
else if(strcmp(argv[2],"write")==0)
{
mode = O_WRONLY;
}
else if(strcmp(argv[2],"read_write")==0)
{
mode = O_RDWR;
}
else if(strcmp(argv[2],"create")==0)
{
mode = O_CREAT;
}
else if(strcmp(argv[2],"truncate")==0)
{
mode = O_WRONLY|O_TRUNC;
}

fd=open(argv[1],mode);
if(fd==-1)
{
printf("unable to open the file\n");
return -1;
}
else
{
printf("file opened successfully with fd %d and mode %s\n",fd,argv[2]);
}
return 0;
}

