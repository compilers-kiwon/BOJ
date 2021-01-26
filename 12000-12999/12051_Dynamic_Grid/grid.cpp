#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	100

int		R,C,N,cnt_of_query;
int		visited[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

void	read_grid(void)
{
	cin>>R>>C;
	
	for(int row=0;row<R;row++)
	{
		cin>>&grid[row][0];
	}
}

void	bfs(int s_row,int s_col,int visited_tag)
{
	queue<Pos>	q;
	
	q.push(make_pair(s_row,s_col));
	visited[s_row][s_col] = visited_tag;
	
	for(;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,R) || !IN_RANGE(0,adj_col,C) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]=='0' || visited[adj_row][adj_col]==visited_tag )
			{
				continue;
			}
			
			q.push(make_pair(adj_row,adj_col));
			visited[adj_row][adj_col] = visited_tag;
		}
	}
}

int		get_num_of_connected_region(void)
{
	int	ret;
	
	ret = 0;
	cnt_of_query++;
	
	for(int row=0;row<R;row++)
	{
		for(int col=0;col<C;col++)
		{
			if( grid[row][col]=='1' && visited[row][col]!=cnt_of_query )
			{
				ret++;
				bfs(row,col,cnt_of_query);
			}
		}
	}
	
	return	ret;
}

void	do_query(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		char	op,z;
		int		x,y;
		
		cin>>op;
		
		switch(op)
		{
			case	'M':
				cin>>x>>y>>z;
				grid[x][y] = z;
				break;
			case	'Q':
				cout<<get_num_of_connected_region()<<'\n';
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		read_grid();
		
		cout<<"Case #"<<t<<":\n";
		do_query();
	}
	
	return	0;
}
