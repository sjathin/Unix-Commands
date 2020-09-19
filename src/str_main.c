#include <stdio.h>
#include "./str.h"

int main(int argc,char *argv[])
{
	int len;
	len = strlen1(argv[1]);
	printf("%d\n",len);
	return 0;
}
