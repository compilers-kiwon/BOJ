#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

#define	uint64TOchar(n)	((char)((n)+(uint64)'0'))

void	dec2bin(uint64& n,string& bin)
{
	for(uint64 i=n;i>0;i/=2)
	{
		bin.insert(bin.begin(),uint64TOchar(i%2));
	}
}

int		main(void)
{
	uint64	N;
	string	b;
	
	cin>>N;
	dec2bin(N,b);
	cout<<b<<endl;
	
	return	0;
}
