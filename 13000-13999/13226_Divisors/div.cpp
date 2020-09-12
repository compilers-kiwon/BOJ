#include	<iostream>
#include	<cmath>

using namespace	std;

int	count_num_of_divisors(int n)
{
	int	cnt,i,to;
	
	for(cnt=2,i=2,to=sqrt(n);i<=to;i++)
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
		int	L,U,max_cnt;
		
		cin>>L>>U;
		max_cnt = 0;
		
		for(int n=L;n<=U;n++)
		{
			max_cnt = max(max_cnt,count_num_of_divisors(n));
		}
		
		cout<<max_cnt<<'\n';
	}
	
	return	0;
}
