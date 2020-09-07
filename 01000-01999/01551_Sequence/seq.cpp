#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	20

vector<int>	set[MAX_SIZE];

int	main(void)
{
	int	N,K,n;
	
	cin>>N>>K;
	
	for(int i=1;i<N;i++)
	{
		scanf("%d,",&n);
		set[0].push_back(n);
	}
	scanf("%d",&n);
	set[0].push_back(n);
	
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<set[i-1].size();j++)
		{
			set[i].push_back(set[i-1][j]-set[i-1][j-1]);
		}
	}
	
	for(int i=0;i<set[K].size()-1;i++)
	{
		cout<<set[K][i]<<',';
	}
	cout<<set[K][set[K].size()-1]<<endl;
	
	return	0;
}
