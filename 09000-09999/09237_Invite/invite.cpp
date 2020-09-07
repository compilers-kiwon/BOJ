#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_WOODS	(100000+1)

int	wood[MAX_NUM_OF_WOODS];

int	main(void)
{
	int	N,max_day;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&wood[i]);
	}
	
	sort(&wood[1],&wood[N+1]);
	
	max_day = 0;
	
	for(int i=N,j=1;i>=1;i--,j++)
	{
		max_day = max(max_day,wood[i]+j+1);
	}
	cout<<max_day<<endl;
	
	return	0;
}
