#include	<iostream>

using namespace	std;

#define	PARALLEL(d,n,p)	((d)+(n)*(p))
#define	SERIAL(n,s)		((n)*(s))

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	d,n,s,p;
		int	parallel,serial;
		
		cin>>d>>n>>s>>p;
		
		parallel = PARALLEL(d,n,p);
		serial = SERIAL(n,s);
		
		if( parallel < serial )
		{
			cout<<"parallelize\n";
		}
		else if( parallel > serial )
		{
			cout<<"do not parallelize\n";
		}
		else
		{
			cout<<"does not matter\n";
		}
		
		T--;
	}
	
	return	0;
}
