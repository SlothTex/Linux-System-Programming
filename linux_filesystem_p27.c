//accept file name and position and read 2 byes from that postion
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char*argv[])
{
int fd=0,pos=0,ret=0;
char name[300],buff[100];
if (argc!=3)
{
printf("InvalidInput\n Format: ./myexe  file_name postion");
return -1;
}
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("cannot open the file %s\n",argv[1]);
return -1;
}
pos=atoi(argv[2]);
lseek(fd,pos,SEEK_CUR);
ret=read(fd,buff,20);
printf("%s\n",buff);
close(fd);
return 0;
}
