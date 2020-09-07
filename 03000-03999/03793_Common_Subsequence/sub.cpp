#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(200+1)

int	find_maximum_length(int table[][MAX_SIZE],string& s1,string& s2)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<s1.length();row++)
	{
		for(int col=1;col<s2.length();col++)
		{
			if( s1[row] == s2[col] )
			{
				table[row][col] = table[row-1][col-1]+1;
			}
			else
			{
				int	left,up;
				
				left = table[row][col-1];
				up = table[row-1][col];
				table[row][col] = max(left,up);
			}
			
			ret = max(ret,table[row][col]);
		}
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	s1,s2;
		int		table[MAX_SIZE][MAX_SIZE];
		
		cin>>s1>>s2;
		
		if( s1=="" && s2=="" )
		{
			break;
		}
		
		s1.insert(s1.begin(),' ');
		s2.insert(s2.begin(),' ');
		
		fill(&table[0][0],&table[0][s1.length()],0);
		
		for(int row=1;row<s2.length();row++)
		{
			table[row][0] = 0;
		}
		
		cout<<find_maximum_length(table,s1,s2)<<'\n';
	}
	
	return	0;
}
