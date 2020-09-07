#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100)

int	space[MAX_SIZE+1][MAX_SIZE+1];

int	main(void)
{
	for(int i=1;i<=4;i++)
	{
		int	x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		
		for(int y=y1;y<=y2-1;y++)
		{
			for(int x=x1;x<=x2-1;x++)
			{
				space[y][x]++;
			}
		}
	}
	
	int cnt = 0;
	
	for(int y=1;y<=MAX_SIZE;y++)
	{
		for(int x=1;x<=MAX_SIZE;x++)
		{
			if( space[y][x] != 0 )
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
