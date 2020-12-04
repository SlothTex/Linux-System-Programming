/*Display username and home directory*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pwd.h>
#include<sys/types.h>
#include<sys/resource.h>
//extern char **environ;
int main()
{
	char *buff,*hd;
	buff=getenv("USERNAME");
	printf("Username:%s\n",buff);
	hd=getenv("HOME");
	printf("Home Directory name:%s\n",buff);
	//home directory path
	uid_t uid=getuid();
	struct passwd *pw=getpwuid(uid);
	printf("Home Directory path:%s\n",pw->pw_dir);
	return 0;
}
