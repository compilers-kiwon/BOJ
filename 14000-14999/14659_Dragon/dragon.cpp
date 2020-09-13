#include	<iostream>

using namespace	std;

#define	MAX_NUM	(30000+1)

int	main(void)
{
	int	N,dp_height[MAX_NUM],dp_kill[MAX_NUM],max_num_of_kill;
	
	cin>>N>>dp_height[1];
	
	dp_kill[1] = 0;
	max_num_of_kill = 0;
	
	for(int i=2;i<=N;i++)
	{
		int	current_height;
		
		cin>>current_height;
		
		if( current_height < dp_height[i-1] )
		{
			dp_height[i] = dp_height[i-1];
			dp_kill[i] = dp_kill[i-1]+1;
		}
		else
		{
			dp_height[i] = current_height;
			dp_kill[i] = 0;
		}
		max_num_of_kill = max(max_num_of_kill,dp_kill[i]);
	}
	cout<<max_num_of_kill<<endl;
	
	return	0;
}
