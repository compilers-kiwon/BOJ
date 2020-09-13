#include	<iostream>
#include	<map>
#include	<cmath>

using namespace	std;

typedef	pair<int,int>	Sign;

int	main(void)
{
	map<Sign,int>	quadrant;
	
	quadrant[make_pair(1,1)] = 1;
	quadrant[make_pair(-1,1)] = 2;
	quadrant[make_pair(-1,-1)] = 3;
	quadrant[make_pair(1,-1)] = 4;
	
	int		x,y;
	Sign	s;
	
	cin>>x>>y;
	s.first = x/abs(x);
	s.second = y/abs(y);
	
	cout<<quadrant[s]<<'\n';
	
	return	0;
}
