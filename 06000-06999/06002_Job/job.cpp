#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(220+1)

typedef	pair<int,int>	Path;	// first:city,second:cost

int				D,P,C,F,S,dp[MAX_SIZE];
vector<Path>	connected[MAX_SIZE];

void	input(void)
{
	cin>>D>>P>>C>>F>>S;
	
	for(int i=1;i<=P;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		connected[A].push_back(make_pair(B,0));
	}
	
	for(int i=1;i<=F;i++)
	{
		int	J,K,T;
		
		cin>>J>>K>>T;
		connected[J].push_back(make_pair(K,T));
	}
}

int		make_money(void)
{
	int		ret;
	bool	updated;
	
	ret = D;
	dp[S] = D;
	updated = true;
    
	for(int cnt=1;cnt<=C&&updated!=false;cnt++)
	{
		updated = false;
		
		for(int i=1;i<=C;i++)
		{
			if( dp[i] == 0 )
			{
				continue;
			}
			
			vector<Path>&	adj = connected[i];
			
			for(int j=0;j<adj.size();j++)
			{
				int&	adj_city = adj[j].first;
				int&	adj_cost = adj[j].second;
				
				if( dp[i] < adj_cost )
				{
					continue;
				}
				
				if( dp[i]-adj_cost+D <= dp[adj_city] )
				{
					continue;
				}
				
				updated = true;
				dp[adj_city] = dp[i]-adj_cost+D;
				ret = max(ret,dp[adj_city]);
			}
		}

		if( updated==true && cnt==C )
		{
			ret = -1;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<make_money()<<'\n';
	
	return	0;
}
