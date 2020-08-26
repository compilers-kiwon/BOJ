#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(30+1)

int	main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int		n;
		double	M,v,h,m[MAX_SIZE],t[MAX_SIZE],F[MAX_SIZE];
		
		cin>>n>>M;
		v = h = 0.0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>m[i]>>t[i]>>F[i];
			M += m[i];
		}
		
		for(int i=1;i<=n;i++)
		{
			h += v*t[i]+0.5*(F[i]/M-9.81)*t[i]*t[i];
			v += (F[i]/M-9.81)*t[i];
			M -= m[i];
		}
		
		printf("Data Set %d:\n%.02f\n\n",k,h);
	}
	
	return	0;
}
