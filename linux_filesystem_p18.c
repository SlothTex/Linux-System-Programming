//wap which accepts directory file from user and display the file with largest size
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
int main(int args,char*argv[])
{
int fs=0,temp=0;
char name[300],fn[300];
struct dirent *ptr;
struct stat sobj;
DIR *dir;
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

temp=sobj.st_size;
if(temp>fs)
{
fs=temp;
strcpy(fn,ptr->d_name);
}
}
}
printf("max size of is of file %s : %d \n",fn,fs);
closedir(dir);
return 0;
}
