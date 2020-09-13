#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		N,a,b;
int		max_row[MAX_SIZE],max_col[MAX_SIZE],X;

void	input(void)
{
	cin>>N>>a>>b;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			int	n;
			
			cin>>n;
			max_row[row] = max(max_row[row],n);
			max_col[col] = max(max_col[col],n);
			
			if( X == 0 && row == a && col == b )
			{
				X = n;
			}
		}
	}
}

int		main(void)
{
	input();
	
	if( X == max(max_row[a],max_col[b]) )
	{
		cout<<"HAPPY\n";
	}
	else
	{
		cout<<"ANGRY\n";
	}
	
	return	0;
}
