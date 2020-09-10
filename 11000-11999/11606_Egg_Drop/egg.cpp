#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		n,k,broken_floor,safe_floor;
	
	cin>>n>>k;
	
	broken_floor = k;
	safe_floor = 1;
	
	for(int i=1;i<=n;i++)
	{
		int		f;
		string	result;
		
		cin>>f>>result;
		
		if( result == "BROKEN" )
		{
			broken_floor = min(broken_floor,f);
		}
		else
		{
			safe_floor = max(safe_floor,f);
		}
	}
	
	cout<<min(k,safe_floor+1)<<' '<<max(1,broken_floor-1)<<'\n';
	
	return	0;
}
