#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int			N,M;
	vector<int>	material;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		material.push_back(n);
	}
	
	sort(material.begin(),material.end());
	
	int	h,t,cnt;
	
	for(h=0,t=N-1,cnt=0;h<t;)
	{
		int	sum;
		
		sum = material[h]+material[t];
		
		if( sum > M )
		{
			t--;
		}
		else if( sum < M )
		{
			h++;
		}
		else
		{
			cnt++;
			h++;t--;
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
