//accept a name from user and create directory of that name 
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char *argv[])
{
int dfd=0;
if(argc!=2)
{
printf("invalid input \n format : ./myexe name  ");
return -1;
}
dfd=mkdir(argv[1],S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
if(dfd==-1)
{
printf("unable to create directory\n");
}
else
{
printf("directory created successfully\n");
}
return 0; 
}
