#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PLAYER		(100+1)
#define	MAX_VALUE_OF_EACH_CARD	(100+1)

int		N,M,score[MAX_NUM_OF_PLAYER];

void	play_game(priority_queue<int>* card_deck)
{
	for(int i=1;i<=M;i++)
	{
		vector<int>	winner;
		int			max_value;
		
		max_value = 0;
		
		for(int j=1;j<=N;j++)
		{
			int	c;
			
			c = card_deck[j].top();
			card_deck[j].pop();
			
			if( c >= max_value )
			{
				if( c > max_value )
				{
					max_value = c;
					winner.clear();
				}
				winner.push_back(j);
			}
		}
		
		for(int j=0;j<winner.size();j++)
		{
			score[winner[j]]++;
		}
	}
}

int		main(void)
{
	priority_queue<int> card_deck[MAX_NUM_OF_PLAYER];
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			int	c;
			
			cin>>c;
			card_deck[i].push(c);
		}
	}
	
	play_game(card_deck);
	
	vector<int>	winner;
	int			max_score;
	
	max_score = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( score[i] >= max_score )
		{
			if( score[i] > max_score )
			{
				max_score = score[i];
				winner.clear();
			}
			winner.push_back(i);
		}
	}
	
	for(int i=0;i<winner.size();i++)
	{
		cout<<winner[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}
