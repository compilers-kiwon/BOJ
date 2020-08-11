#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

int		paper[MAX_SIZE+1][MAX_SIZE+1];

void	cover(int x1,int y1,int x2,int y2)
{
	for(int y=y1;y<=y2;y++)
	{
		for(int x=x1;x<=x2;x++)
		{
			paper[y][x]++;
		}
	}
}

int		count_t(int covered)
{
	int	cnt;
	
	cnt = 0;
	
	for(int y=1;y<=MAX_SIZE;y++)
	{
		for(int x=1;x<=MAX_SIZE;x++)
		{
			if( paper[y][x] > covered )
			{
				cnt++;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		cover(x1,y1,x2,y2);
	}
	
	cout<<count_t(M)<<endl;
	
	return	0;
}
