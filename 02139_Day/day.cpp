#include	<iostream>

using namespace	std;

int	num_of_days_for_month_in_leap_year[12+1] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int	num_of_days_for_month_in_normal_year[12+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool	is_leap_year(int year)
{
	if( year%400 == 0 )
	{
		return	true;
	}
	
	if( year%100 == 0)
	{
		return	false;
	}
	
	if( year%4 == 0 )
	{
		return	true;
	}
	
	return	false;
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		d,m,y,cnt;
		int*	table;
		
		cin>>d>>m>>y;
		cnt = 0;
		
		if( d==0 && m==0 && y==0 )
		{
			break;
		}
		
		if( is_leap_year(y) == true )
		{
			table = num_of_days_for_month_in_leap_year;
		}
		else
		{
			table = num_of_days_for_month_in_normal_year;
		}
		
		for(int month=1;month<m;month++)
		{
			cnt += table[month];
		}
		cnt += d;
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}
