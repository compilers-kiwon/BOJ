#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,M,K;
	
	cin>>N>>M>>K;
	
	int	front_o,front_x,back_o,back_x;
	
	front_o = M;
	front_x = N-M;
	
	back_o = K;
	back_x = N-K;
	
	cout<<min(front_o,back_o)+min(front_x,back_x)<<'\n';
	
	return	0;
}
