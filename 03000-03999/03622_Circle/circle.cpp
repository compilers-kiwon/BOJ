#include	<iostream>

using namespace	std;

typedef	pair<int,int>	Circle;

#define	outer	first
#define	inner	second

int	main(void)
{
	int		A,a,B,b,P;
	Circle	big,small;
	
	cin>>A>>a>>B>>b>>P;
	
	if( A > B )
	{
		big = make_pair(A,a);
		small = make_pair(B,b);
	}
	else
	{
		big = make_pair(B,b);
		small = make_pair(A,a);
	}
	
	if( (big.inner>=small.outer&&big.outer<=P) || big.outer+small.outer<=P )
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	
	return	0;
}
