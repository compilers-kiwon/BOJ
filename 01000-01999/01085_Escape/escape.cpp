#include	<iostream>

using namespace std;

int	main(void)
{	
	int	x,y,w,h;
	int	up,down,left,right;
	
	cin>>x>>y>>w>>h;
	
	up = h-y;
	down = y;
	left = x;
	right = w-x;
	
	int	min_distance;
	
	min_distance = min(min(up,down),min(left,right));
	cout<<min_distance<<endl;
	
	return	0;
}
