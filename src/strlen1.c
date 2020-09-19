int strlen1(char a[])
{
	int i;
	int count = 0;
	for(i=0;;i++)
	{
		if(*a!='\0')
		{
			count++;
			a++;
		}
		else
		{
			break;
			a++;
		}
	}
	return count;
}	
