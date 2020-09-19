char * scat(char str1[],char str2[])
{
	char buf[100];
	int s1 = strlen1(str1);
	int s2 = strlen1(str2);
	int i ,j;
	for(i=0;i<s1;i++)
	{
		buf[i]=str1[i];
	}
	int k=0;
	for(j=i+1;j<s2;j++)
	{
		buf[j] = str2[k];
		k++;
	}
	return buf;
}
	
