#include	<iostream>

using namespace	std;

#define	A	300
#define	B	60
#define	C	10

int	main(void)
{
	int	T;
	
	cin>>T;
	
	int	cntA,cntB,cntC;
	
	cntA = T/A;
	T = T%A;
	
	cntB = T/B;
	T = T%B;
	
	cntC = T/C;
	T = T%C;
	
	if( T == 0 )
	{
		cout<<cntA<<' '<<cntB<<' '<<cntC<<endl;
	}
	else
	{
		cout<<"-1\n";
	}
	
	return	0;
}
