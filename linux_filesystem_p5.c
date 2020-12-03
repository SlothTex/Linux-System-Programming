/*WAP to open a file via command line arg and show error message if unable to open file*/
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char* argv[])
{
int fd;
fd=open(argv[1],O_RDONLY);
if(argc!=2)
{
	printf("ERROR:Incorrect number of arguments passed.");
	return -1;
}
if(fd==-1)
{
	printf("ERROR:Unable to open file.");
	return -1;
}
else
{
	printf("File opened successfully.");
}
return 0;
}
