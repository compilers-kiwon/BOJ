#include	<iostream>

using namespace	std;

#define	PI				3.141592653589
#define	HELIUM_PER_GRAM	1000.0

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int		num_of_balloons;
		double	weight,capability;
		
		cin>>num_of_balloons>>weight;
		
		weight *= HELIUM_PER_GRAM;
		capability = 0.0;
		
		for(int i=1;i<=num_of_balloons;i++)
		{
			double	r;
			
			cin>>r;
			capability += 4.0*PI*r*r*r/3.0;
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( capability > weight )
		{
			cout<<"Yes\n\n";
		}
		else
		{
			cout<<"No\n\n";
		}
	}
	
	return	0;
}
