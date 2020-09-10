#include	<iostream>
#include	<queue>

using namespace	std;

priority_queue<int>	num;

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		num.push(n);
	}
	
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",num.top());
		num.pop();
	}
	
	return	0;
}
