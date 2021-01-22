#include	<iostream>

using namespace	std;

int	count_369(int n)
{
	int	ret;
	
	for(ret=0;n>0;n/=10)
	{
		int	d;
		
		d = n%10;
		
		if( d==3 || d==6 || d==9 )
		{
			ret++;
		}
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
		cnt += count_369(i);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
