#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50000+1)

int	x[MAX_SIZE],y[MAX_SIZE];

int	main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	int	max_value,min_value,c1,c2;
	
	// x+y
	max_value = -2000000;
	min_value = 2000000;
	
	for(int i=1;i<=N;i++)
	{
		max_value = max(max_value,x[i]+y[i]);
		min_value = min(min_value,x[i]+y[i]);
	}
	
	c1 = max_value-min_value;
	
	// x-y
	max_value = -2000000;
	min_value = 2000000;
	
	for(int i=1;i<=N;i++)
	{
		max_value = max(max_value,x[i]-y[i]);
		min_value = min(min_value,x[i]-y[i]);
	}
	
	c2 = max_value-min_value;
	
	cout<<max(c1,c2)<<'\n';
	
	return	0;
}
