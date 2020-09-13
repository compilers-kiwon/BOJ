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
		
		scanf("%d",&n);
		pq.push(-n);
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",-pq.top());
		pq.pop();
	}
	
	return	0;
}
