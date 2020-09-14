#include	<iostream>
#include	<queue>

using namespace	std;

typedef	long long int	int64;

#define	MAX_NUM_OF_STICK	(500000+1)

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int						n;
	int64					sum,total_cost;
	priority_queue<int64>	pq;
	
	cin>>n;
	sum = 0;
	
	for(int i=1;i<=n;i++)
	{
		int64	s;
		
		cin>>s;
		pq.push(-s);
		sum += s;
	}
	
	total_cost = 0;
	
	while( pq.size() > 1 )
	{
		int64	len;
		
		len = -pq.top();
		sum -= len;
		total_cost += sum*len;
		
		pq.pop();
	}
	
	cout<<total_cost<<'\n';
	
	return	0;
}
