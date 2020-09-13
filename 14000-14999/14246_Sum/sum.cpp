#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	long long int	int64;

int64	n,num[MAX_SIZE],k,sum[MAX_SIZE];

void	input(void)
{
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		sum[i] = sum[i-1]+num[i];
	}
	
	cin>>k;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	int64	cnt;
	
	cnt = 0;
	
	for(int s=1,e=1;s<=n&&e<=n;)
	{
		int64	current_sum;
		
		current_sum = sum[e]-sum[s-1];
		
		if( current_sum > k )
		{
			cnt += n-e+1;
			s++;
		}
		else
		{
			e++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
