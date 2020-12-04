//wap accept directory name from user and copy content of all file in file name allcombine
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
struct fileinfo
{
char fname[300];
int fsize;
};
int main(int args,char*argv[])
{
int fdsrc=0,fddest=0,ret=0;
char name[300],buff[1024];
struct fileinfo fobj;
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
fddest=creat("AllCombine.txt",0777);
while((ptr=readdir(dir))!=NULL)
{
sprintf(name,"%s/%s",argv[1],ptr->d_name);
stat(name,&sobj);
if(S_ISREG(sobj.st_mode))
{
fdsrc=open(name,O_RDONLY);
strcpy(fobj.fname,ptr->d_name);
fobj.fsize = sobj.st_size;
write(fddest,&fobj,sizeof(struct fileinfo));
if(ret=read(fdsrc,buff,sizeof(buff))!=0)
{
	write(fddest,buff,ret);	
}
close(fdsrc);
}
}
closedir(dir);
return 0;
}
