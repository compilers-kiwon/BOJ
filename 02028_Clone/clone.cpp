#include	<iostream>
#include	<string>

using namespace	std;

#define	int2char(i)	((char)((i)+(int)'0'))

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		N,square;
		string	src,sqr;
		
		cin>>N;
		square = N*N;
		
		for(;N>0;N/=10)
		{
			src.push_back(int2char(N%10));
		}
		
		for(;sqr.length()!=src.length();square/=10)
		{
			sqr.push_back(int2char(square%10));
		}
		
		if( src == sqr )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		
		T--;
	}
	
	return	0;
}
