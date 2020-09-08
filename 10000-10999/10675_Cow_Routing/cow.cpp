#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	A,B,N,min_cost;
	
	cin>>A>>B>>N;
	min_cost = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		int	cost,len,A_found,B_found;
		
		cin>>cost>>len;
		A_found = B_found = 0;
		
		for(int j=1;j<=len;j++)
		{
			int	city;
			
			cin>>city;
			
			if( city == A )
			{
				A_found = j;
			}
			else if( city == B )
			{
				B_found = j;
			}
		}
		
		if( A_found!=0 && B_found!=0 && A_found<B_found )
		{
			min_cost = min(min_cost,cost);
		}
	}
	
	if( min_cost == 0x7FFFFFFF )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<min_cost<<'\n';
	}
	
	return	0;
}
