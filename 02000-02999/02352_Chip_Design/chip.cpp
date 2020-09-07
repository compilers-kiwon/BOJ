#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	get_max_num_of_connection(vector<int>& connected)
{
	vector<int>	lis;
	
	for(int i=0;i<connected.size();i++)
	{
		vector<int>::iterator	it;
		
		it = lower_bound(lis.begin(),lis.end(),connected[i]);
		
		if( it != lis.end() )
		{
			*it = connected[i];
		}
		else
		{
			lis.push_back(connected[i]);
		}
	}
	
	return	lis.size();
}

int	main(void)
{
	int			n;
	vector<int>	connected;
	
	cin.sync_with_stdio(false);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	p;
		
		cin>>p;
		connected.push_back(p);
	}
	
	cout<<get_max_num_of_connection(connected)<<'\n';
	
	return	0;
}
