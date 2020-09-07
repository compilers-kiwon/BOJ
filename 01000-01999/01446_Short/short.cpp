#include	<iostream>
#include	<vector>
#include	<map>

using namespace	std;

typedef	vector< pair<int,int> > Shortcut;

#define	MAX_LEN		10000

#define	from		first
#define	distance	second

int					dp[MAX_LEN+1];
map<int,Shortcut>	short_table;

int	get_dp(int p)
{
	if( dp[p] != -1 )
	{
		return	dp[p];
	}
	
	dp[p] = get_dp(p-1)+1;
	
	if( short_table[p].size() != 0 )
	{
		for(int i=0;i<short_table[p].size();i++)
		{
			dp[p] = min(dp[p],get_dp(short_table[p][i].from)+short_table[p][i].distance);
		}
	}
	
	return	dp[p];
}

int	main(void)
{
	int	N,D;
	
	cin>>N>>D;
	
	for(int i=1;i<=D;i++)
	{
		dp[i] = -1;
	}
	dp[0] = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	S,E,L;
		
		cin>>S>>E>>L;
		short_table[E].push_back(make_pair(S,L));
	}
	
	cout<<get_dp(D)<<endl;
	
	return	0;
}
