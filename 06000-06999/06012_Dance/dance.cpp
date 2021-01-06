#include	<iostream>

using namespace	std;

int	get_sum(int s,int e)
{
	int	size,mid;
	
	size = e-s+1;
	
	if( size == 1 )
	{
		return	0;
	}
	
	if( size == 2 )
	{
		return	s*e;
	}
	
	mid = s+(size-1)/2;
	
	return	get_sum(s,mid)+get_sum(mid+1,e);
}

int	main(void)
{
	int	N;
	
	cin>>N;
	cout<<get_sum(1,N)<<'\n';
	
	return	0;
}
