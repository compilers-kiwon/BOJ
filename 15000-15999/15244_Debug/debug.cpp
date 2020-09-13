#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_SIZE	1000000

typedef	long long int	int64;

int				N,K,seq[MAX_SIZE];
int64			sum[MAX_SIZE];
map<int,int>	X;

void	init(void)
{
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=K;i++)
	{
		int	x;
		
		scanf("%d",&x);
		X[x]++;
	}
}

void	simulate_something(void)
{
	map<int,int>::iterator	it;
	
	for(it=X.begin();it!=X.end();it++)
	{
		int	jump,num;
		
		jump = it->first;
		num = it->second;
		
		for(int i=0;i<N;i+=jump)
		{
			seq[i] += num;
		}
	}
}

void	get_sum(void)
{
	sum[0] = (int64)seq[0];
	
	for(int i=1;i<N;i++)
	{
		sum[i] = sum[i-1]+(int64)seq[i];
	}
}

int64	verify(int L,int R)
{
	int64	prev_sum;
	
	if( L == 0 )
	{
		prev_sum = 0;
	}
	else
	{
		prev_sum = sum[L-1];
	}
	
	return	sum[R]-prev_sum;
}

int		main(void)
{
	init();
	simulate_something();
	get_sum();
	
	int	Q;
	
	scanf("%d",&Q);
	
	for(int i=1;i<=Q;i++)
	{
		int	L,R;
		
		scanf("%d %d",&L,&R);
		printf("%lld\n",verify(L,R));
	}
	
	return	0;
}
