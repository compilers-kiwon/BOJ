#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	NUM_OF_PLAYER	10000

typedef	pair<int,int>	Player;

bool	is_better(const Player& p1,const Player& p2)
{
	bool	result;
	
	if( p1.second > p2.second )
	{
		result = true;
	}
	else if( p1.second < p2.second )
	{
		result = false;
	}
	else
	{
		if( p1.first < p2.second )
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	
	return	result;
}

int		main(void)
{
	while(1)
	{
		int	N,M;
		
		scanf("%d %d",&N,&M);
		
		if( N == 0 && M == 0 )
		{
			break;
		}
		
		vector<Player>	player_point(NUM_OF_PLAYER+1);
		
		for(int i=1;i<=NUM_OF_PLAYER;i++)
		{
			player_point[i].first = i;
			player_point[i].second = 0;
		}
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				int	p;
				
				scanf("%d",&p);
				player_point[p].second++;
			}
		}
		
		stable_sort(&player_point[1],&player_point[NUM_OF_PLAYER+1],is_better);
		
		int	second_rank_point;
		
		second_rank_point = player_point[2].second;
		
		for(int i=2;i<=NUM_OF_PLAYER;i++)
		{
			if( player_point[i].second < second_rank_point )
			{
				break;
			}
			
			printf("%d ",player_point[i].first);
		}
		puts("");
	}
	
	return	0;
}
