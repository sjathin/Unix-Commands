#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <sys/errno.h>

int main(int argc,char *argv[])
{
	int fd;
	int i;
	static char temp[100];
	if((fd = open(argv[argc-1],O_RDWR)) == -1 && errno == EISDIR)
	{
		printf("Directory");
		for(i=1;i<argc-1;i++)
		{
			strcpy(temp,argv[argc-1]);
			strcat(temp,"/");
			strcat(temp,argv[i]);
			link(argv[i],temp);
			unlink(argv[i]);
		}
		return 0;
	}
	if(argc==3)
	{
		link(argv[1],argv[2]);
		unlink(argv[1]);
	}
	else
	{
		printf("Wrong no. of arguments!");
		exit(0);
	}
}
	
