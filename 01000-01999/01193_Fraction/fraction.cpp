#include	<iostream>

using namespace	std;

#define	MAX_NUM	(10000000+1)

#define	IN_RANGE(n,MIN,MAX)	(((MIN)<=(n)&&(n)<=(MAX))?true:false)

int	row[MAX_NUM],col[MAX_NUM];
int	index;

int	main(void)
{
	int	X;
	int	row_value,col_value;
	
	cin>>X;
	
	row[0] = col[0] = 0;
	row[1] = col[1] = 1;
	
	row[2] = 3;
	row[3] = 4;
	row[4] = 10;
	
	col[2] = 2;
	col[3] = 6;
	col[4] = 7;
	
	if( X == 1 )
	{
		cout<<"1/1\n";
		return	0;
	}
	
	if( X == 2 )
	{
		cout<<"1/2\n";
		return	0;
	}
	
	if( X == 3 )
	{
		cout<<"2/1\n";
		return	0;
	}
	
	index = 3;
	row_value = row[index];
	col_value = col[index];
	
	while( IN_RANGE(X,min(row_value,col_value),max(row_value,col_value)) != true )
	{
		++index;
		
		if( index%2 == 1 )
		{
			row[index] = row[index-1]+1;
			col[index] = 2*col[index-2]-col[index-4]+4;
		}
		else
		{
			row[index] = 2*row[index-2]-row[index-4]+4;
			col[index] = col[index-1]+1;
		}
		
		row_value = row[index];
		col_value = col[index];
	}
	
	int	row_diff,col_diff;
	
	if( index%2 == 1 )
	{
		row_diff = X-row_value;
		col_diff = col_value-X;
	}
	else
	{
		row_diff = row_value-X;
		col_diff = X-col_value;
	}
	cout<<index-row_diff<<'/'<<index-col_diff<<endl;
	
	return	0;
}
