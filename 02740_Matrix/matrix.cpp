#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	A[MAX_SIZE][MAX_SIZE],B[MAX_SIZE][MAX_SIZE];
int	N,M,K;

int	get_value(int row,int col)
{
	int	value = 0;

	for(int i=1;i<=M;i++)
	{
		value += A[row][i]*B[i][col];
	}
	return	value;
}

int	main(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>A[i][j];
		}
	}
	
	cin>>M>>K;
	
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=K;j++)
		{
			cin>>B[i][j];
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=K;j++)
		{
			cout<<get_value(i,j)<<' ';
		}
		cout<<endl;
	}
	
	return	0;
}
