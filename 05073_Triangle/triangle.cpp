#include	<iostream>

using namespace	std;

int	main(void)
{
	while(1)
	{
		int	a,b,c;
		int	l,s1,s2;
		
		cin>>a>>b>>c;
		
		if( a == 0 && b == 0 && c == 0 )
		{
			break;
		}
		
		l = max(a,max(b,c));
		s1 = min(a,min(b,c));
		s2 = (a+b+c)-(l+s1);
		
		if( l >= s1 + s2 )
		{
			cout<<"Invalid\n";
		}
		else
		{
			if( l == s1 )
			{
				cout<<"Equilateral\n";
			}
			else if( l == s2 || s2 == s1 )
			{
				cout<<"Isosceles\n";
			}
			else
			{
				cout<<"Scalene\n";
			}
		}
	}
	return	0;
}
