#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

void	input(priority_queue<int>& pq)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	h;
		
		cin>>h;
		pq.push(h);
	}
}

int		get_min_diff(priority_queue<int>& pq1,priority_queue<int>& pq2)
{
	int	min_diff;
	
	for(min_diff=0x7FFFFFFF;!pq1.empty()&&!pq2.empty();)
	{
		min_diff = min(min_diff,abs(pq1.top()-pq2.top()));
		
		if( pq1.top() > pq2.top() )
		{
			pq1.pop();
		}
		else if( pq1.top() < pq2.top() )
		{
			pq2.pop();
		}
		else
		{
			pq1.pop();
			pq2.pop();
		}
	}
	
	return	min_diff;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		priority_queue<int>	m1,m2;
		
		input(m1);
		input(m2);
		
		cout<<get_min_diff(m1,m2)<<'\n';
	}
	
	return	0;
}
