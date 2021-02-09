#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(499+1)

#define	LEFT	0
#define	DOWN	1
#define	RIGHT	2
#define	UP		3
#define	MAX_DIR	4

#define	next_dir(d)			(((d)+1)%MAX_DIR)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	MAX_SPREAD	9

typedef	struct	{int d_row,d_col;} 		Offset;
typedef	struct	{int rate;Offset o;}	Spread;

const Offset	adj[MAX_DIR] = {{0,-1},{1,0},{0,1},{-1,0}};
const Spread	sand[MAX_DIR][MAX_SPREAD] = {
	{{2,{-2,-1}},{10,{-1,-2}},{7,{-1,-1}},{1,{-1,0}},{5,{0,-3}},{10,{1,-2}},{7,{1,-1}},{1,{1,0}},{2,{2,-1}}},
	{{2,{1,-2}},{10,{2,-1}},{7,{1,-1}},{1,{0,-1}},{5,{3,0}},{10,{2,1}},{7,{1,1}},{1,{0,1}},{2,{1,2}}},
	{{2,{-2,1}},{10,{-1,2}},{7,{-1,1}},{1,{-1,0}},{5,{0,3}},{10,{1,2}},{7,{1,1}},{1,{1,0}},{2,{2,1}}},
	{{2,{-1,-2}},{10,{-2,-1}},{7,{-1,-1}},{1,{0,-1}},{5,{-3,0}},{10,{-2,1}},{7,{-1,1}},{1,{0,1}},{2,{-1,2}}}
};

int	N,grid[MAX_SIZE][MAX_SIZE];

void	move_tonado(int& row,int& col,int len,int d)
{
	for(int i=1;i<=len;i++)
	{
		int	s,adj_row,adj_col;
		
		s = 0;
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		for(int j=0;j<MAX_SPREAD;j++)
		{
			int	r,spread_sand;
			int	spread_row,spread_col;
			
			r = sand[d][j].rate;
			spread_sand = grid[adj_row][adj_col]*r/100;
			s += spread_sand;
			
			spread_row = row+sand[d][j].o.d_row;
			spread_col = col+sand[d][j].o.d_col;
			
			if( !IN_RANGE(1,spread_row,N) || !IN_RANGE(1,spread_col,N) )
			{
				continue;
			}
			
			grid[spread_row][spread_col] += spread_sand;
		}
		
		s = grid[adj_row][adj_col]-s;
		grid[adj_row][adj_col] = 0;
		
		adj_row += adj[d].d_row;
		adj_col += adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
		{
			grid[adj_row][adj_col] += s;
		}
		
		row += adj[d].d_row;
		col += adj[d].d_col;
		
		if( row==1 && col==1 )
		{
			break;
		}
	}
}

void	perform_tonado(void)
{
	for(int row=(N+1)/2,col=(N+1)/2,len=0,d=LEFT;!(row==1&&col==1);d=next_dir(d))
	{
		if( d==LEFT || d==RIGHT )
		{
			len++;
		}
		
		move_tonado(row,col,len,d);
	}
}

void	input(int& sum)
{
	cin>>N;
	sum = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
			sum += grid[row][col];
		}
	}
}

int		get_sum_of_sand(void)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			ret += grid[row][col];
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	init_sand;
	
	input(init_sand);
	perform_tonado();
	
	cout<<init_sand-get_sum_of_sand()<<'\n';
	
	return	0;
}
