#include	<iostream>

using namespace	std;

#define	MAX_SIZE	5
#define	MAX_DIR		8
#define	KNIGHT		'k'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

char	board[MAX_SIZE+1][MAX_SIZE+2];

bool	can_attack(int k_row,int k_col)
{
	bool	result;
	
	result = false;
	
	for(int d=0;d<MAX_DIR;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = k_row+adj[d].d_row;
		adj_col = k_col+adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,MAX_SIZE) && IN_RANGE(1,adj_col,MAX_SIZE) && board[adj_row][adj_col]==KNIGHT )
		{
			result = true;
			break;	
		}	
	}
	
	return	result;	
}

int		main(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		scanf("%s",&board[row][1]);
	}
	
	bool	valid;
	int		num_of_knights;
	
	valid = true;
	num_of_knights = 0;
	
	for(int row=1;row<=MAX_SIZE&&valid==true;row++)
	{
		for(int col=1;col<=MAX_SIZE&&valid==true;col++)
		{
			if( board[row][col] == KNIGHT )
			{
				valid = !(can_attack(row,col));
				num_of_knights++;
			}
		}
	}
	
	if( valid==true && num_of_knights==9 )
	{
		cout<<"valid\n";
	}
	else
	{
		cout<<"invalid\n";
	}
	
	return	0;
}	
