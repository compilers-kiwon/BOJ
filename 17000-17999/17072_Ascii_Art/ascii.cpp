#include	<iostream>

using namespace	std;

#define	MAX_SIZE			(400+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

int		N,M,RGB[MAX_SIZE][MAX_SIZE];
char	ascii[MAX_SIZE][MAX_SIZE];

void	convert_rgb_to_ascii(int row,int col)
{
	char&	c = ascii[row][col];
	int&	n = RGB[row][col];
	
	if( IN_RANGE(0,n,510000) )
	{
		c = '#';
	}
	else if( IN_RANGE(510000,n,1020000) )
	{
		c = 'o';
	}
	else if( IN_RANGE(1020000,n,1530000) )
	{
		c = '+';
	}
	else if( IN_RANGE(1530000,n,2040000) )
	{
		c = '-';
	}
	else
	{
		c = '.';
	}
}

void	print_ascii(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cout<<ascii[row][col];
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	r,g,b;
			
			cin>>r>>g>>b;
			RGB[row][col] = 2126*r+7152*g+722*b;
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			convert_rgb_to_ascii(row,col);
		}
	}
	
	print_ascii();
	
	return	0;
}
