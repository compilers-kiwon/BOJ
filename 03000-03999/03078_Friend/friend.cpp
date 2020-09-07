#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	MAX_LEN	20

typedef	unsigned long long	uint64;

vector<int>	students[MAX_LEN+1];

int	main(void)
{
	int		N,K;
	uint64	cnt;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		string	name;
		
		cin>>name;
		students[name.length()].push_back(i);
	}
	
	cnt = 0;
	
	for(int i=2;i<=MAX_LEN;i++)
	{
		vector<int>&	t = students[i];
		
		for(int j=0;j<t.size();j++)
		{
			int	hi;
		
			hi = upper_bound(t.begin(),t.end(),t[j]+K)-t.begin();
			cnt += (hi-j-1);
		}
	}
	cout<<cnt<<endl;
	
	return	0;
}
