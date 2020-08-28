#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_RINGS	(100+1)

int	get_gcd(int n1,int n2)
{
	int	s,b,gcd;
	
	s = min(n1,n2);
	b = max(n1,n2);
	
	if( b%s == 0 )
	{
		return	s;
	}
	
	gcd = 1;
	
	for(int i=s/2;i>=2;i--)
	{
		if( n1%i==0 && n2%i==0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

int	main(void)
{
	int	N;
	int	r[MAX_NUM_OF_RINGS];
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>r[i];
	}
	
	int	left_ring,right_ring,i;
	
	for(left_ring=r[1],i=2;i<=N;i++)
	{
		int	gcd;
		
		right_ring = r[i];
		gcd = get_gcd(left_ring,right_ring);
		cout<<left_ring/gcd<<'/'<<right_ring/gcd<<endl;
	}
	return	0;
}
