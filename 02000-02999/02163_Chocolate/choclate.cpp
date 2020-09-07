#include	<iostream>

using namespace	std;

typedef	pair<int,int> Chocolate;

int	cut(Chocolate c)
{
	int	result,row,col;
	
	row = c.first;
	col = c.second;
	
	if( row == 1 && col == 1 )
	{
		result = 0;
	}
	else
	{
		if( row > col )
		{
			result = 1+cut(make_pair(row-1,col))+(col-1);
		}
		else
		{
			result = 1+cut(make_pair(row,col-1))+(row-1);
		}
	}
	return	result;
}

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	cout<<cut(make_pair(N,M))<<endl;
	
	return	0;
}
