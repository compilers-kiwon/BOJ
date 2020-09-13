#include	<iostream>

using namespace	std;

#define	ROW_SIZE	100000
#define	COL_SIZE	3

#define	LEFT	1
#define	MID		2
#define	RIGHT	3

int				N,data[ROW_SIZE+1][COL_SIZE+1];
pair<int,int>	dp[ROW_SIZE+1][COL_SIZE+1];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>data[i][LEFT]>>data[i][MID]>>data[i][RIGHT];
		dp[i][LEFT] = dp[i][MID] = dp[i][RIGHT] = make_pair(-1,-1);
	}
	
	dp[1][LEFT] = make_pair(data[1][LEFT],data[1][LEFT]);
	dp[1][MID] = make_pair(data[1][MID],data[1][MID]);
	dp[1][RIGHT] = make_pair(data[1][RIGHT],data[1][RIGHT]);
}

int		get_max_dp(int row,int col)
{
	int&	ret = dp[row][col].first;
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = data[row][col];
	
	switch(col)
	{
		case	LEFT:
			ret += max(get_max_dp(row-1,col),get_max_dp(row-1,col+1));
			break;
		case	MID:
			ret += max(get_max_dp(row-1,col-1),max(get_max_dp(row-1,col),get_max_dp(row-1,col+1)));
			break;
		case	RIGHT:
			ret += max(get_max_dp(row-1,col-1),get_max_dp(row-1,col));
			break;
	}
	
	return	ret;
}

int		get_min_dp(int row,int col)
{
	int&	ret = dp[row][col].second;
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = data[row][col];
	
	switch(col)
	{
		case	LEFT:
			ret += min(get_min_dp(row-1,col),get_min_dp(row-1,col+1));
			break;
		case	MID:
			ret += min(get_min_dp(row-1,col-1),min(get_min_dp(row-1,col),get_min_dp(row-1,col+1)));
			break;
		case	RIGHT:
			ret += min(get_min_dp(row-1,col-1),get_min_dp(row-1,col));
			break;
	}
	
	return	ret;
}

int		main(void)
{
	init();
	
	int	max_value,min_value;
	
	max_value = max(get_max_dp(N,LEFT),max(get_max_dp(N,MID),get_max_dp(N,RIGHT)));
	min_value = min(get_min_dp(N,LEFT),min(get_min_dp(N,MID),get_min_dp(N,RIGHT)));
	
	cout<<max_value<<' '<<min_value<<'\n';
	
	return	0;
}
