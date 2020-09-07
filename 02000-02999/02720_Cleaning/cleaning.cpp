#include	<iostream>

using namespace	std;

#define	QUARTER	25
#define	DIME	10
#define	NICKEL	5
#define	PENNY	1

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	C,q,d,n,p;
		
		cin>>C;
		
		q = C/QUARTER;
		C %= QUARTER;
		
		d = C/DIME;
		C %= DIME;
		
		n = C/NICKEL;
		C %= NICKEL;
		
		p = C;
		
		cout<<q<<' '<<d<<' '<<n<<' '<<p<<endl;
		 
		T--;
	}
	return	0;
}
