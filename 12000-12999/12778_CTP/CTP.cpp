#include	<iostream>

using namespace	std;

#define	CHAR2int(C)	((int)((C)-'A')+1)
#define	int2CHAR(n)	((char)((n)-1+(int)'A'))

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int		M;
		char	p;
		
		cin>>M>>p;
		
		if( p == 'C' )
		{
			for(int i=1;i<=M;i++)
			{
				char	c;
				
				cin>>c;
				cout<<CHAR2int(c)<<' ';
			}
		}
		else
		{
			for(int i=1;i<=M;i++)
			{
				int	n;
				
				cin>>n;
				cout<<int2CHAR(n)<<' ';
			}
		}
		cout<<endl;
		
		T--;
	}
	return	0;
}
