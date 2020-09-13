#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SIZE			36
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		N,digit_table[MAX_SIZE][MAX_SIZE];
string	grid[MAX_SIZE];

int		get_index(char c)
{
	int	ret;
	
	if( IN_RANGE('A',c,'Z') == true )
	{
		ret = (int)(c-'A')+10;
	}
	else
	{
		ret = (int)(c-'0');
	}
	
	return	ret;
}

bool	is_Latin_Square(void)
{
	for(int row=0;row<N;row++)
	{
		vector<bool>	used(N,false);
		
		for(int col=0;col<N;col++)
		{
			int&	digit = digit_table[row][col];
			
			if( used[digit] == true )
			{
				return	false;
			}
			
			used[digit] = true;
		}
	}
	
	for(int col=0;col<N;col++)
	{
		vector<bool>	used(N,false);
		
		for(int row=0;row<N;row++)
		{
			int&	digit = digit_table[row][col];
			
			if( used[digit] == true )
			{
				return	false;
			}
			
			used[digit] = true;
		}
	}
	
	return	true;
}

bool	is_reduced(void)
{
	for(int col=1;col<N;col++)
	{
		if( digit_table[0][col] <= digit_table[0][col-1] )
		{
			return	false;
		}
	}
	
	for(int row=1;row<N;row++)
	{
		if( digit_table[row][0] <= digit_table[row-1][0] )
		{
			return	false;
		}
	}
	
	return	true;
}

int		main(void)
{
	cin>>N;
	
	for(int row=0;row<N;row++)
	{
		cin>>grid[row];
		
		for(int col=0;col<N;col++)
		{
			int&	d = digit_table[row][col];
			
			d = get_index(grid[row][col]);
			
			if( d >= N )
			{
				cout<<"No\n";
				return	0;
			}
		}
	}
	
	if( is_Latin_Square() == false )
	{
		cout<<"No\n";
		return	0;
	}
	
	if( is_reduced() == true )
	{
		cout<<"Reduced\n";
	}
	else
	{
		cout<<"Not Reduced\n";
	}
	
	return	0;
}
