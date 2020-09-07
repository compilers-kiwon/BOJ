#include	<iostream>

using namespace	std;

#define	MAX_SIZE	3
#define	MAX_NUM		20000

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	grid[MAX_SIZE+1][MAX_SIZE+1];
int	num_of_zero_in_row[MAX_SIZE+1];
int	num_of_zero_in_col[MAX_SIZE+1];

void	init(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			int&	n = grid[row][col];
			
			cin>>n;
			
			if( n == 0 )
			{
				num_of_zero_in_row[row]++;
				num_of_zero_in_col[col]++;
			}
		}
	}
}

int		get_sum_of_row_or_col(void)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		if( num_of_zero_in_row[row] == 0 )
		{
			for(int col=1;col<=MAX_SIZE;col++)
			{
				ret += grid[row][col];
			}
			
			return	ret;
		}
	}
	
	for(int col=1;col<=MAX_SIZE;col++)
	{
		if( num_of_zero_in_col[col] == 0 )
		{
			for(int row=1;row<=MAX_SIZE;row++)
			{
				ret += grid[row][col];
			}
			
			return	ret;
		}
	}
	
	return	ret;
}

void	find_hidden_number_in_row(int row,int sum)
{
	int	zero_col,n;
	
	n = 0;
	
	for(int col=1;col<=MAX_SIZE;col++)
	{
		n += grid[row][col];
		
		if( grid[row][col] == 0 )
		{
			zero_col = col;
		}
	}
	
	if( IN_RANGE(1,sum-n,MAX_NUM) )
	{
		grid[row][zero_col] = sum-n;
	
		num_of_zero_in_row[row]--;
		num_of_zero_in_col[zero_col]--;
	}
}

void	find_hidden_number_in_col(int col,int sum)
{
	int	zero_row,n;
	
	n = 0;
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		n += grid[row][col];
		
		if( grid[row][col] == 0 )
		{
			zero_row = row;
		}
	}
	
	if( IN_RANGE(1,sum-n,MAX_NUM) )
	{
		grid[zero_row][col] = sum-n;
	
		num_of_zero_in_row[zero_row]--;
		num_of_zero_in_col[col]--;
	}
}

bool	find_zero(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			if( grid[row][col] == 0 )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

bool	check_diag_sum(int sum)
{
	int	s1,s2;
	
	s1 = s2 = 0;
	
	for(int row=1,col=1;row<=MAX_SIZE&&col<=MAX_SIZE;row++,col++)
	{
		s1 += grid[row][col];
	}
	
	for(int row=1,col=MAX_SIZE;row<=MAX_SIZE&&col>=1;row++,col--)
	{
		s2 += grid[row][col];
	}
	
	return	((s1==sum)&&(s2==sum));
}

int		main(void)
{
	init();
	
	int	sum;
	
	sum = get_sum_of_row_or_col();
	
	if( sum != 0 )
	{
		for(;;)
		{
			for(int row=1;row<=MAX_SIZE;row++)
			{
				if( num_of_zero_in_row[row] == 1 )
				{
					find_hidden_number_in_row(row,sum);
				}
			}
			
			for(int col=1;col<=MAX_SIZE;col++)
			{
				if( num_of_zero_in_col[col] == 1 )
				{
					find_hidden_number_in_col(col,sum);
				}
			}
			
			if( find_zero() == false )
			{
				break;
			}
		}
	}
	else
	{
		int		zero_row,zero_col;
		bool	found;
		
		found = false;
		
		for(int row=1;row<=MAX_SIZE;row++)
		{
			for(int col=1;col<=MAX_SIZE;col++)
			{
				if( grid[row][col] == 0 )
				{
					zero_row = row;
					zero_col = col;
					found = true;
					
					break;
				}
			}
			
			if( found == true )
			{
				break;
			}
		}
		for(int i=1;i<=MAX_NUM;i++)
		{
			//cout<<"i="<<i<<'\n';
		
			int		tmp[MAX_SIZE+1][MAX_SIZE+1];
			
			for(int row=1;row<=MAX_SIZE;row++)
			{
				for(int col=1;col<=MAX_SIZE;col++)
				{
					tmp[row][col] = grid[row][col];
				}
			}
			
			grid[zero_row][zero_col] = i;
			
			num_of_zero_in_row[zero_row]--;
			num_of_zero_in_col[zero_col]--;
			
			sum = get_sum_of_row_or_col();
			
			for(int row=1;row<=MAX_SIZE;row++)
			{
				if( num_of_zero_in_row[row] == 1 )
				{
					find_hidden_number_in_row(row,sum);
				}
			}
				
			for(int col=1;col<=MAX_SIZE;col++)
			{
				if( num_of_zero_in_col[col] == 1 )
				{
					find_hidden_number_in_col(col,sum);
				}
			}

/*				
			for(int row=1;row<=MAX_SIZE;row++)
			{
				for(int col=1;col<=MAX_SIZE;col++)
				{
					cout<<grid[row][col]<<' ';
				}
				cout<<'\n';
			}
			getchar();
*/				
			if( check_diag_sum(sum)==true && find_zero()==false )
			{
				break;
			}
			
			for(int row=1;row<=MAX_SIZE;row++)
			{
				for(int col=1;col<=MAX_SIZE;col++)
				{
					grid[row][col] = tmp[row][col];
				}
			}
			
			for(int i=1;i<=MAX_SIZE;i++)
			{
				num_of_zero_in_row[i] = num_of_zero_in_col[i] = 1;
			}				
		}
	}
	
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			cout<<grid[row][col]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
