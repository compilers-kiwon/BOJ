#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_WORK	(10000+1)

int			N,dp[MAX_NUM_OF_WORK],time_table[MAX_NUM_OF_WORK];
vector<int>	prev_work[MAX_NUM_OF_WORK];

int		get_dp(int work_index)
{
	if( dp[work_index] != -1 )
	{
		return	dp[work_index];
	}
	
	dp[work_index] = 0;
	
	for(int i=0;i<prev_work[work_index].size();i++)
	{
		dp[work_index] = max(dp[work_index],get_dp(prev_work[work_index][i]));
	}
	
	dp[work_index] += time_table[work_index];
	
	return	dp[work_index];
}

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	num_of_prev_work;
		
		cin>>time_table[i]>>num_of_prev_work;
		
		for(int j=1;j<=num_of_prev_work;j++)
		{
			int	w;
			
			cin>>w;
			prev_work[i].push_back(w);
		}
		
		dp[i] = -1;
	}
}

int		main(void)
{
	int	max_time,i;
	
	input();
	
	for(i=1,max_time=0;i<=N;i++)
	{
		max_time = max(max_time,get_dp(i));
	}
	
	cout<<max_time<<endl;
	
	return	0;
}
