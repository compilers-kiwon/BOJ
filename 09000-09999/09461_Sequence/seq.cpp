#include	<iostream>
#include	<vector>

using namespace std;

typedef	unsigned long long	uint64;

#define	MAX_LEN	(100+1)

vector<uint64>	seq(MAX_LEN);
vector<int>		query(MAX_LEN);

int		main(void)
{
	int	T,max_query;
	
	cin>>T;
	
	max_query = 0;
	
	for(int i=1;i<=T;i++)
	{
		cin>>query[i];
		max_query = max(max_query,query[i]);
	}
	
	seq[1] = seq[2] = seq[3] = 1;
	seq[4] = seq[5] = 2;
	
	for(int i=6;i<=max_query;i++)
	{
		seq[i] = seq[i-1]+seq[i-5];
	}	

	for(int i=1;i<=T;i++)
	{
		cout<<seq[query[i]]<<endl;
	}
	
	return	0;
}
