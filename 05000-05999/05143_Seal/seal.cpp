#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	MAX_LIFE	3

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:num_of_goops,second:pos

int		x,y;
Pos		seymour;
char	grid[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE][MAX_LIFE+1];

int		count_supplies(void)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=y;row++)
	{
		for(int col=1;col<=x;col++)
		{
			if( grid[row][col] != 'H' )
			{
				continue;
			}
			
			bool	v;
			
			v = false;
			
			for(int i=0;i<=MAX_LIFE;i++)
			{
				v |= visited[row][col][i];
			}
			
			if( v != false )
			{
				ret++;
			}
		}
	}
	
	return	ret;
}

void	bfs(void)
{
	queue<State>	state_q;
	
	state_q.push(make_pair(MAX_LIFE,seymour));
	visited[seymour.first][seymour.second][MAX_LIFE] = true;
	
	for(;!state_q.empty();)
	{
		int	current_life,current_row,current_col;
		
		current_life = state_q.front().first;
		current_row = state_q.front().second.first;
		current_col = state_q.front().second.second;
		
		state_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col,adj_life;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,y) || !IN_RANGE(1,adj_col,x) )
			{
				continue;
			}
			
			switch(grid[adj_row][adj_col])
			{
				case	'G':
					adj_life = current_life-1;
					break;
				case	'P':
					adj_life = MAX_LIFE;
					break;
				default:
					adj_life = current_life;
					break;
			}
			
			if( adj_life>=0 && visited[adj_row][adj_col][adj_life]==false )
			{
				visited[adj_row][adj_col][adj_life] = true;
				state_q.push(make_pair(adj_life,make_pair(adj_row,adj_col)));
			}
		}
	}
}

void	input(void)
{
	cin>>x>>y;
	
	for(int row=1;row<=y;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=x;col++)
		{
			if( grid[row][col] == 'S' )
			{
				seymour = make_pair(row,col);
				grid[row][col] = '.';
			}
			
			for(int i=0;i<=MAX_LIFE;i++)
			{
				visited[row][col][i] = false;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		bfs();
		
		cout<<"Data Set "<<k<<":\n"<<count_supplies()<<"\n\n";
	}
	
	return	0;
}
