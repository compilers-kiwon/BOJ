#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_AMOUNT	(1000000+1)

typedef	long long int	int64;

int					ballot[MAX_AMOUNT];
priority_queue<int>	min_q,max_q;

void	throw_bill(int bill)
{
	ballot[bill]++;
	
	min_q.push(-bill);
	max_q.push(bill);
}

int64	get_today_prize(void)
{
	int	min_amount,max_amount;
	
	while( !max_q.empty() )
	{
		max_amount = max_q.top();
		max_q.pop();
		
		if( ballot[max_amount] != 0 )
		{
			ballot[max_amount]--;
			break;
		}
	}
	
	while( !min_q.empty() )
	{
		min_amount = -min_q.top();
		min_q.pop();
		
		if( ballot[min_amount] != 0 )
		{
			ballot[min_amount]--;
			break;
		}
	}
	
	return	(int64)(max_amount-min_amount);
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	int		n;
	int64	sum;
	
	cin>>n;
	sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	k;
		
		cin>>k;
		
		for(int i=1;i<=k;i++)
		{
			int	amount;
			
			cin>>amount;
			throw_bill(amount);
		}
		
		sum += get_today_prize();
	}
	
	cout<<sum<<'\n';
	
	return	0;
}
