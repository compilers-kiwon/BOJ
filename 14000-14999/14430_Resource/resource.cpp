#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(300+1)

int	main(void)
{
	int	N,M;
	int	map[MAX_SIZE][MAX_SIZE];
	
	cin>>N>>M;
	
	for(int row=0;row<=N;row++)
	{
		map[row][0] = 0;
	}
	
	for(int col=0;col<=M;col++)
	{
		map[0][col] = 0;
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	r;
			
			cin>>r;
			
			map[row][col] = max(map[row-1][col],map[row][col-1])+r;
		}
	}
	cout<<map[N][M]<<endl;
	
	return	0;
}
