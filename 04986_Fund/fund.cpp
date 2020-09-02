#include	<iostream>
#include	<cmath>

using namespace	std;

#define	SIMPLE		0
#define	COMPOUND	1

int	compound(int money,int year,double rate,int charge)
{
	double	ret;
	
	ret = (double)money;
	
	for(int y=1;y<=year;y++)
	{
		ret += floor(ret*rate)-(double)charge;
	}
	
	return	(int)(floor(ret));
}

int	simple(int money,int year,double rate,int charge)
{
	double	origin,interest;
	
	origin = (double)money;
	interest = 0.0;
	
	for(int y=1;y<=year;y++)
	{
		interest += floor(origin*rate);
		origin -= (double)charge;
	}
	
	return	(int)(floor(origin+interest));
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	m;
	
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	initial,year,n,max_result;
		
		cin>>initial>>year>>n;
		max_result = 0;
		
		for(int j=1;j<=n;j++)
		{
			int		operation,charge,result;
			double	interest_rate;
			
			cin>>operation>>interest_rate>>charge;
			
			if( operation == SIMPLE	)
			{
				result = simple(initial,year,interest_rate,charge);
			}
			else
			{
				result = compound(initial,year,interest_rate,charge);
			}
			
			max_result = max(max_result,result);
		}
		
		cout<<max_result<<'\n';
	}
	
	return	0;
}
