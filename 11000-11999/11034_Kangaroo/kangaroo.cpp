#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	A,B,C;
	
	for(;scanf("%d %d %d",&A,&B,&C)==3;)
	{
		int left,right;
		
		left = B-A;
		right = C-B;
		
		cout<<max(left,right)-1<<'\n';
	}
	
	return	0;
}
