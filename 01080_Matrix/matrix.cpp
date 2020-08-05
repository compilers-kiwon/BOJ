#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(50+1)

char	A[MAX_SIZE][MAX_SIZE+1],B[MAX_SIZE][MAX_SIZE+1];
int		N,M;

bool	is_same_matrix(void)
{
	bool	result = true;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if( A[i][j] != B[i][j] )
			{
				result = false;
				break;
			}
		}
		
		if( result == false)
		{
			break;
		}
	}
	
	return	result;
}

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&A[i][1]);
	}
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&B[i][1]);
	}
}

void	reverse(int row,int col)
{
	for(int i=row;i<=row+2;i++)
	{
		for(int j=col;j<=col+2;j++)
		{
			if( A[i][j] == '0' )
			{
				A[i][j] = '1';
			}
			else
			{
				A[i][j] = '0';
			}
		}
	}
}

int		main(void)
{
	int	cnt = 0;
	
	input();
	
	for(int i=1;i<=N-2;i++)
	{
		for(int j=1;j<=M-2;j++)
		{
			if( A[i][j] != B[i][j] )
			{
				reverse(i,j);
				cnt++;
			}
		}
	}
	
	if( is_same_matrix() == false )
	{
		cnt = -1;
	}
	cout<<cnt<<endl;
	
	return	0;
}
