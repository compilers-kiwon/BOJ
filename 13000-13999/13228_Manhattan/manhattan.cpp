#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int	x1,y1,f1,x2,y2,f2;
		
		cin>>x1>>y1>>f1>>x2>>y2>>f2;
		cout<<abs(x1-x2)+abs(y1-y2)+f1+f2<<'\n';
	}
	
	return	0;
}
