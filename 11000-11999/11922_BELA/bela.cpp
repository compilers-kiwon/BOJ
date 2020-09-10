#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

typedef	pair<int,int>	Score;

#define	dominant		first
#define	not_dominant	second

#define	NUM_OF_CARDS_IN_HAND	4

#define	SYMBOL	0
#define	SUIT	1

void	init_score_table(map<char,Score>& table)
{
	table['A'] = make_pair(11,11);
	table['K'] = make_pair(4,4);
	table['Q'] = make_pair(3,3);
	table['J'] = make_pair(20,2);
	table['T'] = make_pair(10,10);
	table['9'] = make_pair(14,0);
	table['8'] = table['7'] = make_pair(0,0);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,total_score;
	char	B;
	
	map<char,Score>	score_table;
	
	init_score_table(score_table);
	
	cin>>N>>B;
	total_score = 0;
	
	for(int h=1;h<=N;h++)
	{
		for(int c=1;c<=NUM_OF_CARDS_IN_HAND;c++)
		{
			string	card;
						
			cin>>card;
			
			char&	symbol = card[SYMBOL];
			char&	suit = card[SUIT];
			
			if( B == suit )
			{
				total_score += score_table[symbol].dominant;
			}
			else
			{
				total_score += score_table[symbol].not_dominant;
			}
		}
	}
	
	cout<<total_score<<'\n';
	
	return	0;
}
