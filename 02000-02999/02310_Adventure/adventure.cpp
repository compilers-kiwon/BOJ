#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_ROOM	(1000+1)
#define	MAX_GOLD	(500+1)

typedef	struct	_ROOM_INFO	Room;
struct	_ROOM_INFO
{
	char		type;
	int			gold;
	vector<int>	adj_room;
};

typedef	pair<int,int>	State;	// first:current_room,second:current_gold

bool	input(int& num_of_rooms,vector<Room>& r)
{
	cin>>num_of_rooms;
	
	if( num_of_rooms == 0 )
	{
		return	false;
	}
	
	r.resize(num_of_rooms+1);
	
	for(int i=1;i<=num_of_rooms;i++)
	{
		Room&	current = r[i];
		
		cin>>current.type>>current.gold;
		
		for(;;)
		{
			int	c;
			
			cin>>c;
			
			if( c == 0 )
			{
				break;
			}
			
			current.adj_room.push_back(c);
		}
	}
	
	return	true;
}

bool	explore(const int& num_of_rooms,const vector<Room>& r)
{
	queue<State>	state_q;
	vector<bool>	visited[num_of_rooms+1];
	
	for(int i=1;i<=num_of_rooms;i++)
	{
		visited[i].resize(MAX_GOLD,false);
	}
	
	state_q.push(make_pair(1,0));
	visited[1][0] = true;
	
	for(;!state_q.empty();)
	{
		int	current_room,current_gold;
		
		current_room = state_q.front().first;
		current_gold = state_q.front().second;
		
		state_q.pop();
				
		switch(r[current_room].type)
		{
			case	'L':
				current_gold = max(current_gold,r[current_room].gold);
				break;
			case	'T':
				current_gold -= r[current_room].gold;
				break;
			case	'E':
			default :
				// do nothing
				break;
		}
		
		if( current_gold < 0 )
		{
			continue;
		}
		
		if( current_room == num_of_rooms )
		{
			return	true;
		}
		
		for(int i=0;i<r[current_room].adj_room.size();i++)
		{
			int	adj_room_idx = r[current_room].adj_room[i];
			
			if( visited[adj_room_idx][current_gold] == false )
			{
				visited[adj_room_idx][current_gold] = true;
				state_q.push(make_pair(adj_room_idx,current_gold));
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				N;
		vector<Room>	rooms;
		
		if( input(N,rooms) == false )
		{
			break;
		}
		
		if( explore(N,rooms) == true )
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	
	return	0;
}
