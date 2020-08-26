#include	<iostream>

using namespace	std;

#define	MAX_LEN	10

#define	MONDAY		0
#define	TUESDAY		1
#define	WEDNESDAY	2
#define	THURSDAY	3
#define	FRIDAY		4
#define	SATURDAY	5
#define	SUNDAY		6
#define	MAX_DAY		7

#define	NEXT_DAY(d)	(((d)+1)%MAX_DAY)

const int	num_of_days_in_month[12+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const char	day_char[MAX_DAY][MAX_LEN] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int	main(void)
{
	int		today,month,day;
	int		M,D;
	bool	found;
	
	cin>>D>>M;
	
	today = THURSDAY;
	found = false;
	
	for(month=1;month<=12;month++)
	{
		for(day=1;day<=num_of_days_in_month[month];day++)
		{
			if( month == M && day == D )
			{
				puts(day_char[today]);
				found = true;
				break;
			}
			today = NEXT_DAY(today);
		}
		
		if( found == true )
		{
			break;
		}
	}
	
	return	0;
}
