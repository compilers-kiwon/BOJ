#include	<iostream>
#include	<string>

using namespace	std;

#define	HOURS_PER_DAY		24
#define	MINUTES_PER_HOUR	60
#define	SECONDS_PER_MINUTE	60
#define	SECONDS_PER_DAY		(HOURS_PER_DAY*MINUTES_PER_HOUR*SECONDS_PER_MINUTE)

#define	SEPARATOR1_POS		2
#define	SEPARATOR2_POS		5

int	main(void)
{
	string	str1,str2;
	int		h1,m1,s1,t1;
	int		h2,m2,s2,t2;
	int		waiting_time,waiting_hours,waiting_minutes,waiting_seconds;
	
	cin>>str1>>str2;
	
	str1[SEPARATOR1_POS] = str1[SEPARATOR2_POS] = ' ';
	str2[SEPARATOR1_POS] = str2[SEPARATOR2_POS] = ' ';
	
	sscanf(str1.c_str(),"%d %d %d",&h1,&m1,&s1);
	sscanf(str2.c_str(),"%d %d %d",&h2,&m2,&s2);
	
	t1 = (h1*MINUTES_PER_HOUR+m1)*SECONDS_PER_MINUTE+s1;
	t2 = (h2*MINUTES_PER_HOUR+m2)*SECONDS_PER_MINUTE+s2;
	
	if( t2 > t1 )
	{
		waiting_time = t2-t1;
	}
	else
	{
		waiting_time = t2+SECONDS_PER_DAY-t1;
	}
	
	printf("%02d:",waiting_time/(MINUTES_PER_HOUR*SECONDS_PER_MINUTE));
	waiting_time %= MINUTES_PER_HOUR*SECONDS_PER_MINUTE;
	
	printf("%02d:",waiting_time/SECONDS_PER_MINUTE);
	waiting_time %= SECONDS_PER_MINUTE;
	
	printf("%02d\n",waiting_time);
	
	return	0;
}
