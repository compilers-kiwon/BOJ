#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N,K;
	
	cin>>N>>K;
	
	for(int i=1;i<=K;i++)
	{
		int		S,T,R;
		int		page_for_each_reading;
		int		reading_time,num_of_page_to_be_read;
		double	minute_for_page;
		
		cin>>S>>T>>R;
		
		reading_time = 0;
		num_of_page_to_be_read = N;
		page_for_each_reading = S*T;
		minute_for_page = 1/((double)S);
		
		for(;page_for_each_reading<num_of_page_to_be_read;)
		{
			reading_time += T+R;
			num_of_page_to_be_read -= page_for_each_reading;
		}
		
		if( page_for_each_reading == num_of_page_to_be_read )
		{
			reading_time += T;
		}
		else
		{
			reading_time += ceil(((double)num_of_page_to_be_read)*minute_for_page);
		}
		
		cout<<reading_time<<'\n';
	}
	
	return	0;
}
