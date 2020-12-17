#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(2000+1)
#define	TBD			-1
#define	MOD(n)		((n)%1000000007)

int			N,L,dp[MAX_SIZE][MAX_SIZE];
vector<int>	d[MAX_SIZE];

void	get_divisors(int n)
{
	for(int i=1;i<=n;i++)
	{
		if( n%i == 0 )
		{
			d[n].push_back(i);
		}
	}
}

void	init(void)
{
	cin>>N>>L;
	
	fill(&dp[1][1],&dp[1][N+1],1);
	
	for(int i=2;i<=L;i++)
	{
		fill(&dp[i][1],&dp[i][N+1],TBD);
	}
	
	for(int i=1;i<=N;i++)
	{
		get_divisors(i);
	}
}

int		get_dp(int n,int idx)
{
	int&	ret = dp[idx][n];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = 0;
	
	for(int i=0;i<d[n].size();i++)
	{
		ret = MOD(ret+get_dp(d[n][i],idx-1));
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	sum;
	
	init();
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		sum = MOD(sum+get_dp(i,L));
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
