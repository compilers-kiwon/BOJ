#include	<iostream>
#include	<string>

using namespace	std;

typedef	unsigned long long	uint64;

#define	bit2int(b)	((int)((b)-'0'))

int	bin2int(string& bin)
{
	int	n,i;
	
	for(n=i=0;i<bin.length();i++)
	{
		n = n*2+bit2int(bin[i]);
	}
	
	return	n;
}

int	main(void)
{
	string	b1,b2,b3;
	uint64	m;
	
	cin>>b1>>b2;
	m = (uint64)bin2int(b1)*(uint64)bin2int(b2);
	
	for(;m>0;m/=2)
	{
		if( m%2 == 0 )
		{
			b3.push_back('0');
		}
		else
		{
			b3.push_back('1');
		}
	}
	
	for(int i=b3.length()-1;i>=0;i--)
	{
		cout<<b3[i];
	}
	cout<<endl;
	
	return	0;
}
