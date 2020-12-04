//accept a directory name and open that directory and display the file name and display its mode type
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
int main(int argc,char*argv[])
{
int fd=0;
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
//printf("%s\t : %d\n",ptr->d_name,sobj.st_mode);
if(S_ISDIR(sobj.st_mode))
{
	printf("%s :\t directory File\n ",ptr->d_name);
}
else
{
printf("%s : \t regular file\n",ptr->d_name);
}
}

return 0;
}
