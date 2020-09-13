#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

int	main(void)
{
	int			N,M,cnt,i,cost;
	vector<int>	num_of_fail;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	for(cnt=0,i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		
		if( A >= N )
		{
			cnt++;
		}
		else
		{
			num_of_fail.push_back(N-A);
		}
	}
	
	sort(num_of_fail.begin(),num_of_fail.end());
	
	for(i=0,cost=0;i<M-1-cnt;i++)
	{
		cost += num_of_fail[i];
	}
	
	cout<<cost<<'\n';
	
	return	0;
}
