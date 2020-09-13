long long	sum(int *a,int n)
{
	long long	s;
	int			i;
	
	for(i=0,s=0;i<n;i++)
	{
		s += a[i];
	}
	
	return	s;
}
