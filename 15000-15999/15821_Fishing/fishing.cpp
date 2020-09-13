#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	int				K,N;
	vector<int64>	d;
	
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		int		P;
		int64	max_far;
		
		scanf("%d",&P);
		
		max_far = 0;
		
		for(int j=1;j<=P;j++)
		{
			int64	x,y;
			
			scanf("%lld %lld",&x,&y);
			max_far = max(max_far,x*x+y*y);
		}
		
		d.push_back(max_far);
	}
	
	sort(d.begin(),d.end());
	
	printf("%lld.00\n",d[K-1]);
	
	return	0;
}
