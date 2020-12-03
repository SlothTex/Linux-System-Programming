//wap which accept a file name from user and write a string in that file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char*argv[])
{
int fd=0,ret=0;
char brr[30]={'\0'};
fd=open(argv[1],O_RDWR);
if(fd==-1)
{
printf("unable to open the file\n");
return -1;
}
else
{
printf("file successfully openedd with fd %d",fd);
}
printf("enter the data to insert into the file\n");
scanf(" %[^\n]s",brr);
write(fd,brr,strlen(brr));
close(fd);
return 0;
}
