#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int dest,source;
	char buf[10];
	int temp;
	if(argc==3)
	{
		source = open(argv[1],O_RDWR);
		dest = open(argv[2],O_CREAT|O_EXCL|O_RDWR,777);
		do
		{
			temp = read(source,&buf,10);
			write(dest,&buf,temp);
		}while(temp!=0);
	}
	else
	{
		printf("Wrong no. of args");
		exit(1);
	}
}
