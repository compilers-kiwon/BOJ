#include	<iostream>

using namespace	std;

int	get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

int	main(void)
{
	int	A,B,P,Q,gcd;
	
	cin>>A>>B;
	
	P = B-A;
	Q = B;
	gcd = get_gcd(P,Q);
	
	cout<<P/gcd<<' '<<Q/gcd<<'\n';
	
	return	0;
}
