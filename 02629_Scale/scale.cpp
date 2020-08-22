#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_WEIGHT	30
#define	MAX_WEIGHT			500

#define	YES	1
#define	NO	0

int		dp[MAX_NUM_OF_WEIGHT+2][MAX_WEIGHT*MAX_NUM_OF_WEIGHT+1];
int		weight[MAX_NUM_OF_WEIGHT+1];
int		N,M;
char	answer[2] = {'N','Y'};

void	fill_weight_table(int weight_index,int current_weight)
{
	if( dp[weight_index][current_weight] != 0 )
	{
		return;
	}
	
	dp[weight_index][current_weight] = YES;
	
	if( weight_index > N )
	{
		return;
	}
	
	fill_weight_table(weight_index+1,current_weight+weight[weight_index]);
	fill_weight_table(weight_index+1,current_weight);
	fill_weight_table(weight_index+1,abs(current_weight-weight[weight_index]));
}

int		main(void)
{
	int	sum = 0;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>weight[i];
		sum += weight[i];
	}
	
	fill_weight_table(1,0);
	
	cin>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	w,result;
		
		cin>>w;
		
		if( w > sum )
		{
			result = NO;
		}
		else
		{
			result = dp[N+1][w];
		}
		putchar(answer[result]);putchar(' ');
	}
	puts("");
	
	return	0;
}
