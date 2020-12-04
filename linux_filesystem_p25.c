//accept two file from user and check weather the contents of both files are same or not
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
int ret1=0,ret2=0,fd1=0,fd2=0;

if(argc!=3)
{
printf("error : invalide input \n format : ./myexe file1 file2\n");
return -1;
}
fd1=open(argv[1],O_RDONLY);
if(fd1==-1)
{
printf("unable to open the file\n");
return -1;
}
else
{
printf("file1 successfully opened\n");
}
fd2=open(argv[2],O_RDONLY);
if(fd1==-1)
{
printf("unable to open the file\n");
return -1;
}
else
{
printf("file2 successfully opened\n");
}
while((ret1=read(fd1,buff1,sizeof(buff1))!=0)
{
	while((ret1=read(fd1,buff1,sizeof(buff1))!=0)
		{
			
		}	
}
close(fd1);
close(fd2);
return 0;
}
