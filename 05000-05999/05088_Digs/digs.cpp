#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

int	grid[MAX_SIZE][MAX_SIZE];

int	get_item(void)
{
	int	ret,N;
	
	ret = 0;
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	X,Y;
		
		cin>>X>>Y;
		ret += grid[X][Y];
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	X,Y;
		
		cin>>X>>Y;
		
		if( X==0 && Y==0 )
		{
			break;
		}
		
		for(int i=0;i<X;i++)
		{
			for(int j=0;j<Y;j++)
			{
				grid[i][j] = 0;
			}
		}
		
		int	M;
		
		cin>>M;
		
		for(int i=1;i<=M;i++)
		{
			int	x,y;
			
			cin>>x>>y;
			grid[x][y]++;
		}
		
		cout<<get_item()<<'\n';
	}
	
	return	0;
}
