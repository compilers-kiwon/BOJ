#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	N,px,py,cx,cy,min_distance;
	
	cin>>px>>py>>N;
	min_distance = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		int	x,y,m;
		
		cin>>x>>y;
		m = abs(px-x)+abs(py-y);
		
		if( m < min_distance )
		{
			min_distance = m;
			cx = x;
			cy = y;
		}
	}
	
	cout<<cx<<' '<<cy<<'\n';
	
	return	0;
}
