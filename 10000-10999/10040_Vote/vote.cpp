#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_GAME	(1000+1)
#define	MAX_COST		(1000+1)

vector<int>	game_list[MAX_COST];
int			vote_cnt[MAX_NUM_OF_GAME];

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	A;
		
		cin>>A;
		game_list[A].push_back(i);
	}
	
	for(int i=1;i<=M;i++)
	{
		int	B,max_fun_game;
		
		cin>>B;
		max_fun_game = 0x7FFFFFFF;
		
		for(int j=1;j<=B;j++)
		{
			for(int k=0;k<game_list[j].size();k++)
			{
				max_fun_game = min(max_fun_game,game_list[j][k]);
			}
		}
		vote_cnt[max_fun_game]++;
	}
	
	int	max_vote,max_vote_game;
	
	max_vote = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( max_vote < vote_cnt[i] )
		{
			max_vote = vote_cnt[i];
			max_vote_game = i;
		}
	}
	cout<<max_vote_game<<endl;
	
	return	0;
}
