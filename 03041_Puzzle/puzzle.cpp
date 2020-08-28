#include	<iostream>
#include	<map>
#include	<cmath>

using namespace	std;

#define	PUZZLE_SIZE	4

typedef	pair<int,int>	RowCol;

int	main(void)
{
	map<char,RowCol>	final,input;
	char				c;
	
	c = 'A';
	
	for(int row=1;row<=PUZZLE_SIZE;row++)
	{
		char	buf[PUZZLE_SIZE+2];
		
		scanf("%s",&buf[1]);
		
		for(int col=1;col<=PUZZLE_SIZE;col++)
		{
			final[c] = make_pair(row,col);
			c++;
			
			input[buf[col]] = make_pair(row,col);
		}
	}
	
	int	sum_of_diff;
	
	sum_of_diff = 0;
	
	for(c='A';c<='O';c++)
	{
		sum_of_diff += abs(final[c].first-input[c].first)+abs(final[c].second-input[c].second);
	}
	
	cout<<sum_of_diff<<endl;
	
	return	0;
}
