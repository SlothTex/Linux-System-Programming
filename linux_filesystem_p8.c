//wap to open a file and write data in that file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
int fd=0,ret;
char name[100]={'\0'};
char brr[300];
printf("enter the file name\n");
scanf("%s",name);

fd=open(name,O_RDWR);
if(fd==-1)
{
printf("unable to open file\n");
return -1;
}
else
{
printf("file successfully gets opened\n");
}
printf("enter the  data to write\n");
scanf(" %[^\n]s",brr);
write(fd,brr,strlen(brr));
//write(1,brr,sizeof(brr));
close(fd);
return 0;
}
