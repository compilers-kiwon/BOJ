#include	<iostream>
#include	<string>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_GRID_SIZE	(100+1)

#define	TREE	'T'
#define	EMPTY	'.'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;

void	input(int& row_size,int& col_size,vector<string>& grid)
{
	cin>>row_size>>col_size;
	grid.resize(row_size+1);
	
	for(int row=1;row<=row_size;row++)
	{
		cin>>grid[row];
		grid[row].insert(grid[row].begin(),' ');
	}
}

bool	is_adj_empty(Pos p,vector<string>& g,int row_size,int col_size)
{
	bool	found;
	int		d;
	
	for(found=false,d=UP;d<=RIGHT&&found!=true;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = p.first+adj[d].d_row;
		adj_col = p.second+adj[d].d_col;
		
		if( !IN_RANGE(1,adj_row,row_size) || !IN_RANGE(1,adj_col,col_size) || g[adj_row][adj_col]==EMPTY )
		{
			found = true;
		}
	}
	
	return	found;
}

int		modeling(vector<string>& grid,vector<int>* m,int row_size,int col_size)
{
	queue<Pos>	tree_q;
	int			max_cnt;
	
	max_cnt = 0;
	
	for(int row=1;row<=row_size;row++)
	{
		m[row].resize(col_size+1,0);
		
		for(int col=1;col<=col_size;col++)
		{
			if( grid[row][col] == 'T' )
			{
				tree_q.push(make_pair(row,col));
			}
		}
	}
	
	for(int r=1;!tree_q.empty();r++)
	{
		vector<Pos>	ring_vec;
		
		for(int i=1,size=tree_q.size();i<=size;i++)
		{
			Pos	current;
			
			current = tree_q.front();
			tree_q.pop();
			
			if( is_adj_empty(current,grid,row_size,col_size) == true )
			{
				ring_vec.push_back(current);
			}
			else
			{
				tree_q.push(current);
			}
		}
		
		for(int i=0;i<ring_vec.size();i++)
		{
			int&	row = ring_vec[i].first;
			int&	col = ring_vec[i].second;
			
			m[row][col] = r;
			grid[row][col] = EMPTY;
		}
		
		max_cnt = r;
	}
	
	return	max_cnt;
}

int		main(void)
{
	int				n,m,max_level;
	vector<string>	grid;
	vector<int>		tree_model[MAX_GRID_SIZE];
	
	input(n,m,grid);
	max_level = modeling(grid,tree_model,n,m);
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			cout<<'.';
			
			if( max_level != 0 )
			{
				if( max_level < 10 )
				{
					if( tree_model[row][col] == 0 )
					{
						cout<<'.';
					}
					else
					{
						cout<<tree_model[row][col];
					}
				}
				else
				{
					if( tree_model[row][col] == 0 )
					{
						cout<<"..";
					}
					else if( tree_model[row][col] < 10 )
					{
						cout<<'.'<<tree_model[row][col];
					}
					else
					{
						cout<<tree_model[row][col];
					}
				}
			}
		}
		cout<<'\n';
	}
	
	return	0;
}
