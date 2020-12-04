/*wap to to read struct from a file*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
struct employee
{
int eid;
int sal;
char ename[300];
char desg[300];
};
int main(int argc,char *argv[])
{
int fd=0,cnt,ret=0;
char bff[100];
FILE *fp;
struct employee emp;
if(argc!=2)
{
	printf("Invalid input\n");
	return -1;
}
fp=fopen(argv[1],"r");
if(fp==NULL)
{
	printf("Unable to open file\n ");
	return -1;
}
while(fread(&emp,sizeof(struct employee),1,fp))
{
	printf("emp id:%d \t emp name:%s \t emp sal:%d \t emp desg:%s\n",emp.eid,emp.ename,emp.sal,emp.desg);
}
return 0;
}
