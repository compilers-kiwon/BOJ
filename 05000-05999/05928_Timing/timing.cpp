#include	<iostream>

using namespace	std;

#define	HOURS_FOR_DAY		24
#define	MINUTES_FOR_HOUR	60

int	main(void)
{
	const int	s_day = 11;
	const int	s_hour = 11;
	const int	s_min = 11;
	
	int	D,H,M,start_min,end_min;
	
	cin>>D>>H>>M;
	
	start_min = s_day*HOURS_FOR_DAY*MINUTES_FOR_HOUR+s_hour*MINUTES_FOR_HOUR+s_min;
	end_min = D*HOURS_FOR_DAY*MINUTES_FOR_HOUR+H*MINUTES_FOR_HOUR+M;
	
	if( end_min < start_min )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<end_min-start_min<<'\n';
	}
	
	return	0;
}
