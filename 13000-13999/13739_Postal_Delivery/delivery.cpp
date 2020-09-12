#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>	Delivery;

void	input(vector<Delivery>& left,vector<Delivery>& right,int& capacity)
{
	int	n;
	
	cin>>n>>capacity;
	
	for(int i=1;i<=n;i++)
	{
		int	x,t;
		
		cin>>x>>t;
		
		if( x < 0 )
		{
			left.push_back(make_pair(x,t));
		}
		else
		{
			right.push_back(make_pair(x,t));
		}
	}
}

int		get_travel_distance(vector<Delivery>& d,int& capacity)
{
	int	prev,ret,location;
	
	prev = ret = location = 0;
	
	for(int i=0;i<d.size();i++)
	{
		int&	x = d[i].first;
		int&	t = d[i].second;
		int		sum,n;
		
		sum = prev+t;
		
		if( prev!=0 && sum>=capacity )
		{
			ret += 2*abs(location);
			sum -= capacity;
			location = 0;
		}
		
		n = sum/capacity;
		sum %= capacity;
		ret += 2*n*abs(x);
		
		if( location==0 && sum!=0 )
		{
			location = x;
		}
		
		prev = sum;
	}
	
	if( prev != 0 )
	{
		ret += 2*abs(location);
	}
	
	return	ret;
}

bool	is_greater(const Delivery& d1,const Delivery& d2)
{
	bool	ret;
	
	if( d1.first > d2.first )
	{
		ret = true;	
	}
	else
	{
		ret = false;
	}
	
	return	ret;	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					K;
	vector<Delivery>	left,right;
	
	input(left,right,K);
	
	sort(left.begin(),left.end());
	sort(right.begin(),right.end(),is_greater);
	
	cout<<get_travel_distance(left,K)+get_travel_distance(right,K)<<'\n';
	
	return	0;
}
