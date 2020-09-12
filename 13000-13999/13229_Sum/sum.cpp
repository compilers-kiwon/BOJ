#include	<iostream>
#include	<vector>

using namespace	std;

int	get_sum(int start,int end,vector<int>& sum)
{
	int	ret;
	
	if( start == 0 )
	{
		ret = sum[end];
	}
	else
	{
		ret = sum[end]-sum[start-1];
	}
	
	return	ret;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	vector<int>	sum(n);
	
	cin>>sum[0];
	
	for(int i=1;i<n;i++)
	{
		int	k;
		
		cin>>k;
		sum[i] = sum[i-1]+k;
	}
	
	int	m;
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	s,e;
		
		cin>>s>>e;
		cout<<get_sum(s,e,sum)<<'\n';
	}
	
	return	0;
}
