#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

#define	WEST	0
#define	NORTH	1
#define	EAST	2
#define	SOUTH	3
#define	MAX_DIR	4

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{0,-1},{-1,0},{0,1},{1,0}};

#define	MAX_SIZE	(50+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

int	visited[MAX_SIZE][MAX_SIZE];
int	castle[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	RowCol;

void	mark_cell_with_size(int row,int col,int current_row,int current_col,int& current_size,vector<RowCol>& connected)
{
	for(int i=WEST;i<=SOUTH;i++)
	{
		int&	current_cell = castle[current_row][current_col];
		
		if( (current_cell&(1<<i)) != 0 )
		{
			continue;
		}
		
		int	adj_row,adj_col;
		
		adj_row = current_row+adj[i].d_row;
		adj_col = current_col+adj[i].d_col;
		
		if( IN_RANGE(1,adj_row,row) && IN_RANGE(1,adj_col,col) )
		{
			if( visited[adj_row][adj_col] == FALSE )
			{
				current_size++;
				visited[adj_row][adj_col] = TRUE;
				mark_cell_with_size(row,col,adj_row,adj_col,current_size,connected);
			}
		}
	}
	connected.push_back(make_pair(current_row,current_col));
}

int		main(void)
{
	int	m,n;
	
	cin>>m>>n;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			cin>>castle[row][col];
		}
	}
	
	int	max_room_size,cnt,max_size_of_merged_room;
	
	map<int,int>	room_size_table;
	
	max_room_size = cnt = max_size_of_merged_room = 0;
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			if( visited[row][col] == FALSE )
			{
				int				room_size;
				vector<RowCol>	connected;
				
				cnt++;
				room_size = 1;
				visited[row][col] = TRUE;
				
				mark_cell_with_size(n,m,row,col,room_size,connected);
				
				for(int i=0;i<connected.size();i++)
				{
					int	r,c;
					
					r = connected[i].first;
					c = connected[i].second;
					
					visited[r][c] = cnt;
				}
				room_size_table[cnt] = room_size;
				
				max_room_size = max(max_room_size,room_size);
			}
		}
	}
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			int&	current_room_number = visited[row][col];
			
			for(int i=WEST;i<=SOUTH;i++)
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[i].d_row;
				adj_col = col+adj[i].d_col;
				
				if( IN_RANGE(1,adj_row,n) && IN_RANGE(1,adj_col,m) )
				{
					if( current_room_number != visited[adj_row][adj_col] )
					{
						max_size_of_merged_room = max(max_size_of_merged_room,room_size_table[current_room_number]+room_size_table[visited[adj_row][adj_col]]);
					}
				}
			}
		}
	}
	
	cout<<cnt<<endl<<max_room_size<<endl<<max_size_of_merged_room<<endl;
	
	return	0;
}
