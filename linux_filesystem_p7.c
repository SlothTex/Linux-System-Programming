//wap to accept a file and read whole file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd=0,ret=0;
char arr[10]={'\0'};
char brr[100]={'\0'};
printf("enter the file name\n");
scanf("%s",arr);

fd=open(arr,O_RDONLY);

ret=read(fd,brr,sizeof(brr));
write(1,brr,100);
close(fd);
return 0;
}

