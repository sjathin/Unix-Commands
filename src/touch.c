#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc,char *argv[])
{
	char a[10];
	char name[10];
	DIR *d;
	struct dirent *direc;
	if(argc<2)
	{
		printf("Error\n");
	}
	if(argv[1][0] == '*' && argv[1][1] == '.')
	{
		strcpy(a,strchr(argv[1],'.'));
		if((d = opendir(".")) == NULL)
		{
			perror("error");
		}
		while(1)
		{
			if((direc = readdir(d)) != NULL)
			{
				strcpy(name,strchr(direc->d_name,'.'));
				if(!strcmp(name,a))
				{
					utime(direc->d_name,NULL);
				}
			}
			else if((direc = readdir(d)) == NULL)
			{
				break;
			}
		}
		return 0;
	}		
	int x,fd,i,y;
	for(i=1;i<argc;i++)
	{
		x = access(argv[i],F_OK);
		if(x!=0)
		{
			if((fd = open(argv[i],O_CREAT,0644)) == -1)
			{
				perror("error");
			}
		}
		else if(x==0)
		{
			if((y=utime(argv[i],NULL)) == -1)
			{
				perror("error");
			}
		}
	}
}
