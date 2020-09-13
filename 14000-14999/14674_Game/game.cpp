#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	long long int				int64;
typedef	struct{int i;int64 c,h;}	Game;

bool	is_better(const Game& g1,const Game& g2)
{
	int64	g1_value,g2_value;
	bool	result;
	
	g1_value = g1.h*g2.c;
	g2_value = g2.h*g1.c;
	
	if( g1_value == g2_value )
	{
		if( g1.c == g2.c )
		{
			result = g1.i<g2.i;
		}
		else
		{
			result = g1.c<g2.c;
		}
	}
	else
	{
		result = g1_value>g2_value;
	}
	
	return	result;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N,K;
	vector<Game>	games;
	
	cin>>N>>K;
	
	for(int k=1;k<=N;k++)
	{
		Game	g;
		
		cin>>g.i>>g.c>>g.h;
		games.push_back(g);
	}
	
	sort(games.begin(),games.end(),is_better);
	
	for(int k=0;k<K;k++)
	{
		cout<<games[k].i<<'\n';
	}
	
	return	0;
}
