//wap accept directory name from user and display all info of regular file and display its content
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
int fd=0,ret=0;
char name[300],buff[1024];
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
printf("\n\n");
printf("\nFile name:%s",ptr->d_name);
printf("File size: %d\n",(int)sobj.st_size);//file size in bytes
printf("inode numb: %d\n",(int)sobj.st_ino);//inode no
printf("File mode: %d\n",(int)sobj.st_mode);//protection mode
printf("Numb of link: %d\n",(int)sobj.st_nlink);//numb of hardlink
printf("User id: %d\n",(int)sobj.st_uid);//user id of owner
printf("Group id : %d\n",(int)sobj.st_gid);//group id of owner
printf("Device ID: %d\n",(int)sobj.st_dev);//ID of device containing file
printf("File is of type special device ID: %d\n",(int)sobj.st_rdev);//if special file device id
printf("Blocksize of i/o: %d\n",(int)sobj.st_blksize);//blksize of i/o file
printf("512B blok alloc: %d\n",(int)sobj.st_blocks);//no. of 512B blocks allocated
printf("time of last acccess: %d\n",(int)sobj.st_atime);
printf("time of last modification: %d\n",(int)sobj.st_mtime);
printf("time of last status change: %d\n",(int)sobj.st_ctime);
fd=open(name,O_RDONLY);
if(ret=read(fd,buff,sizeof(buff))!=0)
{
	printf("content of file :%s",buff);
}
close(fd);
}
}
closedir(dir);
return 0;
}
