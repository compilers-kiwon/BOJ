#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(40+1)

string	row_str,col_str;
int		dp[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin>>row_str>>col_str;
	
	row_str.insert(row_str.begin(),' ');
	col_str.insert(col_str.begin(),' ');
	
	for(int row=1;row<row_str.length();row++)
	{
		for(int col=1;col<col_str.length();col++)
		{
			dp[row][col] = -1;
		}
	}
}

int		get_dp(int row,int col)
{
	int&	ret = dp[row][col];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	if( row_str[row] == col_str[col] )
	{
		ret = get_dp(row-1,col-1)+1;
	}
	else
	{
		int	left,up;
		
		left = get_dp(row,col-1);
		up = get_dp(row-1,col);
		
		ret = max(left,up);
	}
	
	return	ret;
}

void	get_sub_str(int row,int col,string& s)
{
	for(;dp[row][col]!=0;)
	{
		if( row_str[row] == col_str[col] )
		{
			s.push_back(row_str[row]);
			row--;col--;
		}
		else
		{
			int&	left = dp[row][col-1];
			int&	up = dp[row-1][col];
			
			if( left > up )
			{
				col--;
			}
			else
			{
				row--;
			}
		}
	}
	
	for(int h=0,t=s.length()-1;h<t;h++,t--)
	{
		swap(s[h],s[t]);
	}
}

int	main(void)
{
	init();
	get_dp(row_str.length()-1,col_str.length()-1);
	
	string	sub;
	
	get_sub_str(row_str.length()-1,col_str.length()-1,sub);
	cout<<sub<<'\n';
	
	return	0;
}
