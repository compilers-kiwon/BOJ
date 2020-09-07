#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(20000+1)

typedef	pair<int,string>	Word;

int		N;
Word	w[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N,prev_idx;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>w[i].second;
		w[i].first = w[i].second.length();
	}
	
	sort(&w[1],&w[N+1]);
	prev_idx = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( w[i].first!=w[prev_idx].first || w[i].second!=w[prev_idx].second )
		{
			cout<<w[i].second<<'\n';
			prev_idx = i;
		}
	}
	
	return	0;
}
