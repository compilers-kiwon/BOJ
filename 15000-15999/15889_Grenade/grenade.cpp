#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_SOLDIER	(30000+1)

typedef	pair<int,int>	Soldier;

int		N;
Soldier	s[MAX_NUM_OF_SOLDIER];
bool	visited[MAX_NUM_OF_SOLDIER];

bool	is_reachable_to_the_last_soldier(void)
{
	queue<int>	soldier_q;
	
	soldier_q.push(1);
	visited[1] = true;
	
	while( !soldier_q.empty() )
	{
		int	current_soldier;
		
		current_soldier = soldier_q.front();
		soldier_q.pop();
		
		if( current_soldier == N )
		{
			return	true;
		}
		
		int	max_distance_to_throw;
		
		max_distance_to_throw = s[current_soldier].first+s[current_soldier].second;
		
		for(int i=current_soldier+1;i<=N&&s[i].first<=max_distance_to_throw;i++)
		{
			if( visited[i] == false )
			{
				visited[i] = true;
				soldier_q.push(i);
			}
		}
	}
	
	return	false;
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>s[i].first;
	}
	
	for(int i=1;i<N;i++)
	{
		cin>>s[i].second;
	}
}

int		main(void)
{
	init();
	
	if( N==1 || is_reachable_to_the_last_soldier()==true )
	{
		cout<<"????, ????? ?????\n";
	}
	else
	{
		cout<<"?? ? ?? ??? ? ??\n";
	}
	
	return	0;
}
