#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
	DIR *d;
	struct dirent *direc;
	struct stat file;
	int m;
	d = opendir(".");
	while(1)
	{
		if((direc = readdir(d))!=NULL)
		{
			//if(!strcmp(direc->d_name,".") || !strcmp(direc->d_name,".."))
			{
				//printf("%s\t",direc->d_name);
				m = stat(direc->d_name,&file);
				if(file.st_mode & S_IRUSR)
				{
					printf("r");
				}
				if(file.st_mode & S_IWUSR)
				{
					printf("w");
				}
				else
				{
					printf("-");
				}
				if(file.st_mode & S_IXUSR)
				{
					printf("x");
				}
				else
				{
					printf("-");
				}
				if(file.st_mode & S_IRGRP)
				{
					printf("r");
				}
				else
				{
					printf("-");
				}
				if(file.st_mode & S_IWGRP)
                                {
                                        printf("w");
                                }
                                else
                                {
                                        printf("-");
                                }
				if(file.st_mode & S_IXGRP)
                                {
                                        printf("x");
                                }
                                else
                                {
                                        printf("-");
                                }
				printf("%s\n",direc->d_name);

			}
		}
		else
		{
			break;
		}
	}
	//`return 0;
}
