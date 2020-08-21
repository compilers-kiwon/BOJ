#include	<iostream>
#include	<vector>
#include	<cfloat>

using namespace	std;

#define	MAX_NUM_OF_COUNTRY	(2000+1)

typedef	pair<int,long double>	Exchange;	// first:country,second:rate

int					N,M,A,B;
long double			V,dp[MAX_NUM_OF_COUNTRY];
vector<Exchange>	ex[MAX_NUM_OF_COUNTRY];

void	input(void)
{
	cin>>N>>M>>V>>A>>B;
	
	for(int i=1;i<=M;i++)
	{
		int			c1,c2;
		long double	rate;
		
		cin>>c1>>c2>>rate;
		ex[c1].push_back(make_pair(c2,rate));
	}
}

bool	calculate_big_mac_value(void)
{
	dp[A] = V;
	
	for(int cnt=1;;cnt++)
	{
		bool	update_flag;
		
		update_flag = false;
		
		for(int i=1;i<=N;i++)
		{
			if( dp[i] == DBL_MAX )
			{
				continue;
			}
			
			for(int j=0;j<ex[i].size();j++)
			{
				int&			adj_country = ex[i][j].first;
				long double&	adj_rate = ex[i][j].second;
				
				if( dp[i]*adj_rate < dp[adj_country] )
				{
					dp[adj_country] = dp[i]*adj_rate;
					update_flag = true;
				}
			}
		}
		
		if( update_flag == false )
		{
			break;
		}
		else
		{
			if( cnt == N )
			{
				return	false;	
			}	
		}		
		
	}
	
	return	true;
}

int		main(void)
{
	input();
	fill(&dp[1],&dp[N+1],DBL_MAX);
	
	if( calculate_big_mac_value()==false || dp[B]==DBL_MAX )
	{
		puts("0");
	}
	else
	{
		printf("%.06Lf\n",dp[B]);
	}
	
	return	0;
}
