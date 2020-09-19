#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd;
	int temp;
	int i;
	char buf[10];
	if(argc==1)
	{
		while(1)
		{
			read(0,&buf,1);
			write(1,&buf,1);
		}
		return 0;
	}
	else if(argc >= 2)
	{
		for(i=1;i<argc;i++)
		{
			fd = open(argv[i],O_RDONLY);
			if(fd==-1)
			{
				perror("error");
				return -1;
			}
			do
			{
				if((temp = read(fd,&buf,10)) == -1)
				{
					perror("Read Failed!!");
					exit(1);
				}
				if(write(1,&buf,temp)==-1)
				{
					perror("Write Failed");
					exit(1);
				}
			}while(temp!=0);
		}
	}
	return 0;
}
