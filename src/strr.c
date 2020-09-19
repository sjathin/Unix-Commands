#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *a="jathin",*b="deepak";
	int i = strcmp(a,b);
	int j = strcmp(argv[1],argv[2]);
	printf("%d-->%d",i,j);
	return 0;
}
