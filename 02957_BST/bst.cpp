#include	<iostream>
#include	<map>

using namespace	std;

int	main(void)
{
	int				N,X;
	map<int,int>	tree;
	long long int	sum;
	
	scanf("%d %d",&N,&X);
	tree[X] = 0;
	puts("0");
	sum = 0;
	
	for(int i=2;i<=N;i++)
	{
		scanf("%d",&X);
		
		map<int,int>::iterator	iter;
		
		iter = tree.lower_bound(X);
		
		int	left,right;
		
		if( iter == tree.begin() )
		{
			left = 0;
			right = iter->second;
		}
		else if( iter == tree.end() )
		{
			left = (--iter)->second;
			right = 0;
		}
		else
		{
			right = iter->second;
			left = (--iter)->second;
		}
		
		tree[X] = max(left,right)+1;
		sum += tree[X];
		printf("%lld\n",sum);
	}
	
	return	0;
}
