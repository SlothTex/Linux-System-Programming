/*wap to create a thread which passes value to the thread accepted via main thread.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>
struct summation
{
	int numb1,numb2;
};
void *fun(void *p)
{
	int sum=0;
	sum=(((struct summation*)p)->numb1)+(((struct summation*)p)->numb2);
	pthread_exit(sum);
}
int main(int argc,char *argv[])
{
	pthread_t thread1;
	int no1=0,no2=0;
	int myret=0,ret=0;
	no1=atoi(argv[1]);
	no2=atoi(argv[2]);
	struct summation *sobj=(struct summation*)malloc(sizeof(struct summation));
	int arr[2];
	sobj->numb1=no1;
	sobj->numb2=no2;
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
	printf("return value i.e sum from thread is %d\n",myret);
	
	printf("terminating the main thread\n");
}
