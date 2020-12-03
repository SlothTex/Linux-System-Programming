//wap to accept a file and read first 5 char

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd=0,ret=0;
char arr[10]={'\0'};
char brr[5]={'\0'};
printf("enter the file name\n");
scanf("%s",arr);

fd=open(arr,O_RDONLY);

ret=read(fd,brr,5);
write(1,brr,5);
close(fd);
return 0;
}

