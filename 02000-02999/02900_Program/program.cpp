#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

typedef	unsigned long long	uint64;
typedef	pair<int,int>		Query;

int				N,K,Q;
uint64			a[MAX_SIZE],sum[MAX_SIZE];
Query			q[MAX_SIZE];
map<int,uint64>	X;

void	input(void)
{
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	x;
		
		cin>>x;
		X[x]++;
	}
	
	cin>>Q;
	
	for(int i=1;i<=Q;i++)
	{
		cin>>q[i].first>>q[i].second;
	}
}

void	simulate(void)
{
	map<int,uint64>::iterator	it;
	
	for(it=X.begin();it!=X.end();it++)
	{
		const int&		jump = it->first;
		const uint64&	cnt = it->second;
		
		for(int i=0;i<N;i+=jump)
		{
			a[i] += cnt;
		}
	}
}

void	build_sum_table(void)
{
	sum[0] = a[0];
	
	for(int i=1;i<N;i++)
	{
		sum[i] = sum[i-1]+a[i];
	}
}

void	do_query(void)
{
	for(int i=1;i<=Q;i++)
	{
		int&	L = q[i].first;
		int&	R = q[i].second;
		
		if( L == 0 )
		{
			cout<<sum[R]<<'\n';
		}
		else
		{
			cout<<sum[R]-sum[L-1]<<'\n';
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	simulate();
	build_sum_table();
	do_query();
	
	return	0;
}
