#include	<iostream>
#include	<queue>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_PLAYER	(100+1)

int			N,K,P;
queue<int>	deck;
vector<int>	player_cards[MAX_PLAYER];

int	main(void)
{
	cin>>N>>K>>P;
	
	for(int i=1;i<=K;i++)
	{
		deck.push(i);
	}
	
	for(;!deck.empty();)
	{
		for(int i=1;i<=N;i++)
		{
			player_cards[i].push_back(deck.front());
			deck.pop();

			if( !deck.empty() )
			{
				for(int p=1;p<=P;p++)
				{
					deck.push(deck.front());
					deck.pop();
				}
			}
		}
	}
	
	sort(player_cards[N].begin(),player_cards[N].end());
	
	for(int i=0;i<player_cards[N].size();i++)
	{
		cout<<player_cards[N][i]<<'\n';
	}
	
	return	0;
}
