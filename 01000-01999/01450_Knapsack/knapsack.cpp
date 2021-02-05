#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(30+1)

int	N,C,weight[MAX_SIZE];

void	get_weight(int n,int size,int sum,vector<int>& result)
{
	if( sum > C )
	{
		return;
	}
	
	if( n > size )
	{
		result.push_back(sum);
		return;
	}
	
	get_weight(n+1,size,sum,result);
	get_weight(n+1,size,sum+weight[n],result);
}

void	input(void)
{
	cin>>N>>C;
	
	for(int i=1;i<=N;i++)
	{
		cin>>weight[i];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();

	int			cnt;
	vector<int>	w1,w2;
	
	get_weight(1,N/2,0,w1);
	get_weight(N/2+1,N,0,w2);
	
	sort(w2.begin(),w2.end());
	
	cnt = 0;

	for(int i=0;i<w1.size();i++)
	{
		int	available,tmp;
		
		available = C-w1[i];
		cnt += upper_bound(w2.begin(),w2.end(),available)-w2.begin();
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
