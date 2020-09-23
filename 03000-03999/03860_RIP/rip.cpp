#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	30
#define	INF			0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	EMPTY	0
#define	BLOCK	1

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	Hole;	// first:time,second:Pos

int		W,H,G,E;
int		grid[MAX_SIZE][MAX_SIZE];
int		time[MAX_SIZE][MAX_SIZE];
Hole	hole[MAX_SIZE][MAX_SIZE];

bool	input(void)
{
	cin>>W>>H;
	
	if( W==0 && H==0 )
	{
		return	false;
	}
	
	cin>>G;
	
	for(int row=0;row<H;row++)
	{
		fill(&grid[row][0],&grid[row][W],EMPTY);
		fill(&time[row][0],&time[row][W],INF);
		fill(&hole[row][0],&hole[row][W],make_pair(INF,make_pair(INF,INF)));
	}
	
	for(int i=1;i<=G;i++)
	{
		int	X,Y;
		
		cin>>X>>Y;
		grid[Y][X] = BLOCK;
	}
	
	cin>>E;
	
	for(int i=1;i<=E;i++)
	{
		int	X1,Y1,X2,Y2,T;
		
		cin>>X1>>Y1>>X2>>Y2>>T;
		hole[Y1][X1] = make_pair(T,make_pair(Y2,X2));
	}
	
	return	true;
}

bool	move(void)
{
	bool	infinite;
	
	infinite = false;
	time[0][0] = 0;
	
	for(int i=1;i<=W*H;i++)
	{
		bool	update;
		
		update = false;
		
		for(int row=0;row<H;row++)
		{
			for(int col=0;col<W;col++)
			{
				int&	current_time = time[row][col];
				int		adj_row,adj_col;
				
				if( current_time==INF || (row==H-1&&col==W-1) )
				{
					continue;
				}
				
				if( hole[row][col].first != INF )
				{
					adj_row = hole[row][col].second.first;
					adj_col = hole[row][col].second.second;
					
					if( current_time+hole[row][col].first < time[adj_row][adj_col] )
					{
						update = true;
						time[adj_row][adj_col] = current_time+hole[row][col].first;
					}
					
					continue;
				}
				
				for(int d=UP;d<=RIGHT;d++)
				{
					adj_row = row+adj[d].d_row;
					adj_col = col+adj[d].d_col;
					
					if( !IN_RANGE(0,adj_row,H-1) || !IN_RANGE(0,adj_col,W-1) )
					{
						continue;
					}
					
					if( grid[adj_row][adj_col] == BLOCK )
					{
						continue;
					}
					
					if( current_time+1 < time[adj_row][adj_col] )
					{
						update = true;
						time[adj_row][adj_col] = current_time+1;
					}
				}
			}
		}
		
		if( update == false )
		{
			break;
		}
		
		if( i == W*H )
		{
			infinite = true;
		}
	}
	
	return	infinite;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		bool	infinite;
		
		if( input() == false )
		{
			break;
		}
		
		infinite = move();
		
		if( infinite == true )
		{
			cout<<"Never\n";
		}
		else
		{
			if( time[H-1][W-1] != INF )
			{
				cout<<time[H-1][W-1]<<'\n';
			}
			else
			{
				cout<<"Impossible\n";
			}
		}
	}
	
	return	0;
}
