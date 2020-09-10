#include	<iostream>
#include	<map>
#include	<vector>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	EAST	0
#define	WEST	1
#define	SOUTH	2
#define	NORTH	3
#define	MAX_DIR	4

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{1,0},{-1,0},{0,-1},{0,1}};

typedef	vector<int>	Visited_X;

map<int,Visited_X>	visited;

bool	is_visited(int x,int y)
{
	vector<int>&	current_x = visited[y];
	
	if( current_x.size() == 0 )
	{
		current_x.push_back(x);
		return	false;
	}
	
	vector<int>::iterator	iter;
	bool					result;
	
	iter = lower_bound(current_x.begin(),current_x.end(),x);
	
	if( iter == current_x.end() || *iter != x )
	{
		result = false;
		current_x.insert(iter,x);
	}
	else
	{
		result = true;
	}
	
	return	result;
}

int		main(void)
{
	int		L,x,y,cnt,i;
	string	instruction;
	
	cin>>L>>instruction;
	
	x = y = 0;
	visited[y].push_back(x);
	
	for(i=0,cnt=1;i<L;i++)
	{
		int	direction;
		
		switch(instruction[i])
		{
			case	'S':
				direction = SOUTH;
				break;
			case	'N':
				direction = NORTH;
				break;
			case	'E':
				direction = EAST;
				break;
			case	'W':
				direction = WEST;
				break;
			default:
				// do nothing
				break;
		}
		
		x = x+adj[direction].dx;
		y = y+adj[direction].dy;
		
		if( is_visited(x,y) == false )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
