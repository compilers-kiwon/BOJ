#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	a,b,c;
		int	l,s1,s2;
		
		cin>>a>>b>>c;
		
		l = max(a,max(b,c));
		s1 = min(a,min(b,c));
		s2 = (a+b+c)-(l+s1);
		
		cout<<"Scenario #"<<i<<":\n";
		
		if( l*l == s1*s1+s2*s2 )
		{
			cout<<"yes\n\n";
		}
		else
		{
			cout<<"no\n\n";
		}
	}
	
	return	0;
}
