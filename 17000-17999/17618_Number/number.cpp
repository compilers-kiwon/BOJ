#include	<iostream>

using namespace	std;

int	get_sum_of_digits(int n)
{
	int	ret;
	
	for(ret=0;n>0;n/=10)
	{
		ret += n%10;
	}
	
	return	ret;
}

int	main(void)
{
	int	N,cnt;
	
	cin>>N;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		if( i%get_sum_of_digits(i) == 0 )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
