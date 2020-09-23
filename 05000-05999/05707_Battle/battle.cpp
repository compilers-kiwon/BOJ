#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	get_enemy(m,h)		(((m)+1)%h)

int	N,R,C,K,grid[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:heir,second:Pos

bool	input(void)
{
	cin>>N>>R>>C>>K;
	
	if( N==0 && R==0 && C==0 && K==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			cin>>grid[row][col];
		}
	}
	
	return	true;
}

void	battle(void)
{
	for(int current=1;current<=K;current++)
	{
		vector<State>	battle_result;
		
		for(int row=1;row<=R;row++)
		{
			for(int col=1;col<=C;col++)
			{
				for(int d=UP;d<=RIGHT;d++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[d].d_row;
					adj_col = col+adj[d].d_col;
					
					if( !IN_RANGE(1,adj_row,R) || !IN_RANGE(1,adj_col,C) )
					{
						continue;
					}
					
					if( grid[adj_row][adj_col] == get_enemy(grid[row][col],N) )
					{
						battle_result.push_back(make_pair(grid[row][col],make_pair(adj_row,adj_col)));
					}
				}
			}
		}
		
		if( battle_result.size() == 0 )
		{
			break;
		}
		
		for(int i=0;i<battle_result.size();i++)
		{
			int&	heir = battle_result[i].first;
			int&	row = battle_result[i].second.first;
			int&	col = battle_result[i].second.second;
			
			grid[row][col] = heir;
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		if( input() == false )
		{
			break;
		}
		
		battle();
		
		for(int row=1;row<=R;row++)
		{
			for(int col=1;col<C;col++)
			{
				cout<<grid[row][col]<<' ';
			}
			cout<<grid[row][C]<<'\n';
		}
	}
	
	return	0;
}
