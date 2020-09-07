#include	<iostream>
#include	<vector>

using namespace	std;

typedef	struct	_DEAL_INFO	Deal;
struct	_DEAL_INFO
{
	int	s,p,r;
};

int		get_payment(int stay,int pay,int num_of_repeats,int num_of_nights)
{
	int		p;
	
	p = 0;
	
	for(int i=1;i<=num_of_repeats;i++)
	{
		if( num_of_nights < stay )
		{
			p += min(num_of_nights,pay);
			num_of_nights = 0;
			
			break;
		}
			
		p += pay;
		num_of_nights -= stay;
	}
	
	p += num_of_nights;
	
	return	p;
}

void	input(string& hotel_name,vector<Deal>& d,vector<int>& nights)
{
	cin>>hotel_name;
	
	for(;;)
	{
		Deal	tmp;
		
		cin>>tmp.s>>tmp.p>>tmp.r;
		
		if( tmp.s==0 && tmp.p==0 && tmp.r==0 )
		{
			break;
		}
		
		d.push_back(tmp);
	}
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		nights.push_back(n);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	h,name;
		
		cin>>h;
		
		if( h == "#" )
		{
			break;
		}
		
		vector<Deal>	deals;
		vector<int>		nights;
		
		input(name,deals,nights);
		
		for(int i=0;i<nights.size();i++)
		{
			int	min_pay;
			
			min_pay = nights[i];
			
			for(int j=0;j<deals.size();j++)
			{
				min_pay = min(min_pay,get_payment(deals[j].s,deals[j].p,deals[j].r,nights[i]));
			}
			
			cout<<"Stay "<<nights[i];
			
			if( nights[i] == 1 )
			{
				cout<<" night at Hotel "<<name<<", pay "<<min_pay<<".\n";
			}
			else
			{
				cout<<" nights at Hotel "<<name<<", pay "<<min_pay<<".\n";
			}
		}	
	}
	
	return	0;
}
