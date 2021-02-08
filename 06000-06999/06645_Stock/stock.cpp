#include	<iostream>
#include	<map>
#include	<queue>
#include	<string>
#include	<vector>

using namespace	std;

#define	BUYER	0
#define	SELLER	1

typedef	pair<int,string>	Issuer;
typedef	vector<Issuer>		Bid;
typedef	pair<double,Issuer>	Dealer;

bool	input(map<double,Bid>& buyer,map<double,Bid>& seller,
			  string& stock,vector<Dealer>& dealer)
{
	int	N;
	
	cin>>N>>stock;
	
	if( N==0 && stock=="END" )
	{
		return	false;
	}
	
	for(int i=1;i<=N;i++)
	{
		string	name,type;
		double	price;
		
		cin>>name>>type>>price;
		
		if( type == "buy" )
		{
			buyer[price].push_back(make_pair(-i,name));
			dealer.push_back(make_pair(price,make_pair(BUYER,name)));
		}
		else
		{
			seller[price].push_back(make_pair(-i,name));
			dealer.push_back(make_pair(price,make_pair(SELLER,name)));
		}
	}
	
	return	true;
}

void	get_buyer_deal(priority_queue<Issuer>& issuer,
					   double price,map<double,Bid>& seller)
{
	map<double,Bid>::iterator it1,it2;
	
	for(it1=seller.begin(),it2=seller.upper_bound(price);it1!=it2;it1++)
	{
		Bid&	b = it1->second;
		
		for(int i=0;i<b.size();i++)
		{
			issuer.push(b[i]);
		}
	}
}

void	get_seller_deal(priority_queue<Issuer>& issuer,
					    double price,map<double,Bid>& buyer)
{
	map<double,Bid>::iterator it;
	
	for(it=buyer.lower_bound(price);it!=buyer.end();it++)
	{
		Bid&	b = it->second;
		
		for(int i=0;i<b.size();i++)
		{
			issuer.push(b[i]);
		}
	}
}

void	print(const string& name,priority_queue<Issuer>& issuer)
{
	cout<<name<<":";
	
	if( issuer.empty() )
	{
		cout<<" NO-ONE\n";
	}
	else
	{
		for(;!issuer.empty();issuer.pop())
		{
			cout<<' '<<issuer.top().second;
		}
		cout<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string			stock;
		vector<Dealer>	dealer;
		map<double,Bid>	buyer,seller;
		
		if( input(buyer,seller,stock,dealer) == false )
		{
			break;
		}
		
		cout<<stock<<'\n';
		
		for(int i=0;i<dealer.size();i++)
		{
			priority_queue<Issuer>	pq;
			
			if( dealer[i].second.first == BUYER )
			{
				get_buyer_deal(pq,dealer[i].first,seller);
			}
			else
			{
				get_seller_deal(pq,dealer[i].first,buyer);
			}
			
			print(dealer[i].second.second,pq);
		}
	}
	
	return	0;
}
