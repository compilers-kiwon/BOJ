#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	OFFSET		500
#define	IN_RANGE(n)	(0<=(n)&&(n)<MAX_SIZE)

#define	START_X	(0+OFFSET)
#define	START_Y	(0+OFFSET)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{1,0},{-1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:num_of_steps,second:Pos

int		X,Y,N;
bool	visited[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin>>X>>Y>>N;
	
	X += OFFSET;
	Y += OFFSET;
	
	for(int i=1;i<=N;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		visited[B+OFFSET][A+OFFSET] = true;
	}
}

int		move(void)
{
	queue<State>	state_q;
	int				ret;
	
	visited[START_Y][START_X] = true;
	state_q.push(make_pair(0,make_pair(START_Y,START_X)));
	
	for(;!state_q.empty();)
	{
		int	current_step,current_row,current_col;
		
		current_step = state_q.front().first;
		current_row = state_q.front().second.first;
		current_col = state_q.front().second.second;
		
		state_q.pop();
		
		if( current_row==Y && current_col==X )
		{
			ret = current_step;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(adj_row) && IN_RANGE(adj_col) )
			{
				if( visited[adj_row][adj_col] == false )
				{
					visited[adj_row][adj_col] = true;
					state_q.push(make_pair(current_step+1,make_pair(adj_row,adj_col)));
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	cout<<move()<<'\n';
	
	return	0;
}
