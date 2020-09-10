#include	<iostream>

using namespace	std;

typedef	long long int		int64;
typedef	pair<int64,int64>	Container;

int64		get_gcd(int64 a,int64 b)
{
	int64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	
	if( small == 0 )
	{
		return	big;
	}
	
	for(mod=big%small;mod!=0;mod=big%small)
	{
		big = small;
		small = mod;
	}
	
	return	small;
}

Container	simulate(int64 X,int N,int64 Y,int M)
{
	int64	big,small;
	
	big = X;
	small = 0;
	
	for(int i=1;i<=N;i++)
	{
		small += big;
		swap(small,big);
	}
	
	big += Y;
	
	return	make_pair(big,small);
}

int			main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int			N,M;
		int64		X,Y;
		Container	c;
		
		cin>>X>>N>>Y>>M;
		
		c = simulate(X,N,Y,M);
		cout<<"Case "<<i<<": "<<get_gcd(c.first,c.second)<<'\n';
	}
	
	return	0;
}
