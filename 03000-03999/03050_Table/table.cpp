#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(400+1)

int	R,C;
int	w[MAX_SIZE+1][MAX_SIZE+1],h[MAX_SIZE+1][MAX_SIZE+1];

void	input(void)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		char	buf[MAX_SIZE+1];
		
		cin>>&buf[1];
		w[row][C+1] = 0;
		
		for(int col=C;col>=1;col--)
		{
			if( buf[col] == 'X' )
			{
				w[row][col] = 0;
			}
			else
			{
				w[row][col] = w[row][col+1]+1;
			}
		}
	}

	for(int col=1;col<=C;col++)
	{
		h[R+1][col] = 0;
		
		for(int row=R;row>=1;row--)
		{
			if( w[row][col] == 0 )
			{
				h[row][col] = 0;
			}
			else
			{
				h[row][col] = h[row+1][col]+1;
			}
		}
	}	
}

int		get_max_table(void)
{
	int	ret1,ret2;
	
	ret1 = ret2 = 0;
	
	for(int col=1;col<=C;col++)
	{
		int	min_width,height;
		
		min_width = MAX_SIZE;
		height = 0;
		
		for(int row=1;row<=R;row++)
		{
			if( w[row][col] == 0 )
			{
				min_width = MAX_SIZE;
				height = 0;
			}
			else
			{
				min_width = min(min_width,w[row][col]);
				height++;
				
				ret1 = max(ret1,height*2+min_width*2);
			}
		}	
	}
	
	for(int row=1;row<=R;row++)
	{
		int	width,min_height;
		
		width = 0;
		min_height = MAX_SIZE;
		
		for(int col=1;col<=C;col++)
		{
			if( h[row][col] == 0 )
			{
				width = 0;
				min_height = MAX_SIZE;
			}
			else
			{
				min_height = min(min_height,h[row][col]);
				width++;
				
				ret2 = max(ret2,min_height*2+width*2);
			}
		}
	}
	
	return	max(ret1,ret2);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<get_max_table()-1<<'\n';
	
	return	0;
}
