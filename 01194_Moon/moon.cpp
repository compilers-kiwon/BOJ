#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	NUM_OF_KEYS	6
#define	MAX_KEY		(1<<NUM_OF_KEYS)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	is_key(c)			IN_RANGE('a',(c),'f')
#define	is_door(c)			IN_RANGE('A',(c),'F')
#define	is_wall(c)			((c)=='#')
#define	is_empty(c)			((c)=='.')
#define	is_minsik(c)		((c)=='0')
#define	is_exit(c)			((c)=='1')

#define	get_key_index(k)	((int)((k)-'a'))
#define	get_door_index(d)	((int)((d)-'A'))

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:keys_in_hands,second:Pos
typedef	pair<int,State>	Step;	// first:-num_of_steps,second:State

int			N,M;
char		maze[MAX_SIZE][MAX_SIZE+1];
Pos			minsik;
vector<int>	dp[MAX_SIZE][MAX_SIZE];

#define		get_dp(r,c,k)	(dp[(r)][(c)][(k)])
#define		set_dp(r,c,k,v)	(dp[(r)][(c)][(k)]=v)

void	input(void)
{
	scanf("%d %d",&N,&M);
	
	for(int row=1;row<=N;row++)
	{
		scanf("%s",&maze[row][1]);
		
		for(int col=1;col<=M;col++)
		{
			char&	c = maze[row][col];
			
			if( is_minsik(c) == true )
			{
				c = '.';
				minsik = make_pair(row,col);
			}
			
			if( is_wall(c) == false )
			{
				dp[row][col].resize(MAX_KEY,0x7FFFFFFF);
			}
		}
	}
}

int		escape(void)
{
	priority_queue<Step>	pq;
	
	pq.push(make_pair(0,make_pair(0,minsik)));
	dp[minsik.first][minsik.second][0] = 0;
	
	for(;!pq.empty();)
	{
		int	current_row,current_col,current_steps,current_keys;
		
		current_steps = -pq.top().first;
		current_keys = pq.top().second.first;
		current_row = pq.top().second.second.first;
		current_col = pq.top().second.second.second;
		
		pq.pop();
		
		if( is_exit(maze[current_row][current_col]) == true )
		{
			return	current_steps;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col,adj_steps,adj_keys;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			adj_steps = current_steps+1;
			adj_keys = current_keys;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			char&	c = maze[adj_row][adj_col];
			
			if( is_wall(c) == true )
			{
				continue;
			}
			
			if( is_key(c) == true )
			{
				adj_keys |= 1<<get_key_index(c);
			}
			
			if( is_door(c) == true )
			{
				int	necessary_key;
				
				necessary_key = get_door_index(c);
				
				if( (adj_keys&(1<<necessary_key)) == 0 )
				{
					continue;
				}
			}
			
			if( adj_steps < get_dp(adj_row,adj_col,adj_keys) )
			{
				set_dp(adj_row,adj_col,adj_keys,adj_steps);
				pq.push(make_pair(-adj_steps,make_pair(adj_keys,make_pair(adj_row,adj_col))));
			}
		}
	}
	
	return	-1;
}

int		main(void)
{
	input();	
	printf("%d\n",escape());
	
	return	0;
}
