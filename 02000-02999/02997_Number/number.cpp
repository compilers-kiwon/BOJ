#include	<iostream>

using namespace	std;

int	main(void)
{
	int	a,b,c;
	int	n1,n2,n3,n;
	int	diff1,diff2;
	
	cin>>a>>b>>c;
	
	n1 = max(a,max(b,c));
	n3 = min(a,min(b,c));
	n2 = (a+b+c)-(n1+n3);
	
	diff1 = n1-n2;
	diff2 = n2-n3;
	
	if( diff1 > diff2 )
	{
		n = (n1+n2)/2;
	}
	else if( diff1 < diff2 )
	{
		n = (n2+n3)/2;
	}
	else
	{
		n = n1+diff1;
	}
	cout<<n<<endl;
	
	return	0;
}
