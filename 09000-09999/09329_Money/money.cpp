#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_PRIZE	(10+1)
#define	MAX_STICKER	(30+1)
#define	INF			0x7FFFFFFF

typedef	pair<vector<int>,int>	Prize;	// first:required,second:money

int		n,m;
int		num_of_stickers[MAX_STICKER];
Prize	p[MAX_PRIZE];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int	k;
		
		cin>>k;
		p[i].first.clear();
		
		for(int j=1;j<=k;j++)
		{
			int	s;
			
			cin>>s;
			p[i].first.push_back(s);
		}
		
		cin>>p[i].second;
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>num_of_stickers[i];
	}
}
	
int		get_max_num_of_exchanges(int p_idx)
{
	int				ret;
	vector<int>&	required = p[p_idx].first;
	
	ret = INF;
	
	for(int i=0;i<required.size();i++)
	{
		ret = min(ret,num_of_stickers[required[i]]);
	}
	
	return	ret;
}

int		exchange_money(int p_idx)
{
	if( p_idx > n )
	{
		return	0;
	}
	
	int	possible_exchanges;
	
	possible_exchanges = get_max_num_of_exchanges(p_idx);
	
	return possible_exchanges*p[p_idx].second+exchange_money(p_idx+1);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		input();
		cout<<exchange_money(1)<<'\n';
	}
	
	return	0;
}
