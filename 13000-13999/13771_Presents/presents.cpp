#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int						N;
	priority_queue<double>	price;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		double	p;
		
		scanf("%lf",&p);
		price.push(-p);
	}
	
	price.pop();
	printf("%.02f\n",-price.top());
	
	return	0;
}
