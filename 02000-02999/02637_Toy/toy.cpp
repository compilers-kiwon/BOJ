#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PARTS	(100+1)

int			N,M,dp[MAX_NUM_OF_PARTS];
bool		is_mid_part[MAX_NUM_OF_PARTS];

typedef	pair<int,int>	Structure;	// first:part_no, second:num

vector<Structure>	my_upper_part[MAX_NUM_OF_PARTS];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		dp[i] = -1;
	}
	
	dp[N] = 1;
	
	for(int i=1;i<=M;i++)
	{
		int	X,Y,K;
		
		cin>>X>>Y>>K;
		
		my_upper_part[Y].push_back(make_pair(X,K));
		is_mid_part[X] = true;
	}
}

int		get_dp(int part_no)
{
	int&	ret = dp[part_no];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int i=0;i<my_upper_part[part_no].size();i++)
	{
		int&	my_upper_part_no = my_upper_part[part_no][i].first;
		int&	my_upper_part_quantity = my_upper_part[part_no][i].second;
		
		ret += get_dp(my_upper_part_no)*my_upper_part_quantity;
	}
	
	return	ret;
}

int		main(void)
{
	init();
	
	for(int i=1;i<=N;i++)
	{
		if( is_mid_part[i] == false )
		{
			cout<<i<<' '<<get_dp(i)<<'\n';
		}
	}
	
	return	0;
}
