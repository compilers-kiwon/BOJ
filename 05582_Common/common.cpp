#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(4000+1)

int	dp[MAX_SIZE][MAX_SIZE];

int	main(void)
{
	string	a,b;
	int		max_len;
	
	cin>>a>>b;
	max_len = 0;
	
	for(int row=1;row<=a.length();row++)
	{
		for(int col=1;col<=b.length();col++)
		{
			if( a[row-1] == b[col-1] )
			{
				dp[row][col] = dp[row-1][col-1]+1;
				max_len = max(max_len,dp[row][col]);
			}
		}
	}
	
	cout<<max_len<<'\n';
	
	return	0;
}
