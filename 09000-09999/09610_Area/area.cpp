#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	int	n;
	map<string,int>	space;
	
	space["Q1"] = space["Q2"] = space ["Q3"] = space["Q4"] = space["AXIS"] = 0;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		 
		if( x == 0 || y == 0 )
		{
			space["AXIS"]++;
		}
		else if( x > 0 && y > 0 )
		{
			space["Q1"]++;
		}
		else if( x < 0 && y > 0 )
		{
			space["Q2"]++;
		}
		else if( x < 0 && y < 0 )
		{
			space["Q3"]++;
		}
		else
		{
			space["Q4"]++;
		}
	}
	
	map<string,int>::iterator	mi;
	
	for(mi=++(space.begin());mi!=space.end();mi++)
	{
		cout<<mi->first<<": "<<mi->second<<endl;
	}
	cout<<space.begin()->first<<": "<<space.begin()->second<<endl;
	return	0;
}
