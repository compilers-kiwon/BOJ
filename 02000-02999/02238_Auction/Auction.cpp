#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

typedef	vector<string>	Auctioneer;

map<int,Auctioneer>	auction;
int					U,N;

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>U>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	S;
		int		P;
		
		cin>>S>>P;
		auction[P].push_back(S);
	}
	
	int		min_num,win_price;
	string	winner;
	
	map<int,Auctioneer>::iterator	it;
	
	min_num = 0x7FFFFFFF;
	
	for(it=auction.begin();it!=auction.end();it++)
	{
		if( it->second.size() < min_num )
		{
			min_num = it->second.size();
			winner = it->second[0];
			win_price = it->first;
		}
	}
	
	cout<<winner<<' '<<win_price<<'\n';
	
	return	0;
}
