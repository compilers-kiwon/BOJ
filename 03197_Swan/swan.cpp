#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1500+1)
#define	MAX_SWAN	2
#define	MAX_DAY		(1500-2)
#define	UNKNOWN		0x7FFFFFFF

typedef	pair<int,int>	Pos;	// first:row,second:col

int			R,C,grid[MAX_SIZE][MAX_SIZE];
int			visited[MAX_SIZE][MAX_SIZE];
Pos			swan[MAX_SWAN];
vector<Pos>	ice_to_melt[MAX_DAY];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	input(queue<Pos>& w)
{
	int	swan_ptr;
	
	cin>>R>>C;
	swan_ptr = 0;
	
	for(int row=1;row<=R;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		
		for(int col=1;col<=C;col++)
		{
			char&	c = buf[col];
			
			switch(c)
			{
				case	'.':
				case	'L':
					grid[row][col] = 0;
					w.push(make_pair(row,col));
					
					if( c == 'L' )
					{
						swan[swan_ptr++] = make_pair(row,col);
					}
					break;
				case	'X':
					grid[row][col] = UNKNOWN;
					break;
				default :
					// do nothing
					break;
			}
		}
		
		fill(&visited[row][1],&visited[row][C+1],-1);
	}
}

void	init(queue<Pos>& w)
{
	for(int today=0;!w.empty();today++)
	{
		for(int i=1,size=w.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = w.front().first;
			current_col = w.front().second;
			
			w.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
				{
					continue;
				}
				
				int&	day_for_ice_to_melt = grid[adj_row][adj_col];
				
				if( day_for_ice_to_melt == UNKNOWN )
				{
					day_for_ice_to_melt = today+1;
					w.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

bool	bfs(int day)
{
	queue<Pos>	swan_q;
	
	swan_q.push(swan[0]);
	visited[swan[0].first][swan[0].second] = day;
	
	for(;!swan_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = swan_q.front().first;
		current_col = swan_q.front().second;
		
		swan_q.pop();
		
		if( current_row==swan[1].first && current_col==swan[1].second )
		{
			return	true;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]<=day && visited[adj_row][adj_col]!=day )
			{
				visited[adj_row][adj_col] = day;
				swan_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	return	false;
}

int		bin_search(int lo,int hi)	// lo:impossible,hi:possible
{
	if( lo+1 == hi )
	{
		return	hi;
	}
	
	int		mid;
	bool	result;
	
	mid = (lo+hi)/2;
	result = bfs(mid);
	
	if( result == true )
	{
		hi = mid;
	}
	else
	{
		lo = mid;
	}
	
	return	bin_search(lo,hi);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	queue<Pos>	water_q;
	
	input(water_q);
	init(water_q);
	
	cout<<bin_search(-1,MAX_DAY)<<'\n';
	
	return	0;
}
