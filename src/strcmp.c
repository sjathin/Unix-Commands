int strc(char a[],char b[])
{
	int i;
	int temp=0,fin=0;
	int max = strlen1(a);
	if(strlen1(b) > max)
	{
		max = strlen1(b);
	}
	for(i=0;i<max;i++)
	{
		if(a[i] != b[i])
		{
			fin = fin  + (a[i] - b[i]);
			//printf("%d-->%d",fin,strcmp(a,b));
			return fin;
		}
		else
		{
		}
	}
	//printf("%d-->%d-->%d\n",l,j,k);
}

