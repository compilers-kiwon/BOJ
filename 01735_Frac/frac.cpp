#include	<iostream>

using namespace	std;

int	get_gcd(int a,int b)
{
	int	gcd,i;
	
	gcd=1;
	
	for(i=min(a,b);i>=2;i--)
	{
		if( a%i == 0 && b%i == 0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

int	main(void)
{
	int	A1,B1,A2,B2,A,B;
	
	cin>>A1>>B1>>A2>>B2;
	
	A = A1*B2+A2*B1;
	B = B1*B2;
	
	int	gcd = get_gcd(A,B);
	
	cout<<A/gcd<<' '<<B/gcd<<endl;
	
	return	0;
}
