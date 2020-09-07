#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN	(100+1)

int		dp[MAX_LEN][MAX_LEN][MAX_LEN];
string	str1,str2,str3;

int		get_dp(int x,int y,int z)	// str1,str2,str3
{
	if( dp[z][y][x] != -1 )
	{
		return	dp[z][y][x];
	}
	
	int	x_1 = get_dp(x-1,y,z);
	int	y_1 = get_dp(x,y-1,z);
	int	z_1 = get_dp(x,y,z-1);
	int	x_y_z_1 = get_dp(x-1,y-1,z-1);
	
	if( str1[x] == str2[y] && str2[y] == str3[z] )
	{
		dp[z][y][x] = x_y_z_1+1;
	}
	else
	{
		dp[z][y][x] = max(x_1,max(y_1,z_1));
	}
	
	return	dp[z][y][x];
}

int		main(void)
{
	cin>>str1>>str2>>str3;
	
	int	x_len = str1.length();
	int	y_len = str2.length();
	int	z_len = str3.length();
	
	for(int i=1;i<=z_len;i++)
	{
		for(int j=1;j<=y_len;j++)
		{
			for(int k=1;k<=x_len;k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	str1.insert(str1.begin(),' ');
	str2.insert(str2.begin(),' ');
	str3.insert(str3.begin(),' ');
	
	cout<<get_dp(x_len,y_len,z_len)<<endl;
	
	return	0;
}
