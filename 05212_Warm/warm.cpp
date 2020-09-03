#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10+2)

#define	LAND	'X'
#define	WATER	'.'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const	struct{
	int	d_row,d_col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	main(void)
{
	int		R,C;
	char	map[MAX_SIZE][MAX_SIZE+1];
	
	scanf("%d %d",&R,&C);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	for(int row=0;row<=R+1;row++)
	{
		map[row][0] = map[row][C+1] = WATER;
	}
	
	for(int col=1;col<=C;col++)
	{
		map[0][col] = map[R+1][col] = WATER;
	}
	
	vector< pair<int,int> > new_water;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( map[row][col] == LAND )
			{
				int	cnt,i;
				
				for(cnt=0,i=UP;i<=RIGHT;i++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+move_dir[i].d_row;
					adj_col = col+move_dir[i].d_col;
					
					if( map[adj_row][adj_col] == WATER )
					{
						cnt++;
					}
				}
				
				if( cnt >= 3 )
				{
					new_water.push_back(make_pair(row,col));
				}
			}
		}
	}
	
	for(int i=0;i<new_water.size();i++)
	{
		map[new_water[i].first][new_water[i].second] = WATER;
	}
	
	int	min_row,max_row,min_col,max_col;
	
	min_row = R;
	max_row = 1;
	min_col = C;
	max_col = 1;
	
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			if( map[row][col] == LAND )
			{
				min_row = min(min_row,row);
				max_row = max(max_row,row);
				min_col = min(min_col,col);
				max_col = max(max_col,col);
			}
		}
	}
	
	for(int row=min_row;row<=max_row;row++)
	{
		for(int col=min_col;col<=max_col;col++)
		{
			putchar(map[row][col]);
		}
		putchar('\n');
	}
	
	return	0;
}
