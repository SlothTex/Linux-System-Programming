//wap to show i/o redirection
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
int fd=0,ret=0;
char arr[10];
fd=open(argv[1],O_RDONLY);
if(fd==-1)
{
printf("unable ot open file\n");
}
while((ret=read(fd,arr,sizeof(arr)))!=0)
{
write(1,arr,ret);
}
return 0;
}
