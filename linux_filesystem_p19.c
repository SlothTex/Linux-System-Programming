//wap to copy contents from one files to another file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
int ret=0,fdsrc=0,fddest=0;
char buff[256];
if(argc!=3)
{
printf("invalude input\n format : ./myexe src_file dest_file\n");
return -1;
}

fdsrc=open(argv[1],O_RDONLY);
if(fdsrc==-1)
{
printf("unable to source open file\n");
return -1;
}
fddest=open(argv[2],O_WRONLY|O_CREAT,0777);
if(fddest==-1)
{
printf("unable to destination open file\n");
return -1;
}

while((ret=(read(fdsrc,buff,sizeof(buff))))!=0)
{
write(fddest,buff,ret);
}
close(fdsrc);
close(fddest);
return 0;
}
