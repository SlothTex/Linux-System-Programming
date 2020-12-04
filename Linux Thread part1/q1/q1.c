/*wap to create a simple thread.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
void *fun(void *p)
{
	int i=0,no1=2001;
	for(i=1;i<(int)p;i++)
	{
		printf("%d\n",i);
	}
	pthread_exit(no1);
}
int main(int argc,char *argv[])
{
	pthread_t thread1;
	int no1=10;
	int myret=0,ret=0;
	printf("Inside main thread..\n");
	ret=pthread_create(&thread1,//address f pthred_t pointer
				NULL,//attrbute of thread
				fun,//adress of callback function
				(void *)no1);//parametersof callback function
	if(ret!=0)
	{
		printf("Unable to create a thread\n");
		return -1;
	}
	pthread_join(thread1,&myret);//(pthread_t pointer,status of thread)
	printf("return value from thread %d\n",myret);
	printf("terminating the main thread\n");
}
