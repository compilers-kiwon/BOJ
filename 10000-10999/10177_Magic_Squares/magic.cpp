#include	<iostream>

using namespace	std;

#define	TO_LEFT		-1
#define	TO_RIGHT	1

#define	MAX_SIZE	5

int	m,square[MAX_SIZE+1][MAX_SIZE+1];

void	input(void)
{
	cin>>m;
	
	for(int row=1;row<=m;row++)
	{
		for(int col=1;col<=m;col++)
		{
			cin>>square[row][col];
		}
	}
}

int		get_sum_of_diag(int s_col,int d)
{
	int	sum;
	
	sum = 0;
	
	for(int	row=1,col=s_col;row<=m;row++,col+=d)
	{
		sum += square[row][col];
	}
	
	return	sum;
}

int		get_sum_of_row(int col)
{
	int	sum;
	
	sum = 0;
	
	for(int row=1;row<=m;row++)
	{
		sum += square[row][col];
	}
	
	return	sum;
}

int		get_sum_of_col(int row)
{
	int	sum;
	
	sum = 0;
	
	for(int col=1;col<=m;col++)
	{
		sum += square[row][col];
	}
	
	return	sum;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(;n>0;n--)
	{
		input();
		
		int		init_sum;
		bool	flag;
		
		flag = true;
		init_sum = get_sum_of_diag(1,TO_RIGHT);
		
		if( init_sum != get_sum_of_diag(m,TO_LEFT) )
		{
			flag = false;
		}
		
		for(int row=1;row<=m&&flag==true;row++)
		{
			flag = (init_sum==get_sum_of_row(row));
		}
		
		for(int col=1;col<=m&&flag==true;col++)
		{
			flag = (init_sum==get_sum_of_col(col));
		}
		
		if( flag == true )
		{
			cout<<"Magic square of size "<<m<<'\n';
		}
		else
		{
			cout<<"Not a magic square\n";
		}
	}
	
	return	0;
}
