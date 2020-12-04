//accept a directory name and write 10 letters from every regular file into newely created file demo.txt
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
int fd=0,fd2=0,ret=0;
char name[300],buff[100];
struct dirent *ptr;
struct stat sobj;
DIR *dir;
if (argc!=3)
{
printf("InvalidInput\n Format: ./myexe dir_name file_name");
return -1;
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
fd=creat(argv[2],0777);
while((ptr=(readdir(dir)))!=NULL)
{
sprintf(name,"%s/%s",argv[1],ptr->d_name);
stat(name,&sobj);
//printf("%s\t : %d\n",ptr->d_name,sobj.st_mode);
if(S_ISREG(sobj.st_mode))
{	fd2=open(name,O_RDONLY);
	//read 10byts from each file in dir
	ret=read(fd2,buff,10);
	//write into new file
	write(fd,ptr->d_name,strlen(ptr->d_name));
	write(fd,buff,ret);
	memset(buff,0,sizeof(buff));
	close(fd2);
}
}
closedir(dir);
close(fd);
return 0;
}
