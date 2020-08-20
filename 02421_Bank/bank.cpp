#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(999+1)

vector<bool>	prime_table(MAX_SIZE*MAX_SIZE,true);
int				dp[MAX_SIZE][MAX_SIZE];

void	build_prime_table(void)
{
	for(int i=2;i<MAX_SIZE*MAX_SIZE;i++)
	{
		if( prime_table[i] == true )
		{
			for(int j=i+i;j<MAX_SIZE*MAX_SIZE;j+=i)
			{
				prime_table[j] = false;
			}
		}
	}
}

int		get_num(int a,int b)
{
	int	m;
	
	if( b<10 )
	{
		m =10;
	}
	else if( b<100 )
	{
		m = 100;
	}
	else
	{
		m = 1000;
	}
	
	return	a*m+b;
}

int		get_dp(int row,int col)
{
	int&	result = dp[row][col];
	
	if( result != -1 )
	{
		return	result;
	}
	
	result = max(get_dp(row-1,col),get_dp(row,col-1));
	result += (int)prime_table[get_num(row,col)];
	
	return	result;
}

int		main(void)
{
	int	N;
	
	build_prime_table();
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dp[i][j] = -1;
		}
	}
	
	dp[1][1] = 0;
	
	cout<<get_dp(N,N)<<'\n';
	
	return	0;
}
