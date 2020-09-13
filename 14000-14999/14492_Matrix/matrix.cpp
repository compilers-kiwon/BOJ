#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(300+1)

int	A[MAX_SIZE][MAX_SIZE],B[MAX_SIZE][MAX_SIZE];

int	get_bool(int row,int col,int size)
{
	int	C;
	
	C = 0;
	
	for(int n=1;n<=size;n++)
	{
		C |= (A[row][n]&B[n][col]);
	}
	
	return	C;
}

int	main(void)
{
	int	N,cnt;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>A[i][j];
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>B[i][j];
		}
	}
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cnt += get_bool(i,j,N);
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
