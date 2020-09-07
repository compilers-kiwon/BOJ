#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	(1000+1)

string	str1,str2,answer;
int		dp[MAX_LEN][MAX_LEN],prev;

int		get_lcs(int row,int col)
{
	if( dp[row][col] != -1 )
	{
		return	dp[row][col];
	}
	
	int	left = get_lcs(row,col-1);
	int	up = get_lcs(row-1,col);
	int	up_left = get_lcs(row-1,col-1);
	
	if( str1[row] != str2[col] )
	{
		dp[row][col] = max(up,left);
	}
	else
	{
		dp[row][col] = up_left+1;
	}
	
	return	dp[row][col];
}

int		main(void)
{
	int	row_len,col_len;
	
	cin>>str1>>str2;
	
	row_len = str1.length();
	col_len = str2.length();
	
	str1.insert(str1.begin(),' ');
	str2.insert(str2.begin(),' ');
	
	for(int i=1;i<=row_len;i++)
	{
		for(int j=1;j<=col_len;j++)
		{
			dp[i][j] = -1;
		}
	}
	
	prev=get_lcs(row_len,col_len);
	cout<<prev<<endl;
	
	while( prev != 0 )
	{
		int	left,up;
		
		left = dp[row_len][col_len-1];
		up = dp[row_len-1][col_len];
		
		if( prev > max(left,up) )
		{
			answer.insert(answer.begin(),str1[row_len]);
			row_len = row_len-1;
			col_len = col_len-1;
			prev = dp[row_len][col_len];
		}
		else
		{
			if( left > up )
			{
				col_len = col_len-1;
			}
			else
			{
				row_len = row_len-1;
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}

