#include	<iostream>
#include	<vector>
#include	<cmath>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(300+1)
#define	TBD			-1
#define	MOD(n)		((n)%1000000007)
								
int	N,H[MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>H[i];
	}
}

int		get_divisors(vector<int>& d,int h)
{
	int	ret = 0;
	
	for(int i=1,to=sqrt(h);i<=to;i++)
	{
		if( h%i == 0 )
		{
			d.push_back(i);
			d.push_back(h/i);
			
			ret += 2;
		}
	}
	
	if( (int)sqrt(h)*(int)sqrt(h) == h )
	{
		d.pop_back();
		ret--;
	}
	
	sort(d.begin(),d.end());
	
	return	ret;
}

void	init(vector<int>* div)
{
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		n = get_divisors(div[i],H[i]);
		fill(&dp[i][0],&dp[i][n],TBD);
		
		dp[i][0] = 1;
	}
	
	fill(&dp[1][0],&dp[1][div[1].size()],1);
}

int		get_dp(int row,int col,vector<int>* div,int current_cut)
{
	int&	ret = dp[row][col];
	
	if( ret != TBD )
	{
		return	ret;
	}
	
	ret = 0;

	for(int prev_cut=0;
		prev_cut<div[row-1].size()&&div[row-1][prev_cut]<=current_cut;
		prev_cut++)
	{
		ret = MOD(ret+get_dp(row-1,prev_cut,div,div[row-1][prev_cut]));
	}

	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		vector<int>	divisors[MAX_SIZE];
		
		input();
		init(divisors);
		
		int	sum = 0;
		
		for(int i=0;i<divisors[N].size();i++)
		{
			sum = MOD(sum+get_dp(N,i,divisors,divisors[N][i]));
		}

		cout<<sum<<'\n';
	}
	
	return	0;
}
