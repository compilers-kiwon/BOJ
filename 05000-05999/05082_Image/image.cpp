#include	<iostream>
#include	<queue>

using namespace	std;

typedef	struct{int red,green,blue;}	Pixel;
typedef	pair<int,int>				Pos;

#define	MAX_SIZE	(1024+1)

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

Pixel	image[MAX_SIZE][MAX_SIZE];

const Pixel	visited = {-1,-1,-1};

#define	is_same_pixel(a,b)	(((a).red==(b).red)&&((a).green==(b).green)&&((a).blue==(b).blue))

bool	input(int& height,int& width,int& band_size,int& size_limit)
{
	cin>>height>>width>>band_size>>size_limit;
	
	if( height==0 && width==0 && band_size==0 && size_limit==0 )
	{
		return	false;
	}
	
	for(int row=1;row<=height;row++)
	{
		for(int col=1;col<=width;col++)
		{
			int&	R = image[row][col].red;
			int&	G = image[row][col].green;
			int&	B = image[row][col].blue;
			
			cin>>R>>G>>B;
			
			R /= band_size;
			G /= band_size;
			B /= band_size;
		}
	}
	
	return	true;
}

int		get_size_of_connected_area(int row,int col,int height,int width)
{
	queue<Pos>	pixel_q;
	Pixel		p;
	int			ret;
	
	ret = 0;
	p = image[row][col];
	
	pixel_q.push(make_pair(row,col));
	image[row][col] = visited;
	
	for(;!pixel_q.empty();)
	{
		int		current_row,current_col;
		
		current_row = pixel_q.front().first;
		current_col = pixel_q.front().second;
		
		pixel_q.pop();
		ret++;
		
		for(int d=UP;d<=UP_LEFT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,height) && IN_RANGE(1,adj_col,width) )
			{
				if( is_same_pixel(image[adj_row][adj_col],p) == true )
				{
					pixel_q.push(make_pair(adj_row,adj_col));
					image[adj_row][adj_col] = visited;
				}
			}
		}
	}
	
	return	ret;
}

int		count_connected_areas(int height,int width,int size_limitation)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=height;row++)
	{
		for(int col=1;col<=width;col++)
		{
			if( is_same_pixel(image[row][col],visited)!=true && 
				get_size_of_connected_area(row,col,height,width)>=size_limitation )
			{
				ret++;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	H,W,S,L;
		
		if( input(H,W,S,L) == false )
		{
			break;
		}
		
		cout<<count_connected_areas(H,W,L)<<'\n';
	}
	
	return	0;
}
