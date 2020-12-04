//wap which accepts directory file and file name from user and search that file 
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char*argv[])
{
int flag1=1,fs=0,temp=0;
char name[300],fn[300];
struct dirent *ptr;
struct stat sobj;
DIR *dir;
if(argc!=3)
{
printf("invalid i/p \n ./my exe dir_name file_name");
return -1;
}
dir=opendir(argv[1]);
if(dir==NULL)
{
printf("unable to open the directory\n");
}
else
{
printf("directory successfully opened\n");
}
while((ptr=readdir(dir))!=NULL)
{
sprintf(name,"%s/%s",argv[1],ptr->d_name);
stat(name,&sobj);
if(S_ISREG(sobj.st_mode))
{
if(strcmp(ptr->d_name,argv[2])==0)
{
	printf("file %s found \n",argv[2]);
	flag1=0;
}
}
}
if(flag1==1)
{
printf("file %s not found\n",argv[2]);
}
closedir(dir);
return 0;
}
