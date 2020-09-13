#include	<iostream>
#include	<string>

using namespace	std;

#define	FAVORITE_NUM	20000303
#define	char2int(c)		((int)((c)-'0'))

int	main(void)
{
	string	N;
	int		n,i;
	
	cin>>N;
	
	for(i=n=0;i<N.length();i++)
	{
		n = n*10+char2int(N[i]);
		
		if( n >= FAVORITE_NUM )
		{
			n = n%FAVORITE_NUM;
		}
	}
	
	cout<<n<<'\n';
	
	return	0;
}
