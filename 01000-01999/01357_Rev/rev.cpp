#include	<iostream>

using namespace	std;

#define	MAX_LEN	4

int	rev(int n)
{
	int		value;
	
	for(value=0;n>0;n=n/10)
	{
		value = value*10+n%10;
	}
	return	value;
}

int	main(void)
{
	int	X,Y;
	
	cin>>X>>Y;
	cout<<rev(rev(X)+rev(Y))<<endl;
	
	return	0;
}

