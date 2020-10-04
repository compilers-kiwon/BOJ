#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(1000+1)

#define	EMPTY	0
#define	WALL	1

int	N,M,grid[MAX_SIZE][MAX_SIZE];
int	group[MAX_SIZE][MAX_SIZE],g_ptr;
int	area[MAX_SIZE*MAX_SIZE];
int	converted[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	MOD(n)				((n)%10)

typedef	pair<int,int>	Pos;	// first:row,second:col

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=M;col++)
		{
			grid[row][col] = (buf[col]=='0'?EMPTY:WALL);
		}
	}
}

int		bfs(int s_row,int s_col)
{
	int			ret;
	queue<Pos>	pos_q;
	
	group[s_row][s_col] = g_ptr;
	pos_q.push(make_pair(s_row,s_col));
	
	for(ret=1;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]==WALL || group[adj_row][adj_col]!=EMPTY )
			{
				continue;
			}
			
			ret++;
			group[adj_row][adj_col] = g_ptr;
			pos_q.push(make_pair(adj_row,adj_col));
		}
	}
	
	return	ret;
}

void	find_empty_group(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col]==EMPTY && group[row][col]==EMPTY )
			{
				++g_ptr;
				area[g_ptr] = bfs(row,col);
			}
		}
	}
}

bool	is_found(const vector<int>& f,int g)
{
	bool	ret;
	
	ret = false;
	
	for(int i=0;i<f.size();i++)
	{
		if( f[i] == g )
		{
			ret = true;
			break;
		}
	}
	
	return	ret;
}

int		get_adj_area(int row,int col)
{
	int			ret;
	vector<int>	found;
	
	ret = 0;
	
	for(int d=UP;d<=RIGHT;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
		{
			continue;
		}
		
		if( grid[adj_row][adj_col]==WALL || is_found(found,group[adj_row][adj_col])==true )
		{
			continue;
		}
		
		ret += area[group[adj_row][adj_col]];
		found.push_back(group[adj_row][adj_col]);
	}
	
	return	ret;
}

void	convert(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				converted[row][col] = EMPTY;
			}
			else
			{
				converted[row][col] = MOD(get_adj_area(row,col)+1);
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	find_empty_group();
	convert();
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cout<<converted[row][col];
		}
		cout<<'\n';
	}
	
	return	0;
}
