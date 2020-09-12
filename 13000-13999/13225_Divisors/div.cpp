#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_num_of_divisors(int n)
{
	int	cnt,i,to;
	
	for(cnt=0,i=1,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			cnt += 2;
		}
	}
	
	if( to*to == n )
	{
		cnt--;
	}
	
	return	cnt;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	C;
	
	cin>>C;
	
	for(int i=1;i<=C;i++)
	{
		int	n;
		
		cin>>n;
		cout<<n<<' '<<get_num_of_divisors(n)<<'\n';
	}
	
	return	0;
}
