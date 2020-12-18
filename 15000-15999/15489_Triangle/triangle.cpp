#include	<iostream>

using namespace	std;

#define	MAX_SIZE	30

int	R,C,W,T[MAX_SIZE+1][MAX_SIZE+1];

void	init(void)
{
	T[1][1] = 1;
	
	for(int row=2;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=row;col++)
		{
			T[row][col] = T[row-1][col-1]+T[row-1][col];
		}
	}
}

int		get_sum(void)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<W;i++)
	{
		for(int col=C;col<=C+i;col++)
		{
			ret += T[R+i][col];
		}
	}
	
	return	ret;
}

int		main(void)
{
	init();
	cin>>R>>C>>W;
	
	cout<<get_sum()<<'\n';
	
	return	0;
}
