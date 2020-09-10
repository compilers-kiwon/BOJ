#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

int	main(void)
{
	string	N;
	int		sum,n,i;
	
	getline(cin,N);
	
	for(i=0,sum=0,n=0;i<N.length();i++)
	{
		if( N[i] == ' ' )
		{
			sum += n;
			n = 0;
		}
		else
		{
			n = n*10+char2int(N[i]);
		}
	}
	sum += n;
	cout<<sum<<endl;
	
	return	0;
}
