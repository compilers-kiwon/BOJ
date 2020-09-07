#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_LITER		(200+1)
#define	NUM_OF_BOTTLES	3

bool	visited[MAX_LITER][MAX_LITER][MAX_LITER];
int		bottle_info[NUM_OF_BOTTLES+1];

typedef	struct	_STATE	State;
struct	_STATE
{
	int	bottle[NUM_OF_BOTTLES+1];
};

bool	pour(int from_index,int to_index,State current_state,State& next_state)
{
	if( current_state.bottle[from_index] == 0 )
	{
		return	false;
	}
	
	int	empty_of_to_bottle = bottle_info[to_index]-current_state.bottle[to_index];
	
	if( empty_of_to_bottle == 0 )
	{
		return	false;
	}
	
	if( current_state.bottle[from_index] <= empty_of_to_bottle )
	{
		next_state.bottle[from_index] = 0;
		next_state.bottle[to_index] = current_state.bottle[to_index]+current_state.bottle[from_index];
	}
	else
	{
		next_state.bottle[to_index] = bottle_info[to_index];
		next_state.bottle[from_index] = current_state.bottle[from_index]-empty_of_to_bottle; 	
	}
	
	return	true; 
}

int		main(void)
{
	queue<State>	bottles;
	State			init;
	
	cin>>bottle_info[1]>>bottle_info[2]>>bottle_info[3];
	
	init.bottle[1] = 0;
	init.bottle[2] = 0;
	init.bottle[3] = bottle_info[3];
	
	bottles.push(init);
	visited[init.bottle[1]][init.bottle[2]][init.bottle[3]] = true;
	
	while( bottles.size() != 0 )
	{
		State current_state;
		
		current_state = bottles.front();		
		bottles.pop();
		
		for(int from=1;from<=3;from++)
		{
			for(int to=1;to<=3;to++)
			{
				if( from == to )
				{
					continue;
				}
				
				State	new_state = current_state;
				
				if( pour(from,to,current_state,new_state) != false )
				{
					if( visited[new_state.bottle[1]][new_state.bottle[2]][new_state.bottle[3]] == false )
					{
						bottles.push(new_state);
						visited[new_state.bottle[1]][new_state.bottle[2]][new_state.bottle[3]] = true;
					}
				}
			}
		}
	}
	
	for(int i=0;i<=bottle_info[3];i++)
	{
		for(int j=0;j<=bottle_info[2];j++)
		{
			if( visited[0][j][i] == true )
			{
				cout<<i<<' ';
				break;
			}
		}
	}
	cout<<endl;
	
	return	0;
}
