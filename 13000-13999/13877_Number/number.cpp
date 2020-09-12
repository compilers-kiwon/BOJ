#include	<iostream>

using namespace	std;

int	convert(int n,int d)
{
	int		base,result;
	
	for(result=0,base=1;n>0;n/=10,base*=d)
	{
		int	m;
		
		m = n%10;
		
		if( m >= d )
		{
			result = 0;
			break;
		}
		
		result += m*base;
	}

	return	result;
}

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int	K,N;
		
		cin>>K>>N;
		cout<<K<<' '<<convert(N,8)<<' '<<N<<' '<<convert(N,16)<<'\n';
	}
	
	return	0;
}
