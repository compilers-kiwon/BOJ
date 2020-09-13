#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	TBD			-1

#define	WIN		1
#define	LOSE	0

#define is_visited(v,c)	(((v)&(1<<(c)))!=0)

int	N;
int	record[MAX_SIZE][MAX_SIZE];
int	dp[1<<MAX_SIZE][MAX_SIZE];

int		get_dp(int current_player,int visited)
{
	int&	ret = dp[visited][current_player];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int p=1;p<=N;p++)
	{
		if( record[current_player][p]==WIN && is_visited(visited,p)==false )
		{
			ret = max(ret,get_dp(p,visited|(1<<p))+1);
		}
	}
	
	return	ret;
}

void	print_players(int current_player,int visited)
{
	cout<<current_player<<' ';
	
	for(int i=1;i<=N;i++)
	{
		if( record[current_player][i]==WIN && is_visited(visited,i)==false )
		{
			if( dp[visited][current_player]-1 == dp[visited|(1<<i)][i] )
			{
				print_players(i,visited|(1<<i));
				break;
			}
		}
	}
}

int		main(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>record[row][col];
		}
	}
	
	for(int row=(1<<1);row<=(1<<MAX_SIZE)-1;row++)
	{
		fill(&dp[row][1],&dp[row][N+1],TBD);
	}
	
	cout<<get_dp(1,(1<<1))+1<<"\n";
	print_players(1,1<<1);
	
	return	0;
}
