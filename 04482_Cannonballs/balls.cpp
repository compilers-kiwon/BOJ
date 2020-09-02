#include	<iostream>

using namespace	std;

#define	MAX_SIZE	1000

int	main(void)
{
	int	n,num_of_balls[MAX_SIZE],sum[MAX_SIZE];
	
	num_of_balls[1] = sum[1] = 1;
	
	for(int i=2;i<MAX_SIZE;i++)
	{
		sum[i] = sum[i-1]+i;
		num_of_balls[i] = num_of_balls[i-1]+sum[i];
	}
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	a;
		
		cin>>a;
		cout<<i<<": "<<a<<' '<<num_of_balls[a]<<'\n';
	}
	
	return	0;
}
