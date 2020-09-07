#include	<iostream>
#include	<map>

using namespace	std;

map<int,int> X,Y;

int	main(void)
{
	for(int i=1;i<=3;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		X[x]++;
		Y[y]++;
	}
	
	map<int,int>::iterator	i;
	
	for(i=X.begin();i!=X.end();i++)
	{
		if( i->second == 1 )
		{
			cout<<i->first<<' ';
			break;
		}
	}
	
	for(i=Y.begin();i!=Y.end();i++)
	{
		if( i->second == 1 )
		{
			cout<<i->first<<'\n';
			break;
		}
	}
	
	return	0;
}
