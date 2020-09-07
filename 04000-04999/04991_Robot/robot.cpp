#include	<iostream>
#include	<vector>
#include	<queue>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(20+1)
#define	MAX_DIRTY	10
#define	INF			(MAX_SIZE*MAX_SIZE*MAX_SIZE)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	ROBOT	'o'
#define	DIRTY	'*'
#define	WALL	'x'
#define	EMPTY	'.'

int		w,h,graph[MAX_DIRTY][MAX_DIRTY],robot_to_dirty[MAX_DIRTY];
char	grid[MAX_SIZE][MAX_SIZE+1],tmp_grid[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;	// first:row,second:col

Pos	robot,dirty[MAX_DIRTY];

#define	ROBOT_IDX	0

#define	ALL_DIRTY(N)	((1<<(N))-1)
#define	is_removed(d,c)	(((d)&(1<<(c)))!=0)

bool	input(int& cnt_of_dirty)
{
	cin>>w>>h;
	
	if( w==0 && h==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=h;row++)
	{
		fill(&tmp_grid[row][1],&tmp_grid[row][w+1],EMPTY);
	}
	
	cnt_of_dirty = 0;
	
	for(int row=1;row<=h;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=w;col++)
		{
			char&	c = grid[row][col];
			
			switch(c)
			{
				case	ROBOT:
					robot = make_pair(row,col);
					break;
				case	DIRTY:
					dirty[cnt_of_dirty++] = make_pair(row,col);
					break;
				case	WALL:
					tmp_grid[row][col] = WALL;
					break;
				default:
					// do nothing
					break;
			}
		}
	}
	
	return	true;
}

int		is_reachable(Pos& from,Pos& to)
{
	bool		visited[MAX_SIZE][MAX_SIZE];
	queue<Pos>	pos_q;
	
	for(int row=1;row<=h;row++)
	{
		fill(&visited[row][1],&visited[row][w+1],false);
	}
	
	visited[from.first][from.second] = true;
	pos_q.push(from);
	
	for(int step=0;!pos_q.empty();step++)
	{
		int	size_of_q;
		
		size_of_q = pos_q.size();
		
		for(int i=1;i<=size_of_q;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			if( current_row==to.first && current_col==to.second )
			{
				return	step;
			}
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !IN_RANGE(1,adj_row,h) || !IN_RANGE(1,adj_col,w) )
				{
					continue;
				}
				
				if( tmp_grid[adj_row][adj_col]==EMPTY && visited[adj_row][adj_col]==false )
				{
					visited[adj_row][adj_col] = true;
					pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
	
	return	INF;
}

bool	build_graph(int& num_of_dirty)
{
	for(int i=0;i<num_of_dirty;i++)
	{
		graph[i][i] = 0;
		
		for(int j=i+1;j<num_of_dirty;j++)
		{
			graph[i][j] = graph[j][i] = is_reachable(dirty[i],dirty[j]);
		}
		
		robot_to_dirty[i] = is_reachable(robot,dirty[i]);
		
		if( robot_to_dirty[i] == INF )
		{
			return	false;
		}
	}

	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	num_of_dirty;
		
		if( input(num_of_dirty) == false )
		{
			break;
		}
		
		if( num_of_dirty == 0 )
		{
			cout<<"0\n";
			continue;
		}
		
		if( build_graph(num_of_dirty) == false )
		{
			cout<<"-1\n";
			continue;	
		}
		
		int			result;
		vector<int>	order_to_clean;
		
		for(int i=0;i<num_of_dirty;i++)
		{
			order_to_clean.push_back(i);
		}
		
		result = INF;
		
		do{
			int	sum;
			
			sum = 0;
			
			for(int i=0;i<order_to_clean.size()-1;i++)
			{
				int&	from = order_to_clean[i];
				int&	to = order_to_clean[i+1];
				
				sum += graph[from][to];
			}
			sum += robot_to_dirty[order_to_clean[0]];
			result = min(result,sum);
			
		}while(next_permutation(order_to_clean.begin(),order_to_clean.end()));
		
		cout<<result<<'\n';
		
	}
	
	return	0;
}
