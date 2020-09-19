#include <stdio.h>
#include <string.h>
#include "./str.h"

int main(int argc,char *argv[])
{
	char buff[100];
	strcpy(buff,scat(argv[1],argv[2]));
	puts(buff);
}
