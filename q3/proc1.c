#include"header.h"
int main(int argc,char *argv[])
{
struct dirent *ptr;
DIR *dir;
struct stat sobj;
dir=opendir(argv[0]);
int i=1,value=0;
char name[50],path[300];
printf("child process is running...\n");
if(dir==NULL)
{
  printf("Unable to open directory\n");
  return -1;
}
while((ptr=readdir(dir))!=NULL)
{
	sprintf(path,"%s/%s",argv[0],ptr->d_name);
	stat(path,&sobj);
	if(S_ISREG(sobj.st_mode))
	{
		sprintf(name,"%s/%d.%s",argv[0],i,"txt");
		//printf("%s%s\n",ptr->d_name,name);
		value=rename(path,name);		
		i++;
	}
	
	
		
}
return 0;
}


