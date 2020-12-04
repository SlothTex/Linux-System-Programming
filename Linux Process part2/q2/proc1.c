//count capital letters from demo.txt file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int fd=0,ret=0,cap=0,i=0;
char buffer[1024];
printf("process 1 running\n");
fd=open(argv[0],O_RDONLY);
if(fd==-1)
{
	printf("Unable to open file\n");
}
while((ret=read(fd,buffer,sizeof(buffer)))!=0)
{
	for(i=0;(i<sizeof(buffer))&&(buffer[i]!=EOF);i++)
	{	
		//printf("%c\n",buffer[i]);
		if((buffer[i]>='A') && (buffer[i]<='Z'))
		{
			cap++;
		}
	}
}
printf("process 1 i.e demo.txt capital letter count: %d\n",cap);
return 0;
}
