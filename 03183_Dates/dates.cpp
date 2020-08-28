#include	<iostream>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

#define	VALID	1
#define	INVALID	0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	is_leap_year(int y)
{
	int	ret;
	
	if( y%400==0 || !(y%100==0 || y%4!=0) )
	{
		ret = TRUE;
	}
	else
	{
		ret = FALSE;
	}
	
	return	ret;
}

int	main(void)
{
	const int 	days[12+1] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	const char	answer[2][10] = {"Invalid","Valid"};
	
	for(;;)
	{
		int	d,m,y,result;
		
		cin>>d>>m>>y;
		
		if( d==0 && m==0 && y==0 )
		{
			break;
		}
		
		int	max_day;
		
		if( IN_RANGE(1,m,12) )
		{
			max_day = days[m]+(m==2?is_leap_year(y):0);
			
			if( IN_RANGE(1,d,max_day) )
			{
				result = VALID;
			}
			else
			{
				result = INVALID;
			}
		}
		else
		{
			result = INVALID;
		}
		
		cout<<answer[result]<<'\n';
	}
	
	return	0;
}
