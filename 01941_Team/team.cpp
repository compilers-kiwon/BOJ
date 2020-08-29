#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE			5
#define	TEAM_SIZE			7
#define	shift(row,col)		(1<<((row)*MAX_SIZE+(col)))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

string			seat[MAX_SIZE];
map<int,bool>	counted;

void	dfs(int visited,int v1,int v2,int& cnt)
{
	if( v1+v2 == TEAM_SIZE )
	{
		if( v1>v2 && counted[visited]==false )
		{
			counted[visited] = true;
			cnt++;
		}
		
		return;
	}
	
	for(int p=0;p<MAX_SIZE*MAX_SIZE;p++)
	{
		int	row,col;
		
		if( (visited&(1<<p)) == 0 )
		{
			continue;
		}	
		
		row = p/MAX_SIZE;
		col = p%MAX_SIZE;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = row+adj[d].d_row;
			adj_col = col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,MAX_SIZE) || !IN_RANGE(0,adj_col,MAX_SIZE) )
			{
				continue;
			}
			
			if( (visited&shift(adj_row,adj_col)) != 0 )
			{
				continue;
			}
			
			if( seat[adj_row][adj_col] == 'S' )
			{
				dfs(visited|shift(adj_row,adj_col),v1+1,v2,cnt);
			}
			else
			{
				dfs(visited|shift(adj_row,adj_col),v1,v2+1,cnt);
			}
		}
	}
}

int		main(void)
{
	int	cnt;
	
	for(int row=0;row<MAX_SIZE;row++)
	{
		cin>>seat[row];
	}
	
	cnt = 0;
	
	for(int row=0;row<MAX_SIZE;row++)
	{
		for(int col=0;col<MAX_SIZE;col++)
		{
			if( seat[row][col] == 'S' )
			{
				dfs(shift(row,col),1,0,cnt);
			}
			else
			{
				dfs(shift(row,col),0,1,cnt);
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
