//accept a directory name and open that directory create a file in that directory
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
int fd=0,flag1=0;
char name[300];
struct dirent *ptr;
struct stat sobj;
DIR *dir;
if(argc!=3)
{
	printf("ERROR: Invalid input.\n Format: ./a.out dir_name file_name");
}
dir=opendir(argv[1]);
if(dir==NULL)
{
printf("cannot open the directory\n");
return -1;
}
else
{
printf("directory successfully opened\n");
}
sprintf(name,"%s/%s",argv[1],argv[2]);
fd=creat(name,0777);
if(fd==-1)
{
	printf("File cannot be created successfully in %s named %s",argv[1],argv[2]);
	return -1;
}
else
{
	printf("File  created successfully in %s named %s",argv[1],argv[2]);
}
closedir(dir);
return 0;
}
