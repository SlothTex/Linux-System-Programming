//accept a directory name and open that directory and delete file greater than 100bytes
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

while((ptr=(readdir(dir)))!=NULL)
{
sprintf(name,"%s/%s",argv[1],ptr->d_name);
stat(name,&sobj);
if(S_ISREG(sobj.st_mode))
{
	if((sobj.st_size)>100)
	{
		printf("%s\t : %ld deleted \n",ptr->d_name,sobj.st_size);
		unlink(name);
		flag1=0;
	}
}
}
if(flag1==1)
{
printf("file size greater than 100 not found\t");
}
closedir(dir);
return 0;
}
