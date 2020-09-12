#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_gcd(int a,int b)
{
	int	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

int	get_cnt_of_pair(int a)
{
	int	cnt = 0;
	
	for(int i=1,to=sqrt(a);i<=to;i++)
	{
		if( a%i==0 && get_gcd(i,a/i)==1 )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N;
		
		cin>>N;
		cout<<get_cnt_of_pair(N)<<'\n';
		
		T--;
	}
	
	return	0;
}
