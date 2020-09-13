#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	BLACK	'B'
#define	WHITE	'W'

int		main(void)
{
	int		N,B,W;
	int		num_of_white,num_of_black,max_len;
	string	r;	
	
	queue<char>	prev;
	
	cin>>N>>B>>W>>r;
	
	num_of_white = num_of_black = max_len = 0;
	
	for(int i=0;i<r.length();i++)
	{
		char&	current = r[i];
		
		if( current == WHITE )
		{
			num_of_white++;
			prev.push(current);
		}
		else
		{
			num_of_black++;
			prev.push(current);
			
			while( !prev.empty() && num_of_black > B )
			{
				char	prev_stone;
				
				prev_stone = prev.front();
				prev.pop();
				
				if( prev_stone == WHITE )
				{
					num_of_white--;
				}
				else
				{
					num_of_black--;
				}
			}
		}
		
		if( num_of_white >= W )
		{
			max_len = max(max_len,num_of_white+num_of_black);
		}
	}
	
	cout<<max_len<<endl;
	
	return	0;
}
