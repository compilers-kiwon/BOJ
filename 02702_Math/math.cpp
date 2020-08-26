#include	<iostream>

using namespace	std;

int	get_gcd(int n1,int n2)
{
	int	s,b,gcd;
	
	s = min(n1,n2);
	b = max(n1,n2);
	
	if( b%s == 0 )
	{
		return	s;
	}
	
	gcd = 1;
	
	for(int i=s/2;i>=2;i--)
	{
		if( n1%i==0 && n2%i==0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	a,b,gcd,lcm;
		
		cin>>a>>b;
		gcd = get_gcd(a,b);
		lcm = a*b/gcd;
		cout<<lcm<<' '<<gcd<<endl;
		
		T--;
	}
	return	0;
}
