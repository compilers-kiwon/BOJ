#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_HEIGHT	(1000+1)

typedef	pair<int,int>	Pos;	// first:row,second:col

int	n,m,grid[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	input(int& max_height,int& min_height)
{
	cin>>n>>m;
	
	if( n==0 && m==0 )
	{
		return	false;
	}
	
	max_height = 0;
	min_height = MAX_HEIGHT;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			int&	h = grid[row][col];
			
			cin>>h;			
			max_height = max(max_height,h);
			
			if( row==1 || row==n || col==1 || col==m )
			{
				min_height = min(min_height,h);
			}
		}
	}
	
	return	true;
}

void	simulate(queue<Pos>& pos_q,const int& flood_height,bool visited[][MAX_SIZE])
{
	for(;!pos_q.empty();)
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
			
			if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,m) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]<=flood_height && visited[adj_row][adj_col]==false )
			{
				visited[adj_row][adj_col] = true;
				pos_q.push(make_pair(adj_row,adj_col));
			} 
		}
	}
}

void	ocean_rise(int flood_height,queue<Pos>& f,bool visited[][MAX_SIZE])
{
	for(int col=1;col<=m;col++)
	{
		if( grid[1][col] <= flood_height ) f.push(make_pair(1,col)),visited[1][col]=true;
		if( grid[n][col] <= flood_height ) f.push(make_pair(n,col)),visited[n][col]=true;
	}
	
	for(int row=2;row<n;row++)
	{
		if( grid[row][1] <= flood_height ) f.push(make_pair(row,1)),visited[row][1]=true;
		if( grid[row][m] <= flood_height ) f.push(make_pair(row,m)),visited[row][m]=true;
	}
}

void	bfs(int s_row,int s_col,bool visited[][MAX_SIZE])
{
	queue<Pos>	pos_q;
	
	visited[s_row][s_col] = true;
	pos_q.push(make_pair(s_row,s_col));
	
	for(;!pos_q.empty();)
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
			
			if( !IN_RANGE(1,adj_row,n) || !IN_RANGE(1,adj_col,m) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == false )
			{
				visited[adj_row][adj_col] = true;
				pos_q.push(make_pair(adj_row,adj_col));
			} 
		}
	}
}

bool	is_splitted(bool visited[][MAX_SIZE])
{
	int cnt;
	
	cnt = 0;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			if( visited[row][col] == false )
			{
				if( cnt != 0 )
				{
					return	true;
				}
				else
				{
					bfs(row,col,visited);
					cnt = 1;
				}
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int t=1;;t++)
	{
		int	max_height,min_height,solution;

		if( input(max_height,min_height) == false )
		{
			break;
		}
	
		solution = 0;
		
		for(int flood=min_height;flood<=max_height;flood++)
		{
			queue<Pos>	pos_q;
			bool		visited[MAX_SIZE][MAX_SIZE];
			
			for(int row=1;row<=n;row++)
			{
				fill(&visited[row][1],&visited[row][m+1],false);
			}
			
			ocean_rise(flood,pos_q,visited);
			simulate(pos_q,flood,visited);
			
			if( is_splitted(visited) == true )
			{
				solution = flood;
				break;
			}
		}
		
		if( solution == 0 )
		{
			cout<<"Case "<<t<<": Island never splits.\n";
		}
		else
		{
			cout<<"Case "<<t<<": Island splits when ocean rises "<<solution<<" feet.\n";
		}
	}
	
	return	0;
}
