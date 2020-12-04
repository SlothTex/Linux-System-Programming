/*wap to write a structure in file.Structure should contain information of the empoyee*/
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
fp=fopen(argv[1],"w");
if(fp==NULL)
{
	printf("Unable to open file\n ");
	return -1;
}
printf("Enter \"stop\" for the entry to end");
while(1)
{
printf("\nEnter name:");
scanf("%s",emp.ename);
if(strcmp(emp.ename,"stop")==0)
{
	exit(1);
}
printf("\nEnter emp id:");
scanf("%d",&emp.eid);
printf("\nEnter emp sal:");
scanf("%d",&emp.sal);
printf("\nEnter emp desgination:");
scanf("%s",emp.desg);
fwrite(&emp,sizeof(struct employee),1,fp);
}
return 0;
}
