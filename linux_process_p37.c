//accept a file and offset from user and delete all content from that offset
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char*argv[])
{
int fd=0,ret=1,ret1=0,pos=0;
char name[300];
fd=open(argv[1],O_RDWR);
if(argc!=3)
{
	printf("ERROR: Invalid input.\n Format: ./a.out file_name postion");
	return -1;
}
if(fd==-1)
{
printf("cannot open the file\n");
return -1;
}
pos=atoi(argv[2]);
ret=lseek(fd,pos,SEEK_CUR);
ret1=ftruncate(fd,ret);
if(ret1==-1)
{
printf("File cannot be updated");
return -1;
}
close(fd);
return 0;
}
