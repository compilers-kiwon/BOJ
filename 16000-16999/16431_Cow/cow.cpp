#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			1000
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MAX_OFFSET			2

bool	visited[MAX_OFFSET+1][MAX_SIZE+1][MAX_SIZE+1];

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

#define	B_offset	1
#define	D_offset	2

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef	pair<int,int>		RowCol;
typedef	pair<int,RowCol>	State;

int		find_shortest_path(int s_row,int s_col,int e_row,int e_col,int cow_offset)
{
	queue<State>	state_q;
	int				min_time;
	
	state_q.push(make_pair(0,make_pair(s_row,s_col)));
	visited[cow_offset][s_row][s_col] = true;
	
	while( !state_q.empty() )
	{
		int	current_time,current_row,current_col;
		
		current_time = state_q.front().first;
		current_row = state_q.front().second.first;
		current_col = state_q.front().second.second;
		
		state_q.pop();
		
		if( current_row==e_row && current_col==e_col )
		{
			min_time = current_time;
			break;
		}
		
		int	next_time,next_row,next_col;
		
		next_time = current_time+1;
		
		for(int d=UP;d<MAX_DIR;d+=cow_offset)
		{
			next_row = current_row+adj[d].d_row;
			next_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,next_row,MAX_SIZE) && IN_RANGE(1,next_col,MAX_SIZE) )
			{
				if( visited[cow_offset][next_row][next_col] == false )
				{
					visited[cow_offset][next_row][next_col] = true;
					state_q.push(make_pair(next_time,make_pair(next_row,next_col)));
				}
			}
		}
	}
	
	return	min_time;
}

int	main(void)
{
	int	B_row,B_col,D_row,D_col,J_row,J_col;
	int	B_time,D_time;
	
	cin>>B_row>>B_col>>D_row>>D_col>>J_row>>J_col;
	
	B_time = find_shortest_path(B_row,B_col,J_row,J_col,B_offset);
	D_time = find_shortest_path(D_row,D_col,J_row,J_col,D_offset);
	
	if( B_time > D_time )
	{
		cout<<"daisy\n";
	}
	else if( B_time < D_time )
	{
		cout<<"bessie\n";
	}
	else
	{
		cout<<"tie\n";
	}
	
	return	0;
}
