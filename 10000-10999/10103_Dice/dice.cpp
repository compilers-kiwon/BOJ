#include	<iostream>

using namespace	std;

int	main(void)
{
	int	n,c,s;
	
	cin>>n;
	c = s = 100;
	
	for(int i=1;i<=n;i++)
	{
		int	cd,sd;
		
		cin>>cd>>sd;
		
		if( cd > sd )
		{
			s -= cd;
		}
		else if( cd < sd )
		{
			c -= sd;
		}
	}
	cout<<c<<endl<<s<<endl;
	
	return	0;
}
