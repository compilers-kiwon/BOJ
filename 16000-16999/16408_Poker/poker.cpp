#include	<iostream>
#include	<string>

using namespace	std;

#define	NUM_OF_CARDS	5

const string	card_rank = "A23456789TJQK";

int	main(void)
{
	int		cnt[0x100],max_value;
	
	for(int i=0;i<card_rank.length();i++)
	{
		cnt[card_rank[i]] = 0;
	}
	
	max_value = 0;
	
	for(int i=1;i<=NUM_OF_CARDS;i++)
	{
		string	c;
		
		cin>>c;
		max_value = max(max_value,++cnt[c[0]]);
	}
	
	cout<<max_value<<'\n';
	
	return	0;
}
