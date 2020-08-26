#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int					N;
	priority_queue<int>	pq;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		pq.push(-n);
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<-pq.top()<<'\n';
		pq.pop();
	}
	
	return	0;
}
