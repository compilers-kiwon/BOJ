#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	b;
		
		cin>>b;
		
		for(int x=0;x<=255;x++)
		{
			if( ((x^(x<<1))&0xFF) == b )
			{
				cout<<x<<' ';
				break;
			}
		}
	}
	cout<<'\n';
	
	return	0;
}
