#include	<iostream>
#include	<cmath>

using namespace	std;

int	get_distance(int x1,int y1,int x2,int y2)
{
	int	distance,d1,d2;
	
	d1 = abs(x1-x2);
	d2 = abs(y1-y2);
	
	if( (x1<x2 && y1<y2) || (x1>x2 && y1>y2) )
	{
		distance = max(d1,d2);
	}
	else
	{
		distance = d1+d2;
	}
	
	return	distance;
}

int	main(void)
{
	int	W,H,N;
	int	prev_x,prev_y,d,i;
	
	cin>>W>>H>>N>>prev_x>>prev_y;
	
	for(d=0,i=2;i<=N;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		d += get_distance(prev_x,prev_y,x,y);
		prev_x = x;
		prev_y = y;
	}
	
	cout<<d<<endl;
	
	return	0;
}
