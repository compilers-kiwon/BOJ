#include	<iostream>

using namespace	std;

int	reverse_number(int n)
{
	int	ret;
	
	for(ret=0;n>0;n/=10)
	{
		ret = ret*10+n%10;
	}
	
	return	ret;
}

int	main(void)
{
	int	N;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	a,b;
		
		cin>>a>>b;
		cout<<reverse_number(reverse_number(a)+reverse_number(b))<<'\n';
	}
	
	return	0;
}
