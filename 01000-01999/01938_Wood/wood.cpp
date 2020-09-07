#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	HORI	0
#define	VERT	1

#define	EMPTY		'0'

const struct{
	int	row,col;
} adj_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	pair<int,int>	p[3];
	int				direction;
	int				num_of_movements;
};

bool	visited[VERT+1][MAX_SIZE][MAX_SIZE];
char	map[MAX_SIZE+1][MAX_SIZE+1];
int		N;

int		move_adj(State& current,State& next,int direction)
{
	bool	flag;
	
	for(int i=0;i<3;i++)
	{
		next.p[i].first = current.p[i].first+adj_dir[direction].row;
		next.p[i].second = current.p[i].second+adj_dir[direction].col;
	}
	
	next.direction = current.direction;
	next.num_of_movements = current.num_of_movements+1;
	
	flag = false;
	
	if( visited[next.direction][next.p[0].first][next.p[0].second] == false )
	{
		flag = true;
		
		for(int i=0;i<3;i++)
		{
			int& row = next.p[i].first;
			int& col = next.p[i].second;
			
			if( map[row][col] != EMPTY )
			{
				flag = false;
				break;
			}
		}
		visited[next.direction][next.p[0].first][next.p[0].second] = flag;
	}
	
	return	flag;
}

bool	turn_dir(State& current,State& next)
{
	int		top,bottom,left,right;
	bool	flag;
	
	if( current.direction == HORI )
	{
		top = current.p[0].first-1;
		bottom = current.p[0].first+1;
		
		left = current.p[0].second;
		right = current.p[2].second;
		
		next.p[0].second = next.p[1].second = next.p[2].second = left+1;
		
		next.p[0].first = top;
		next.p[1].first = top+1;
		next.p[2].first = top+2;
	}
	else
	{
		top = current.p[0].first;
		bottom = current.p[2].first;
		
		left = current.p[0].second-1;
		right = current.p[0].second+1;
		
		next.p[0].first = next.p[1].first = next.p[2].first = top+1;
		
		next.p[0].second = left;
		next.p[1].second = left+1;
		next.p[2].second = left+2;
	}
	
	for(int row=top;row<=bottom;row++)
	{
		for(int col=left;col<=right;col++)
		{
			if( map[row][col] != EMPTY )
			{
				return	false;
			}
		}
	}
	
	next.direction = (current.direction+1)%2;
	next.num_of_movements = current.num_of_movements+1;
	
	flag = false;
	
	if( visited[next.direction][next.p[0].first][next.p[0].second] == false )
	{
		flag = true;
		
		for(int i=0;i<3;i++)
		{
			int& row = next.p[i].first;
			int& col = next.p[i].second;
			
			if( map[row][col] != EMPTY )
			{
				flag = false;
				break;
			}
		}
		visited[next.direction][next.p[0].first][next.p[0].second] = flag;
	}
	
	return	flag;
}

int		main(void)
{
	State	start,end;
	
	scanf("%d",&N);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	int	start_p_index,end_p_index;
	
	start_p_index = end_p_index = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			if( map[row][col] == 'B' )
			{
				start.p[start_p_index].first = row;
				start.p[start_p_index].second = col;
				start_p_index++;
			}
			
			if( map[row][col] == 'E' )
			{
				end.p[end_p_index].first = row;
				end.p[end_p_index].second = col;
				end_p_index++;
			}
		}
	}
	
	if( start.p[0].first == start.p[1].first )
	{
		start.direction = HORI;
	}
	else
	{
		start.direction = VERT;
	}
	
	for(int i=0;i<3;i++)
	{
		map[start.p[i].first][start.p[i].second] = EMPTY;
	}
	
	if( end.p[0].first == end.p[1].first )
	{
		end.direction = HORI;
	}
	else
	{
		end.direction = VERT;
	}
	
	for(int i=0;i<3;i++)
	{
		map[end.p[i].first][end.p[i].second] = EMPTY;
	}
	
	queue<State>	state_q;
	int				cnt;
	
	state_q.push(start);
	state_q.front().num_of_movements = 0;
	visited[start.direction][start.p[0].first][start.p[0].second] = true;
	cnt = 0;
	
	while( state_q.size() != 0 )
	{
		State	current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.direction == end.direction && current.p[0].first == end.p[0].first && current.p[0].second == end.p[0].second )
		{
			cnt = current.num_of_movements;
			break;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			if( move_adj(current,next,i) == true )
			{
				state_q.push(next);
			}
		}
		
		if( turn_dir(current,next) == true )
		{
			state_q.push(next);
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
