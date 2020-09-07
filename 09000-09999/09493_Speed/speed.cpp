#include	<iostream>

using namespace	std;

#define	SEC_FOR_MIN		60
#define	MIN_FOR_HOUR	60
#define	SEC_FOR_HOUR	(SEC_FOR_MIN*MIN_FOR_HOUR)

int	main(void)
{
	for(;;)
	{
		double	M,A,B;
		
		cin>>M>>A>>B;
		
		if( M==0.0 && A==0.0 && B==0.0 )
		{
			break;
		}
		
		double	A_per_sec,B_per_sec;
		double	A_time,B_time;
		int		time_gap,h,m,s;
		
		A_per_sec = A/(double)SEC_FOR_HOUR;
		B_per_sec = B/(double)SEC_FOR_HOUR;
		
		A_time = M/A_per_sec;
		B_time = M/B_per_sec;
		
		time_gap = (int)(A_time-B_time+0.5);
		h = time_gap/SEC_FOR_HOUR;
		m = (time_gap%SEC_FOR_HOUR)/SEC_FOR_MIN;
		s = time_gap%SEC_FOR_MIN;
		
		printf("%d:%02d:%02d\n",h,m,s);
	}
	
	return	0;
}
