//accept a directory name from file crrete hole in the file if filesize is >1 kb and truncate the file < than 1kb
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int args,char*argv[])
{
int fd=0,temp=0,ret=0;
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
fd=open(name,O_RDWR);
if(temp>1000)//1kb=1000 bytes
{
ret=lseek(fd,1000,SEEK_CUR);
ftruncate(fd,ret);
}
else
{
ret=lseek(fd,1000,SEEK_CUR);
write(fd,"hello",6);
}
}
close(fd);
}
closedir(dir);
return 0;
}
