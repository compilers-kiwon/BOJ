#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int	P,M,F,C;
		int	num_of_chicken_to_buy,num_of_coupon;
		int	sang,doo;
		
		cin>>P>>M>>F>>C;
		
		num_of_chicken_to_buy = M/P;
		num_of_coupon = num_of_chicken_to_buy*C;
		
		doo = num_of_chicken_to_buy+num_of_coupon/F;
		sang = num_of_chicken_to_buy+((num_of_coupon>=F)?(num_of_coupon-F)/(F-C)+1:0);
		
		cout<<sang-doo<<'\n';
	}
	
	return	0;
}
