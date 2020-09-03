#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_TEAM	(100+1)

typedef	pair<int,int>	Team;

int		N;
Team	t[MAX_NUM_OF_TEAM];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	int	num_of_game,i;
	
	for(i=1;i<=N;i++)
	{
		t[i].first = 0;
		t[i].second = i;
	}
	
	for(i=1,num_of_game=N*(N-1)/2;i<=num_of_game;i++)
	{
		int	A,B,C,D;
		
		cin>>A>>B>>C>>D;
		
		if( C > D )
		{
			t[A].first += 3;
		}
		else if( C < D )
		{
			t[B].first += 3;
		}
		else
		{
			t[A].first++;
			t[B].first++;
		}
	}
	
	stable_sort(&t[1],&t[N+1]);	
}

int		main(void)
{
	init();
	
	int	cnt,rank,team[MAX_NUM_OF_TEAM];
	
	cnt = rank = 1;
	
	team[t[N].second] = rank;
	cnt++;
	
	for(int i=N-1;i>=1;i--)
	{
		if( t[i].first != t[i+1].first )
		{
			rank = cnt;
		}
		
		team[t[i].second] = rank;
		cnt++;
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<team[i]<<'\n';
	}
	
	return	0;
}
