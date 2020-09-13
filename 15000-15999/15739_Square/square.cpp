#include	<iostream>

using namespace	std;

#define	MAX_SIZE	100

int		square[MAX_SIZE+1][MAX_SIZE+1];
bool	used[MAX_SIZE*MAX_SIZE+1];

bool	check_row(int row,int sum,int size)
{
	int		s,i;
		
	for(i=1,s=0;i<=size;i++)
	{
		s += square[row][i];
	}
	
	return	(s==sum);
}

bool	check_col(int col,int sum,int size)
{
	int		s,i;
	
	for(i=1,s=0;i<=size;i++)
	{
		s += square[i][col];
	}
	
	return	(s==sum);
}

bool	check_diagonal_left_right(int sum,int size)
{
	int		s,row,col;
	
	for(row=col=1,s=0;row<=size;row++,col++)
	{
		s += square[row][col];
	}
	
	return	(s==sum);
}

bool	check_diagonal_right_left(int sum,int size)
{
	int		s,row,col;
	
	for(row=1,col=size,s=0;row<=size;row++,col--)
	{
		s += square[row][col];
	}
	
	return	(s==sum);
}

int		main(void)
{
	int		N;
	bool	result;
	
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>square[row][col];
			
			if( used[square[row][col]] == true )
			{
				cout<<"FALSE\n";
				return	0;
			}
			used[square[row][col]] = true;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		if( check_row(i,N*(N*N+1)/2,N) == false )
		{
			cout<<"FALSE\n";
			return 0;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		if( check_col(i,N*(N*N+1)/2,N) == false )
		{
			cout<<"FALSE\n";
			return 0;
		}
	}
	
	if( check_diagonal_left_right(N*(N*N+1)/2,N) == false )
	{
		cout<<"FALSE\n";
		return 0;
	}
	
	if( check_diagonal_right_left(N*(N*N+1)/2,N) == false )
	{
		cout<<"FALSE\n";
		return 0;
	}
	
	cout<<"TRUE\n";
	return	0;
}
