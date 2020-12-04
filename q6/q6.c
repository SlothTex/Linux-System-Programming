/*Display environment variable for our running process*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
extern char **environ;
int main()
{
	char **env=environ;
	printf("Enironment variables are\n");
	for(;*env!=NULL;++env)
	{
	
	printf("________________________________________\n");
	printf("%s\n",*env);
	
	}
	return 0;
}
