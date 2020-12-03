//wap that accept the name of a file and number and display that many bytes on the screen  
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int args,char *argv[])
{
int fd=0;
int ret;
int no;
char *brr=NULL;
if(args!=3)
{
printf("insufficient arguments\n ");
return -1;
}
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("unable to open the file\n");
return -1;
}
else
{
printf("file opened with fd %d \n",fd);
}
no=atoi(argv[2]);
brr=(char*)malloc(sizeof(char)*no);
if(brr==NULL)
{
printf("memory allocation failed\n");
return -1;
}
ret=read(fd,brr,no);
printf("\nthe data inside the file %s are : %s",argv[1],brr);
//write(1,brr,no);
free(brr);
close(fd);
return 0;
}
