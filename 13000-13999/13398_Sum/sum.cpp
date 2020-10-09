#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)
#define	MIN_NUM		(-1000*MAX_SIZE)

int	N,num[MAX_SIZE];
int	forward_max_sum[MAX_SIZE],backward_max_sum[MAX_SIZE+1];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
}

void	get_max_sums(void)
{
	forward_max_sum[1] = num[1];
	
	for(int i=2;i<=N;i++)
	{
		forward_max_sum[i] = max(num[i],forward_max_sum[i-1]+num[i]);
	}
	
	backward_max_sum[N] = num[N];
	
	for(int i=N-1;i>=1;i--)
	{
		backward_max_sum[i] = max(num[i],backward_max_sum[i+1]+num[i]);
	}
}

int		get_max_sum(void)
{
	int	ret;
	
	ret = MIN_NUM;
	
	for(int i=1;i<=N;i++)
	{
		ret = max(ret,max(forward_max_sum[i],forward_max_sum[i-1]+backward_max_sum[i+1]));
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	if( N == 1 )
	{
		cout<<num[1]<<'\n';
		return	0;
	}
	
	get_max_sums();
	cout<<get_max_sum()<<'\n';
	
	return	0;
}
