/*wap to create a simple thread and return which accepts some value from user and returns some value from caller thread*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>
struct summation
{
	int numb1;
};
void *fun(void *p)
{
	int sum=0,ino1=2001;
	printf("Value passed by user is :%d \n",(((struct summation*)p)->numb1));
	pthread_exit(ino1);
}
int main(int argc,char *argv[])
{
	pthread_t thread1;
	int no1=0;
	int myret=0,ret=0;
	no1=atoi(argv[1]);
	struct summation *sobj=(struct summation*)malloc(sizeof(struct summation));
	int arr[2];
	sobj->numb1=no1;
	printf("Inside main thread..\n");
	ret=pthread_create(&thread1,//address f pthred_t pointer
				NULL,//attrbute of thread
				fun,//adress of callback function
				(void *)sobj);//parametersof callback function
				
				
	if(ret!=0)
	{
		printf("Unable to create a thread\n");
		return -1;
	}
	pthread_join(thread1,&myret);//(pthread_t pointer,status of thread)
	printf("return value from thread is %d\n",myret);
	
	printf("terminating the main thread\n");
}
