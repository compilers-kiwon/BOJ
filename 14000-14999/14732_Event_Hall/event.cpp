#include	<iostream>

using namespace	std;

#define	MAX_SIZE	500

#define	FALSE	0
#define	TRUE	1

int		area[MAX_SIZE+1][MAX_SIZE+1];

void	fill(int x1,int y1,int x2,int y2)
{
	for(int row=y1+1;row<=y2;row++)
	{
		for(int col=x1+1;col<=x2;col++)
		{
			area[row][col] = TRUE;
		}
	}
}

int		count(void)
{
	int	cnt;
	
	cnt = 0;
	
	for(int row=0;row<=MAX_SIZE;row++)
	{
		for(int col=0;col<=MAX_SIZE;col++)
		{
			cnt += area[row][col];
		}
	}
	
	return	cnt;
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	x1,y1,x2,y2;
		
		cin>>x1>>y1>>x2>>y2;
		fill(x1,y1,x2,y2);
	}
	
	cout<<count()<<endl;
	
	return	0;
}
