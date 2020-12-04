/*wap which is used to get a thread id inside a thread function*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
void *fun(void *p)
{
	int i=0;
	printf("Inside thread \n thread id is:%ld\n",pthread_self());
	pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
	pthread_t thread1;
	int myret=0,ret=0;
	printf("Inside main thread..\n");
	ret=pthread_create(&thread1,//address f pthred_t pointer
				NULL,//attrbute of thread
				fun,//adress of callback function
				NULL);//parametersof callback function
	if(ret!=0)
	{
		printf("Unable to create a thread\n");
		return -1;
	}
	pthread_join(thread1,NULL);//(pthread_t pointer,status of thread)
	printf("return value from thread %d\n",myret);
	printf("terminating the main thread\n");
}
