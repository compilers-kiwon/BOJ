#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int	N;
	
	priority_queue<double>	pq;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		double	x;
		
		cin>>x;
		pq.push(-x);
	}
	
	for(;pq.size()!=1;)
	{
		double	x1,x2;
		
		x1 = -pq.top();
		pq.pop();
		
		x2 = -pq.top();
		pq.pop();
		
		pq.push(-((x1+x2)/2));
	}
	
	printf("%.06f\n",-pq.top());
	
	return	0;
}
