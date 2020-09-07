#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	10

#define	MINUS	-1
#define	ZERO	0
#define	PLUS	1

#define	get_sign(n)	(((n)==0)?0:(((n)>0)?1:-1))

int	S[MAX_SIZE][MAX_SIZE],A[MAX_SIZE],sum_table[MAX_SIZE][MAX_SIZE];
int	N;

void	init(void)
{
	string	str;
	int		row,col,i;
	
	cin>>N>>str;
	
	for(i=row=0;row<N;row++)
	{
		for(col=row;col<N;col++)
		{
			char&	c = str[i++];
			
			switch(c)
			{
				case	'-':
					S[row][col] = MINUS;
					break;
				case	'0':
					S[row][col] = ZERO;
					break;
				case	'+':
					S[row][col] = PLUS;
					break;
			}
		}
	}
}

bool	find_number(int A_index)
{
	if( A_index == N )
	{
		return	true;
	}
	
	for(int candidate=-10;candidate<=10;candidate++)
	{
		bool	result;
		
		result = true;
		
		for(int row=0;row<=A_index&&result==true;row++)
		{
			int	tmp;
			
			tmp = sum_table[row][A_index-1]+candidate;
			
			if( get_sign(tmp) != S[row][A_index] )
			{
				result = false;
			}
			
			sum_table[row][A_index] = tmp;
		}
		
		if( result == true )
		{
			A[A_index] = candidate;
			
			if( find_number(A_index+1) == true )
			{
				return	true;
			}
		}
	}
	return	false;
}

int		main(void)
{
	int	from,to;
	
	init();
	
	if( S[0][0] == ZERO )
	{
		from = to = 0;
	}
	else
	{
		if( S[0][0] == MINUS )
		{
			from = -10;
			to = -1;
		}
		else
		{
			from = 1;
			to = 10;
		}
	}
	
	for(int i=from;i<=to;i++)
	{
		A[0] = i;
		sum_table[0][0] = i;
		
		if( find_number(1) == true )
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",A[j]);
			}
			puts("");
			
			break;
		}
	}
	
	return	0;
}
