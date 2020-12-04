//wp to create 1kb hole in the file
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char*argv[])
{
int fd=0,temp=0,ret=0;
char name[300],fn[300];
if(argc!=2)
{
	printf("Inavlid input");
	return -1;
}
fd=open(argv[1],O_RDWR);
ret=lseek(fd,100,SEEK_CUR);
write(fd,"Milind nalawade",15);
close(fd);
return 0;
}
