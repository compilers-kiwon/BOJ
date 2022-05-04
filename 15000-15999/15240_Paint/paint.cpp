#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(1000+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		R,C,X,Y;
char	image[MAX_SIZE][MAX_SIZE+1],K;

typedef	pair<int,int>	RowCol;

void	input(void)
{
	scanf("%d %d",&R,&C);
	
	for(int row=1;row<=R;row++)
	{
		scanf("%s",&image[row][1]);
	}
	
	scanf("%d %d %c",&Y,&X,&K);
	Y++;X++;
}

void	fill(void)
{
	queue<RowCol>	pixel;
	char			init_color;
	
	init_color = image[Y][X];
    
    if( init_color == K )
    {
        return;
    }
    
	image[Y][X] = K;
	pixel.push(make_pair(Y,X));
	
	while( !pixel.empty() )
	{
		int	current_row,current_col;
		
		current_row = pixel.front().first;
		current_col = pixel.front().second;
		
		pixel.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,R) && IN_RANGE(1,adj_col,C) )
			{
				if( image[adj_row][adj_col] == init_color )
				{
					image[adj_row][adj_col] = K;
					pixel.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

int		main(void)
{
	input();
	fill();
	
	for(int row=1;row<=R;row++)
	{
		puts(&image[row][1]);
	}
	
	return	0;
}