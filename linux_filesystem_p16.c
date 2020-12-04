//wap witch accept the name of directory and display contents in it
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
int main(int argc,char*argv[])
{
int ret=0;
struct dirent *ptr;
DIR *dir=NULL;
dir=opendir(argv[1]);
if(dir==NULL)
{
printf("unable to open the directory\n");
return -1;
}
else 
{
printf("directory opened successfully\n");
}
while((ptr=readdir(dir))!=NULL)
{
printf("\n%s\t",ptr->d_name);
}
closedir(dir);
return 0;
}
