#include	<iostream>
#include	<cmath>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Coordinate;

#define	MAX_NUM_OF_STORES	(100+1)
#define	MAX_DISTANCE		(50*20)

#define	GET_DISTANCE(from,to)	(abs((from).first-(to).first)+abs((from).second-(to).second))

Coordinate	store[MAX_NUM_OF_STORES],home,festival;
bool		visited[MAX_NUM_OF_STORES];
int			n;

void	input(void)
{
	cin>>n>>home.first>>home.second;
	
	for(int i=1;i<=n;i++)
	{
		cin>>store[i].first>>store[i].second;
		visited[i] = false;
	}
	
	cin>>festival.first>>festival.second;
}

bool	go_to_festival(void)
{
	queue<Coordinate>	store_q;
	
	store_q.push(home);
	
	while( store_q.size() != 0 )
	{
		Coordinate	current;
		
		current = store_q.front();
		store_q.pop();
		
		if( GET_DISTANCE(current,festival) <= MAX_DISTANCE )
		{
			return	true;
		}
		
		for(int i=1;i<=n;i++)
		{
			
			if( visited[i] == false )
			{
				if( GET_DISTANCE(current,store[i]) <= MAX_DISTANCE )
				{
					visited[i] = true;
					store_q.push(store[i]);
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		input();
		
		if( go_to_festival() == true )
		{
			cout<<"happy\n";
		}
		else
		{
			cout<<"sad\n";
		}
		
		T--;
	}
	
	return	0;
}
