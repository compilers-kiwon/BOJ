#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	FALSE		0
#define	TRUE		1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	N,L,R;
int	map[MAX_SIZE][MAX_SIZE],visited[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	RowCol;

void	init_visited(void)
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			visited[i][j] = FALSE;
		}
	}
}

int		migration(int row,int col,int union_index)
{
	queue<RowCol>	rc_q;
	
	int	num_of_nations_in_union,num_of_population_in_union;
	
	rc_q.push(make_pair(row,col));
	visited[row][col] = union_index;
	
	num_of_nations_in_union = 1;
	num_of_population_in_union = map[row][col];
	
	while( !rc_q.empty() )
	{
		int	current_row,current_col,current_population;
		
		current_row = rc_q.front().first;
		current_col = rc_q.front().second;
		current_population = map[current_row][current_col];
		
		rc_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) && visited[adj_row][adj_col]==FALSE )
			{
				int&	adj_population = map[adj_row][adj_col];
				
				if( current_population!=adj_population && IN_RANGE(L,abs(current_population-adj_population),R) )
				{
					rc_q.push(make_pair(adj_row,adj_col));
					visited[adj_row][adj_col] = union_index;
					
					num_of_nations_in_union++;
					num_of_population_in_union += map[adj_row][adj_col];
				}
			}
		}
	}
	
	if( num_of_nations_in_union == 1 )
	{
		return	FALSE;
	}
	
	int	avg_population;
	
	avg_population = num_of_population_in_union/num_of_nations_in_union;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if( visited[i][j] == union_index )
			{
				map[i][j] = avg_population;
			}
		}
	}
	
	return	TRUE;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>L>>R;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>map[i][j];
		}
	}
	
	int	cnt;
	
	for(cnt=0;;cnt++)
	{
		int	union_index,migration_result;
		
		init_visited();
		union_index = 1;
		migration_result = FALSE;
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if( visited[i][j] == FALSE )
				{
					migration_result += migration(i,j,union_index);
					union_index++;
				}
			}
		}
		
		if( migration_result == FALSE )
		{
			break;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
