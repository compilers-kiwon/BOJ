#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

int		W,H,max_area;
char	grid[MAX_SIZE][MAX_SIZE+1];

bool	can_be_cleared(int s_row,int s_col,int e_row,int e_col)
{
	for(int row=s_row;row<=e_row;row++)
	{
		for(int col=s_col;col<=e_col;col++)
		{
			if( grid[row][col]!='G' && grid[row][col]!='S' )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

void	input(void)
{
	cin>>W>>H;
	
	for(int row=1;row<=H;row++)
	{
		cin>>&grid[row][1];
	}
}

int		get_max_area(void)
{
	int	ret;
	
	ret = 0;
	
	for(int s_row=1;s_row<=H;s_row++)
	{
		for(int s_col=1;s_col<=W;s_col++)
		{
			for(int e_row=s_row;e_row<=H;e_row++)
			{
				for(int e_col=s_col;e_col<=W;e_col++)
				{
					if( can_be_cleared(s_row,s_col,e_row,e_col) == true )
					{
						ret = max(ret,(e_row-s_row+1)*(e_col-s_col+1));
					}
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int n=1;n<=N;n++)
	{
		input();
		cout<<"Case #"<<n<<": "<<get_max_area()<<'\n';
	}
	
	return	0;
}
