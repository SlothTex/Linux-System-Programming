#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
struct finfo
{
char fname[100];
int size;
};
int main(int argc,char *argv[])
{
struct dirent *ptr;
DIR *dir;
struct stat sobj;
struct finfo fobj;
char pathname[355],buff[1024];
int fd1=0,d1=0,ret=0,ret1=0;
printf("into child process\n");
fd1=creat("demo.txt",0777);
if(fd1==-1)
{
	printf("Unable to create file\n");
	return -1;
}
dir=opendir("/home/milindn/Desktop/");
if(dir==NULL)
{
	printf("Unable to open directory\n");
	return -1;
}
while((ptr=readdir(dir))!=NULL)
{
sprintf(pathname,"%s%s","/home/milindn/Desktop/",ptr->d_name);
stat(pathname,&sobj);
	if(S_ISREG(sobj.st_mode))
	{
		strcpy(fobj.fname,ptr->d_name);
		fobj.size=sobj.st_size;
		ret=write(fd1,&fobj,sizeof(fobj));
		//ret=write(fd1,"\n",sizeof('\n'));
		if(ret==-1)
		{
			printf("Unable to write in file\n");
			return -1;	
		}
		memset(&fobj,0,sizeof(fobj));
	}
}
close(fd1);
closedir(dir);
//read content from demo.txt file
fd1=open("demo.txt",O_RDONLY);
if(fd1==-1)
{
	printf("Unable to create file\n");
	return -1;
}
while(ret1=(read(fd1,&fobj,sizeof(fobj)))!=0)
{
	printf("%s\t%d\n",fobj.fname,fobj.size);
}
close(fd1);
return 0;
}
