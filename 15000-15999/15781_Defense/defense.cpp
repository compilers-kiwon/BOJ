#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,M,max_h,max_a;
	
	cin>>N>>M;
	max_h = max_a = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	h;
		
		cin>>h;
		max_h = max(max_h,h);
	}
	
	for(int i=1;i<=M;i++)
	{
		int	a;
		
		cin>>a;
		max_a = max(max_a,a);
	}
	
	cout<<max_h+max_a<<'\n';
	
	return	0;
}
