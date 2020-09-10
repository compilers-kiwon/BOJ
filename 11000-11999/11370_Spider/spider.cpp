#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Pos;	// first:row, second:col

#define	SPIDER	'S'
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

int		main(void)
{
	int	W,H;
	
	for(;;)
	{
		scanf("%d %d",&W,&H);
		
		if( W==0 && H==0 )
		{
			break;
		}
		
		char		mirkwood[H+1][W+2];
		queue<Pos>	spider_q;
		
		for(int	row=1;row<=H;row++)
		{
			scanf("%s",&mirkwood[row][1]);
			
			for(int col=1;col<=W;col++)
			{
				if( mirkwood[row][col] == SPIDER )
				{
					spider_q.push(make_pair(row,col));
				}
			}
		}
		
		for(;!spider_q.empty();)
		{
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = spider_q.front().first+adj[d].d_row;
				adj_col = spider_q.front().second+adj[d].d_col;
				
				if( mirkwood[adj_row][adj_col] == TREE )
				{
					mirkwood[adj_row][adj_col] = SPIDER;
					spider_q.push(make_pair(adj_row,adj_col));
				}
			}
			
			spider_q.pop();
		}
		
		for(int row=1;row<=H;row++)
		{
			puts(&mirkwood[row][1]);
		}
	}
	
	return	0;
}
