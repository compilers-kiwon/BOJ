#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_FLOORS	(1000000+1)

vector<bool>			visited(MAX_NUM_OF_FLOORS,false);
queue< pair<int,int> >	floor_q;
int	F,S,G,U,D;

int	main(void)
{
	cin>>F>>S>>G>>U>>D;
	
	int		answer = -1;
	
	visited[S] = true;
	floor_q.push(make_pair(0,S));
	
	while( floor_q.size() != 0 )
	{
		int	current_floor,current_num_of_buttons;
		
		current_num_of_buttons = floor_q.front().first;
		current_floor = floor_q.front().second;
		floor_q.pop();
		
		if( current_floor == G )
		{
			answer = current_num_of_buttons;
			break;
		}
		
		int	next_floor;
		
		next_floor = current_floor+U;
		if( next_floor <= F && visited[next_floor] == false )
		{
			visited[next_floor] = true;
			floor_q.push(make_pair(current_num_of_buttons+1,next_floor));
		}
		
		next_floor = current_floor-D;
		if( next_floor >= 1 && visited[next_floor] == false )
		{
			visited[next_floor] = true;
			floor_q.push(make_pair(current_num_of_buttons+1,next_floor));
		}
	}
	
	if( answer == -1 )
	{
		cout<<"use the stairs\n";
	}
	else
	{
		cout<<answer<<endl;
	}
	
	return	0;
} 	
