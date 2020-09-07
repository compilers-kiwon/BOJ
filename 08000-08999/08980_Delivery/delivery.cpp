#include	<iostream>
#include	<algorithm>

using namespace	std;

typedef	struct	_DELIVERY_INFO	Delivery;
struct	_DELIVERY_INFO
{
	int	from,to,amount;
};

#define	MAX_NUM_OF_VILLAGE	(2000+1)
#define	MAX_NUM_OF_DELIVERY	(10000+1)

int			N,C,M,delivered,truck[MAX_NUM_OF_VILLAGE];
Delivery	d[MAX_NUM_OF_DELIVERY];

bool	is_earlier(const Delivery& d1,const Delivery& d2)
{
	bool	result;
	
	if( d1.to < d2.to )
	{
		result = true;
	}
	else if( d1.to > d2.to )
	{
		result = false;
	}
	else
	{
		if( d1.from < d2.from )
		{
			result = true;
		}
		else
		{
			result = false;
		}	
	}
	
	return	result; 
}

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>C>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>d[i].from>>d[i].to>>d[i].amount;
	}
	
	sort(&d[1],&d[M+1],is_earlier);
}

int		main(void)
{
	init();
	
	for(int i=1;i<=M;i++)
	{
		int	max_delivery,can_be_delivered;
		
		max_delivery = 0;
		
		for(int j=d[i].from;j<d[i].to;j++)
		{
			max_delivery = max(max_delivery,truck[j]);
		}
		
		can_be_delivered = min(d[i].amount,C-max_delivery);
		
		for(int j=d[i].from;j<d[i].to;j++)
		{
			truck[j] += can_be_delivered;
		}
		
		delivered += can_be_delivered;
	}
	
	cout<<delivered<<'\n';
	
	return	0;
}
