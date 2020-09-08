#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_BELT	(1000+1)

typedef	unsigned long long	uint64;

uint64	get_gcd(uint64 a,uint64 b)
{
	uint64	big,small,mod;
	
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

int	main(void)
{
	int		M,dir,i;
	uint64	left,right;
	
	cin>>M;
	
	for(left=right=1,dir=i=0;i<M;i++)
	{
		uint64	a,b,gcd;
		int		s;
		
		cin>>a>>b>>s; 
		
		left *= a;
		right *= b;
		
		gcd = get_gcd(left,right);
		
		left /= gcd;
		right /= gcd;
		dir = (dir+s)%2;
	}
	cout<<dir<<' '<<right<<'\n';
	
	return	0;
}
