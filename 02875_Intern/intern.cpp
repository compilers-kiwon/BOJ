#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,M,K;
	int	max_num_of_team,i;
	
	cin>>N>>M>>K;
	
	for(max_num_of_team=0,i=1;i<=min(N/2,M);i++)
	{
		if( N-2*i>=0 && M-i>=0 && (N-2*i)+(M-i)>=K )
		{
			max_num_of_team = max(max_num_of_team,i); 
		}
	}
	cout<<max_num_of_team<<endl;
	
	return	0;
}
