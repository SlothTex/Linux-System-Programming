//wap which accepts two directory and move all files from one directory to another 
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
char srcname[300],destname[300];
struct dirent *ptr;
struct stat sobj;
DIR *src,*dest;
if(argc!=3)
{
printf("invalid i/p \n ./my exe dir_name file_name");
return -1;
}
src=opendir(argv[1]);
dest=opendir(argv[2]);
if((src==NULL) && (dest==NULL))
{
printf("unable to open the directory\n");
}
else
{
printf("success to open the directory\n");
}
while((ptr=readdir(src))!=NULL)
{
sprintf(srcname,"%s/%s",argv[1],ptr->d_name);
sprintf(destname,"%s/%s",argv[2],ptr->d_name);
stat(srcname,&sobj);
if(S_ISREG(sobj.st_mode))
{
rename(srcname,destname);
}
}
closedir(src);
closedir(dest);
return 0;
}
