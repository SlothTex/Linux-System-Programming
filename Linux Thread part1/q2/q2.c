/*wap to create a 2 thread.thread 1 prints 1-500 and 2nd thread prints 500-1*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
void *fun(void *p)
{
	int i=0,no1=2001;
	printf("(int)p is %d\n",(int)p);
	for(i=(int)p;i>0;i--)
	{
		printf("Inside thread 1\n");
		printf("%d\n",i);
	}
	pthread_exit(no1);
}
void *gun(void *p)
{
	int i=0;
	for(i=1;i<=(int)p;i++)
	{
		printf("Inside thread 2\n");
		printf("%d\n",i);
	}
	pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
	pthread_t thread1;
	pthread_t thread2;
	int no1=500;
	int myret1=0,myret2=0,ret1=0,ret2=0;
	printf("Inside main thread..\n");
	ret1=pthread_create(&thread1,//address f pthred_t pointer
				NULL,//attrbute of thread
				fun,//adress of callback function
				(void *)no1);//parametersof callback function
	if(ret1!=0)
	{
		printf("Unable to create a thread 1\n");
		return -1;
	}
	ret2=pthread_create(&thread2,NULL,gun,(void *)no1);
	if(ret2!=0)
	{
		printf("Unable to create a thread 2\n");
		return -1;
	}
	pthread_join(thread1,&myret1);//(pthread_t pointer,status of thread)
	pthread_join(thread2,&myret2);
	printf("return value from thread %d\n",myret1);
	printf("return value from thread %d\n",myret2);
	printf("terminating the main thread\n");
}
