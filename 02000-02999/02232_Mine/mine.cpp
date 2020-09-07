#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50000+1)

typedef	pair<int,int>	Mine;	// first:power, second:index

int		N,mine_power[MAX_SIZE];
bool	removed[MAX_SIZE];

priority_queue<Mine>	pq;
priority_queue<int>		answer;

void	init(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>mine_power[i];
		pq.push(make_pair(mine_power[i],i));
	}
}

void	explode(void)
{
	while( !pq.empty() )
	{
		int	current_mine_power,current_mine_index;
		
		current_mine_index = pq.top().second;
		
		pq.pop();
		
		if( removed[current_mine_index] == true )
		{
			continue;
		}
		
		removed[current_mine_index] = true;
		answer.push(-current_mine_index);
		
		for(int prev_mine_power=mine_power[current_mine_index],i=current_mine_index+1;i<=N;i++)
		{
			current_mine_power = mine_power[i];
			
			if( prev_mine_power <= current_mine_power )
			{
				break;
			}
			
			removed[i] = true;
			prev_mine_power = current_mine_power;
		}
		
		for(int prev_mine_power=mine_power[current_mine_index],i=current_mine_index-1;i>=1;i--)
		{
			current_mine_power = mine_power[i];
			
			if( prev_mine_power <= current_mine_power )
			{
				break;
			}
			
			removed[i] = true;
			prev_mine_power = current_mine_power;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	explode();
	
	while( !answer.empty() )
	{
		cout<<-answer.top()<<'\n';
		answer.pop();
	}
	
	return	0;
}
