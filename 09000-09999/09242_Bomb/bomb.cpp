#include	<iostream>

using namespace	std;

const char	number[10][5][3] = {
	{{'*','*','*'},{'*',' ','*'},{'*',' ','*'},{'*',' ','*'},{'*','*','*'}},
	{{' ',' ','*'},{' ',' ','*'},{' ',' ','*'},{' ',' ','*'},{' ',' ','*'}},
	{{'*','*','*'},{' ',' ','*'},{'*','*','*'},{'*',' ',' '},{'*','*','*'}},
	{{'*','*','*'},{' ',' ','*'},{'*','*','*'},{' ',' ','*'},{'*','*','*'}},
	{{'*',' ','*'},{'*',' ','*'},{'*','*','*'},{' ',' ','*'},{' ',' ','*'}},
	{{'*','*','*'},{'*',' ',' '},{'*','*','*'},{' ',' ','*'},{'*','*','*'}},
	{{'*','*','*'},{'*',' ',' '},{'*','*','*'},{'*',' ','*'},{'*','*','*'}},
	{{'*','*','*'},{' ',' ','*'},{' ',' ','*'},{' ',' ','*'},{' ',' ','*'}},
	{{'*','*','*'},{'*',' ','*'},{'*','*','*'},{'*',' ','*'},{'*','*','*'}},
	{{'*','*','*'},{'*',' ','*'},{'*','*','*'},{' ',' ','*'},{'*','*','*'}}
};

#define	MAX_SIZE	100
#define	ROW_LEN		5
#define	COL_LEN		3

char	buf[MAX_SIZE][MAX_SIZE];

bool	find_number(int s_row,int s_col,int& value)
{
	bool	found;
	int		row,col;
	
	for(value=0;value<=9;value++)
	{
		found = true;
		
		for(row=0;row<ROW_LEN;row++)
		{
			for(col=0;col<COL_LEN;col++)
			{
				if( buf[s_row+row][s_col+col] != number[value][row][col] )
				{
					found = false;
					break;
				}
			}
			
			if( found == false )
			{
				break;
			}
		}
		
		if( found == true )
		{
			break;
		}
	}
	
	return	found;
}

int		main(void)
{
	for(int i=0;i<ROW_LEN;i++)
	{
		buf[i][0] = ' ';
		fgets(&buf[i][1],MAX_SIZE-2,stdin);
	}
	
	int		value,number;
	bool	valid;
	
	value = 0;
	valid = true;
	
	for(int i=0;buf[0][i]==' ';i+=4)
	{
		if( find_number(0,i+1,number) == true )
		{
			value = value*10+number;
		}
		else
		{
			valid = false;
			break;
		}
	}
	
	if( valid == false || value%6 != 0 )
	{
		cout<<"BOOM!!\n";
	}
	else
	{
		cout<<"BEER!!\n";
	}
	
	return	0;
}
