#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

typedef	unsigned long long	uint64;

#define	abs(n)	(((n)>=0)?(n):-(n))

int	main(void)
{
	int		N;
	uint64	sum;
	
	vector<int>	rank;
	
	cin>>N;
	
	rank.push_back(0);
	
	for(int i=1;i<=N;i++)
	{
		int	r;
		
		cin>>r;
		rank.push_back(r);
	}
	
	sort(rank.begin(),rank.end());
	
	sum = 0;
	
	for(int i=1;i<=N;i++)
	{
		sum += abs(i-rank[i]);
	}
	cout<<sum<<endl;
	
	return	0;
}
