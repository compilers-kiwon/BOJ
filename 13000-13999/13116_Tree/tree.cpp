#include	<iostream>

using namespace	std;

#define	MAX_SIZE		(1023+1)
#define	get_parent(n)	((n)/2)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T,degree[MAX_SIZE];

	cin>>T;
	degree[1] = 0;
	
	for(int i=1;i<MAX_SIZE/2;i++)
	{
		int	left_child,right_child;
		
		left_child = i*2;
		right_child = left_child+1;
		
		degree[left_child] = degree[right_child] = degree[i]+1;
	}
	
	for(int t=1;t<=T;t++)
	{
		int	A,B,d1,d2;
		
		cin>>A>>B;
		
		d1 = degree[A];
		d2 = degree[B];
		
		// 1. place at the same degree
		if( d1 < d2 )
		{
			for(;d1!=degree[B];B=get_parent(B));
		}
		
		if( d1 > d2 )
		{
			for(;d2!=degree[A];A=get_parent(A));
		}
		
		// 2. move up until to meet
		for(;A!=B;A=get_parent(A),B=get_parent(B));
		
		// 3. 10 times
		cout<<10*A<<'\n';
	}
	
	return	0;
}
