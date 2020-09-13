#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_CRASH	10

#define	EMPTY	'0'
#define	WALL	'1'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

int		min_movement_table[MAX_SIZE][MAX_SIZE][MAX_CRASH+1];
char	map[MAX_SIZE][MAX_SIZE+1];

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	row,col,available_crash,num_of_movement;
};

int	find_shortest_path(int max_row,int max_col,int max_crash)
{
	State			init;
	queue<State>	state_queue;
	int				min_movement;
		
	init.row = init.col = 1;
	init.available_crash = max_crash;
	init.num_of_movement = 1;
	
	min_movement = 0x7FFFFFFF;
	min_movement_table[1][1][0] = 1;
	state_queue.push(init);
	
	while( state_queue.size() != 0 )
	{
		State	current,next;
		
		current = state_queue.front();
		state_queue.pop();
		
		if( current.row == max_row && current.col == max_col )
		{
			min_movement = min(min_movement,current.num_of_movement);
			continue;
		}
		
		next.num_of_movement = current.num_of_movement+1;
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int&	next_row = next.row;
			int&	next_col = next.col;
			
			next_row = current.row+adj[i].d_row;
			next_col = current.col+adj[i].d_col;
			
			next.available_crash = current.available_crash;
			
			if( IN_RANGE(1,next_row,max_row) && IN_RANGE(1,next_col,max_col) )
			{
				if( map[next_row][next_col] == WALL )
				{
					if( next.available_crash == 0 )
					{
						continue;
					}
					else
					{
						next.available_crash--;
					}
				}
				
				if( min_movement_table[next_row][next_col][next.available_crash] == 0 ||
					next.num_of_movement < min_movement_table[next_row][next_col][next.available_crash] )
				{
					min_movement_table[next_row][next_col][next.available_crash] = next.num_of_movement;
					state_queue.push(next);
				}
			}
		}
	}
	
	return	min_movement;
}

int		main(void)
{
	int	N,M,K,answer;
	
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
	}
	
	answer = find_shortest_path(N,M,K);
	
	if( answer == 0x7FFFFFFF )
	{
		answer = -1;
	}
	
	cout<<answer<<endl;
	
	return	0;
}
