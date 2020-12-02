#include	<iostream>

using namespace	std;

#define	MAX_SIZE	5002

#define	RIGHT_DOWN	0
#define	LEFT_UP		1

int	number[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	int		n,x,y,d;
	
	for(x=y=n=0,d=RIGHT_DOWN;!(x>=MAX_SIZE&&y>=MAX_SIZE);n++)
	{
		if( x<MAX_SIZE && y<MAX_SIZE )
		{
			number[y][x] = n;
		}
		
		if( n%2 == 0 )
		{
			x++;
			y++;
		}
		else
		{
			if( d == RIGHT_DOWN)
			{
				x++;
				y--;
				d = LEFT_UP;
			}
			else
			{
				x--;
				y++;
				d = RIGHT_DOWN;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	init();
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		
		if( x==0 && y==0 )
		{
			cout<<"0\n";
		}
		else
		{
			if( number[y][x] != 0 )
			{
				cout<<number[y][x]<<'\n';
			}
			else
			{
				cout<<"No Number\n";
			}
		}
	}
	
	return	0;
}
