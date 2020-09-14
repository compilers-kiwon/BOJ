#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int			n,sum,avg;
		vector<int>	a;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		sum = 0;
		
		for(int i=1;i<=n;i++)
		{
			int	m;
			
			cin>>m;
			sum += m;
			a.push_back(m);
		}
		
		avg = sum/n;
		sort(a.begin(),a.end());
		
		cout<<lower_bound(a.begin(),a.end(),avg+1)-a.begin()<<'\n';
	}
	
	return	0;
}
