#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	find_lis(vector<int>& port)
{
	vector<int> lis;
	
	for(int i=0;i<port.size();i++)
	{
		int&	n = port[i];
		
		vector<int>::iterator	it = lower_bound(lis.begin(),lis.end(),n);
		
		if( it == lis.end() )
		{
			lis.push_back(n);
		}
		else
		{
			*it = n;
		}
	}
	
	return	lis.size();
}

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		int			N;
		vector<int>	p;
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			int	k;
			
			cin>>k;
			p.push_back(k);
		}
		
		cout<<find_lis(p)<<'\n';
		
		T--;
	}
	
	return	0;
}
