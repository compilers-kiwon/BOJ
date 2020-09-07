#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	NUM_OF_DAYS_OF_WEEK	7

map<int,int>	days_of_month;
map<int,string>	days_of_week;

int	main(void)
{
	days_of_month[1] = 31;
	days_of_month[2] = 28;
	days_of_month[3] = 31;
	days_of_month[4] = 30;
	days_of_month[5] = 31;
	days_of_month[6] = 30;
	days_of_month[7] = 31;
	days_of_month[8] = 31;
	days_of_month[9] = 30;
	days_of_month[10] = 31;
	days_of_month[11] = 30;
	days_of_month[12] = 31;
	
	days_of_week[0] = "SUN";
	days_of_week[1] = "MON";
	days_of_week[2] = "TUE";
	days_of_week[3] = "WED";
	days_of_week[4] = "THU";
	days_of_week[5] = "FRI";
	days_of_week[6] = "SAT";
	
	int	x,y,month,total_num_of_days;
	
	cin>>x>>y;
	
	total_num_of_days = y;
	
	for(month=1;month<x;month++)
	{
		total_num_of_days = total_num_of_days+days_of_month[month];
	}
	cout<<days_of_week[total_num_of_days%NUM_OF_DAYS_OF_WEEK]<<endl;
	
	return	0;	
}
