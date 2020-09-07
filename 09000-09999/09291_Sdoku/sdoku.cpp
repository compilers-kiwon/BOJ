#include	<iostream>

using namespace	std;

#define	MAX_SIZE	9

int		sdoku[MAX_SIZE+1][MAX_SIZE+1];

bool	check_row(int col)
{
	bool	visited[MAX_SIZE+1] = {false,false,false,false,false,false,false,false,false,false};
	bool	result;
	int		i;
	
	for(i=1,result=true;i<=MAX_SIZE;i++)
	{
		int&	n = sdoku[i][col];
		
		if( visited[n] == true )
		{
			result = false;
			break;
		}
		
		visited[n] = true;
	}
	
	return	result;
}

bool	check_col(int row)
{
	bool	visited[MAX_SIZE+1] = {false,false,false,false,false,false,false,false,false,false};
	bool	result;
	int		i;
	
	for(i=1,result=true;i<=MAX_SIZE;i++)
	{
		int&	n = sdoku[row][i];
		
		if( visited[n] == true )
		{
			result = false;
			break;
		}
		
		visited[n] = true;
	}
	
	return	result;
}

bool	check_sub(int row,int col)
{
	bool	visited[MAX_SIZE+1] = {false,false,false,false,false,false,false,false,false,false};
	bool	result;
	int		i,j;
	
	for(i=row,result=true;i<row+3;i++)
	{
		for(j=col;j<col+3;j++)
		{	
			int&	n = sdoku[i][j];
		
			if( visited[n] == true )
			{
				result = false;
				break;
			}
		
			visited[n] = true;
		}
		
		if( result == false )
		{
			break;
		}
	}
	
	return	result;
}

bool	check_rows(void)
{
	bool	result;
	int		i;
	
	for(i=1,result=true;i<=MAX_SIZE&&result==true;i++)
	{
		result = check_row(i);
	}
	
	return	result;
}

bool	check_cols(void)
{
	bool	result;
	int		i;
	
	for(i=1,result=true;i<=MAX_SIZE&&result==true;i++)
	{
		result = check_col(i);
	}
	
	return	result;
}

bool	check_subs(void)
{
	bool	result;
	int		row,col;
	
	for(row=1,result=true;row<=MAX_SIZE&&result==true;row+=3)
	{
		for(col=1,result=true;col<=MAX_SIZE&&result==true;col+=3)
		{
				result = check_sub(row,col);
		}
	}
	
	return	result;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		for(int row=1;row<=MAX_SIZE;row++)
		{
			for(int col=1;col<=MAX_SIZE;col++)
			{
				cin>>sdoku[row][col];
			}
		}
	
		if( check_rows() && check_cols() && check_subs() )
		{
			cout<<"Case "<<i<<": CORRECT\n";
		}
		else
		{
			cout<<"Case "<<i<<": INCORRECT\n";
		}
	}
	
	return	0;
}
