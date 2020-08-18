#include	<iostream>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	n,s,f;
		int	total_wasted_water;
		
		cin>>n>>s>>f;
		total_wasted_water = 0;
		
		for(int i=1;i<=n;i++)
		{
			int	s_i,f_i,r_i;
			int	s_t,f_t;
						
			cin>>s_i>>f_i>>r_i;
			
			s_t = max(s,s_i);
			f_t = min(f,f_i);
			
			if( s_t <= f_t )
			{
				total_wasted_water += (f_t-s_t+1)*r_i;
			}
		}
		
		cout<<"Data Set "<<k<<":\n"<<total_wasted_water<<"\n\n";
	}
	
	return	0;
}
