/*application which is used to separate conent from one file to multiple file
1. open file
2.Check struct -->extract name
3.create print the content of that size
4.lseek from that size of that struct
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
//argv[0] argv[1] argv[2]
//./myexe  dirname filename
struct fileinfo
{
char fname[256];
int fsize;
};
int main(int argc,char *argv[])
{
int ret1=0,fsrc=0,fdest=0;
char *buff;
struct fileinfo fobj;
if(argc!=2)//Invalid argument passed
{
	printf("ERROR:Invalid argument numb");
	return -1;
}
fsrc=open(argv[1],O_RDONLY);
while((ret1=read(fsrc,&fobj,sizeof(fobj)))!=0)
{
  printf("%s \t :%d",fobj.fname,fobj.fsize);
  //create that name file and fd achieved
  fdest=creat(fobj.fname,0777);
  //allocate buffer dynamic memory  
  buff=(char*)malloc(sizeof(fobj.fsize));
  //read that data from common file
  ret1=read(fsrc,buff,sizeof(buff));
  //write content in that file
  write(fdest,buff,sizeof(fobj.fsize));
  //free memory
  free(buff);
  //close dest file
  close(fdest);
}
close(fsrc);//unlink(argv[1]);
return 0;//exit(0)
}
