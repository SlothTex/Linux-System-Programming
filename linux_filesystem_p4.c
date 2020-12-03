//write a program which accepts a filename and open that file 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
int fd=0;
char arr[20]={'\0'};

printf("enter the file name\n");
scanf("%s",arr);

fd=(arr,O_RDONLY|O_CREAT,0777);
if(fd==-1)
{
printf("file unable to open\n");
return -1;
}
else
{
printf("file successfully gets open with fd %d",fd);
}
return 0;
} 
