#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					n;
	priority_queue<int>	pq;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	a;
		
		cin>>a;
		
		if( a == 0 )
		{
			if( pq.empty() )
			{
				cout<<"-1\n";
			}
			else
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else
		{
			for(int j=1;j<=a;j++)
			{
				int	p;
				
				cin>>p;
				pq.push(p);
			}
		}
	}
	
	return	0;
}
