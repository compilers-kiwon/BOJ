#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_NUM_OF_QUESTIONS	(50+1)
#define	MAX_ANSWER_VALUE		5

typedef	int	CowID;

set<CowID>	answered_cows[MAX_NUM_OF_QUESTIONS][MAX_ANSWER_VALUE+1];
int			N,NQ,P;	

void	input(void)
{
	cin>>N>>NQ>>P;
	
	for(int cow_id=1;cow_id<=N;cow_id++)
	{
		for(int question=1;question<=NQ;question++)
		{
			int	ans;
			
			cin>>ans;
			answered_cows[question][ans].insert(cow_id);
		}
	}
}

void	find_cows(int q_ind,set<CowID>& candidates)
{
	if( q_ind > P )
	{
		cout<<candidates.size()<<'\n';
		return;
	}
	
	int			Q,A;
	set<CowID>	next_candidates;
	
	cin>>Q>>A;
	
	set<CowID>::iterator	ci;
	set<CowID>&				ans_cows = answered_cows[Q][A];
	
	for(ci=candidates.begin();ci!=candidates.end();ci++)
	{
		if( ans_cows.find(*ci) != ans_cows.end() )
		{
			next_candidates.insert(*ci);
		}
	}
	
	return	find_cows(q_ind+1,next_candidates);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	set<CowID>	c;
	
	for(int i=1;i<=N;i++)
	{
		c.insert(i);
	}
	
	find_cows(1,c);
	
	return	0;
}
