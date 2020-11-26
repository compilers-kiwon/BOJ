#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	L;
	
	cin>>L;
	
	for(int i=1;i<=L;i++)
	{
		int		n;
		char	c;
		
		cin>>n>>c;
		
		for(int j=1;j<=n;j++)
		{
			cout<<c;	
		}
		
		cout<<'\n';
	}
	
	return	0;
}
