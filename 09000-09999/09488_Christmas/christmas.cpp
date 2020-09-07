#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(1000000+1)

typedef	unsigned long long	uint64;

uint64	sum[MAX_SIZE];

#define	get_num_of_today_gifts(n)	((n)*((n)+1)/2)	

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(uint64 d=1;d<=MAX_SIZE;d++)
	{
		sum[d] = sum[d-1]+get_num_of_today_gifts(d);
	}
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		cout<<sum[n]<<'\n';
	}
	
	return	0;
}
