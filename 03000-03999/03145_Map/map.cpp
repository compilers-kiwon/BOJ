#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	VILLAGE		'x'
#define	NONE		0
	
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		R,C,visited[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];
int		map[MAX_SIZE][MAX_SIZE],my_name[MAX_SIZE][MAX_SIZE];
string	all_names[MAX_SIZE*MAX_SIZE];

vector<int>	candidate[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;	// first:row,second:col

Pos	assigned_village[MAX_SIZE*MAX_SIZE];

bool	dfs(int v,int row,int col)
{
	if( visited[row][col] == v )
	{
		return	false;
	}
	
	visited[row][col] = v;
	
	vector<int>&	c = candidate[row][col];
	
	for(int i=0;i<c.size();i++)
	{
		int&	name_idx = c[i];
		
		if( assigned_village[name_idx]==make_pair(0,0)
			|| dfs(v,assigned_village[name_idx].first,assigned_village[name_idx].second) )
		{
			my_name[row][col] = name_idx;
			assigned_village[name_idx] = make_pair(row,col);
			
			return	true;
		}
	}
	
	return	false;
}

bool	find_candidate(const vector<int>& c,const int v)
{
	bool	ret;
	
	ret = false;
	
	for(int i=0;i<c.size();i++)
	{
		if( c[i] == v )
		{
			ret = true;
			break;
		}
	}
	
	return	ret;
}

void	find_possible_name(int row,int col)
{
	vector<int>&	c = candidate[row][col];
	
	for(int d_row=-1;d_row<=1;d_row++)
	{
		for(int d_col=-1;d_col<=1;d_col++)
		{
			int	adj_row,adj_col;
			
			adj_row = row+d_row;
			adj_col = col+d_col;
			
			if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
			{
				continue;
			}
			
			if( map[adj_row][adj_col]!=NONE 
				&& find_candidate(c,map[adj_row][adj_col])==false )
			{
				c.push_back(map[adj_row][adj_col]);
			}
		}
	}
}

void	get_name(void)
{
	int	ptr;
	
	ptr = 1;
	
	for(int row=1;row<=R;row++)
	{
		vector<int>	pos;
		
		for(int col=1;col<=C+1;col++)
		{
			if( IN_RANGE('A',grid[row][col],'Z') )
			{
				pos.push_back(col);
				all_names[ptr].push_back(grid[row][col]);
			}
			else
			{
				if( !pos.empty() )
				{
					for(int i=0;i<pos.size();i++)
					{
						map[row][pos[i]] = ptr;
					}
				}
				
				pos.clear();
				ptr++;
			}
		}
	}
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
	}
	
	get_name();
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == VILLAGE )
			{
				find_possible_name(row,col);
			}
		}
	}
	
	for(int row=1,v=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == VILLAGE )
			{
				dfs(v,row,col);
				v++;
			}
		}
	}
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( grid[row][col] == VILLAGE )
			{
				cout<<row<<' '<<col<<' '<<all_names[my_name[row][col]]<<'\n';
			}
		}
	}
	
	return	0;
}
