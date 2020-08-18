#include	<iostream>

using namespace	std;

#define	ROW_SIZE	5
#define	COL_SIZE	3
#define	DIGIT_LEN	10

char		clock[ROW_SIZE][100+1];
const char	digit[DIGIT_LEN][ROW_SIZE][COL_SIZE] =
{
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','.','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	},
	{
		{'#','.','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	}
};

bool	compare_diode(int digit_col,int digit_num)
{
	bool	result;
	
	result = true;
	
	for(int row=0;row<ROW_SIZE;row++)
	{
		for(int col=0;col<COL_SIZE;col++)
		{
			if( clock[row][digit_col+col] == '#' && digit[digit_num][row][col] != '#' )
			{
				result = false;
				break;
			}
		}
		
		if( result == false )
		{
			break;
		}
	}
	
	return	result;
}

int		find_digit(int digit_col)
{
	int	d;
	
	for(d=0;d<DIGIT_LEN;d++)
	{
		if( compare_diode(digit_col,d) == true )
		{
			break;
		}
	}
	
	return	d;
}

int		main(void)
{
	for(int row=0;row<ROW_SIZE;row++)
	{
		fgets(&clock[row][0],99,stdin);
	}
	
	int	h1,h2,m1,m2;
	
	h1 = find_digit(0);
	h2 = find_digit(4);
	m1 = find_digit(8);
	m2 = find_digit(12);
	
	cout<<h1<<h2<<':'<<m1<<m2<<'\n';
	
	return	0;
}
