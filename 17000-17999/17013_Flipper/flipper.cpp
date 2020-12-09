#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	2

int	main(void)
{
	int		grid[MAX_SIZE][MAX_SIZE] = {{1,2},{3,4}};
	string	str;
	
	cin>>str;
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == 'V' )
		{
			swap(grid[0][0],grid[0][1]);
			swap(grid[1][0],grid[1][1]);
		}
		else
		{
			swap(grid[0][0],grid[1][0]);
			swap(grid[0][1],grid[1][1]);
		}
	}
	
	cout<<grid[0][0]<<' '<<grid[0][1]<<'\n'<<grid[1][0]<<' '<<grid[1][1]<<'\n';
	
	return	0;
}
