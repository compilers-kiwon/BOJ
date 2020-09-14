#include	<iostream>
#include	<cmath>

using namespace	std;

int	calculate(int a,int b,char op)
{
	int	result,sign;
	
	switch(op)
	{
		case	'+':
			result = a+b;
			break;
		case	'-':
			result = a-b;
			break;
		case	'*':
			result = a*b;
			break;
		case	'/':
			if( (a>=0&&b<0) || (a<0&&b>=0) )
			{
				sign = -1;
				a = abs(a);
				b = abs(b);
			}
			else
			{
				sign = 1;
			}
			result = sign*(a/b);
			break;
	}
	
	return	result;
}

int	main(void)
{
	int		K1,K2,K3,r1,r2;
	char	O1,O2;
	
	cin>>K1>>O1>>K2>>O2>>K3;
	
	r1 = calculate(calculate(K1,K2,O1),K3,O2);
	r2 = calculate(K1,calculate(K2,K3,O2),O1);
	
	cout<<min(r1,r2)<<'\n'<<max(r1,r2)<<'\n';
	
	return	0;
}
