#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>	Number;

priority_queue<Number>	arr;

int	main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	x;
		
		scanf("%d",&x);
		
		if( x == 0 )
		{
			if( arr.size() != 0 )
			{
				printf("%d\n",-arr.top().second);
				arr.pop();
			}
			else
			{
				puts("0");
			}
		}
		else
		{
			arr.push(make_pair(-abs(x),-x));
		}
	}
	return	0;
}
