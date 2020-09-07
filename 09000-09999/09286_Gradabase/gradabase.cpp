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
		cout<<"Case "<<i<<":\n";
		
		int	m;
		
		cin>>m;
		
		for(int j=1;j<=m;j++)
		{
			int	num;
			
			cin>>num;
			
			if( num+1 <= 6 )
			{
				cout<<num+1<<'\n';
			}
		}
	}
	
	return	0;
}
