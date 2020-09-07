#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

bool	space[MAX_SIZE][MAX_SIZE];

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int x,y;
		
		cin>>x>>y;
		
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				space[y+i][x+j] = true;
			}
		}
	}
	
	int	cnt = 0;
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		for(int j=0;j<MAX_SIZE;j++)
		{
			if( space[i][j] == true )
			{
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
