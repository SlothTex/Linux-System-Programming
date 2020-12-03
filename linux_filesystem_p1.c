
//addition of two number using commandline argument
#include<stdio.h>
#include<stdlib.h>
int main(int args,char*argv[])
{
int ans=0,a=0,b=0;
a=atoi(argv[1]);
b=atoi(argv[2]);
ans=a+b;
printf("%d+%d=%d",a,b,ans);
return 0;
}
