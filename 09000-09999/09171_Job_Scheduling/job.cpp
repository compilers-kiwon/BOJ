#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_JOBS	(500+1)
#define	MAX_TIME		(2000+1)

typedef	pair<int,double>	Job;

int		n,t;
double	income[MAX_NUM_OF_JOBS][MAX_TIME];
Job		job[MAX_NUM_OF_JOBS];

void	init(void)
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %lf",&job[i].first,&job[i].second);
	}
	
	scanf("%d",&t);
	
	for(int job_no=1;job_no<=n;job_no++)
	{
		for(int time=1;time<=t;time++)
		{
			income[job_no][time] = 0.0;
		}
	}
}

void	do_scheduling(void)
{
	income[1][job[1].first] = job[1].second;
	
	for(int job_no=2;job_no<=n;job_no++)
	{
		int&	current_job_time = job[job_no].first;
		double&	current_job_income = job[job_no].second;
		
		for(int prev_job=job_no-1,time=1;time<=t;time++)
		{
			double&	prev_income = income[prev_job][time];
			double&	current_income = income[job_no][time];
			
			if( prev_income != 0.0 )
			{
				current_income = max(current_income,prev_income);
				
				int	adj_time;
				
				adj_time = time+current_job_time;
				
				if( adj_time <= t )
				{
					double&	adj_income = income[job_no][adj_time];
					
					adj_income = max(adj_income,prev_income+current_job_income);
				}
			} 
		}
		
		if( current_job_time <= t )
		{
			income[job_no][current_job_time] = max(income[job_no][current_job_time],current_job_income);
		}
	}
}

double	get_max_income(int& scheduled_time)
{
	double	ret;
	int		time;
	
	for(ret=0.0,time=1;time<=t;time++)
	{
		if( income[n][time] > ret )
		{
			ret = income[n][time];
			scheduled_time = time;
		}
	}
	
	return	ret;
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int t=1;t<=T;t++)
	{
		double	max_income;
		int		max_scheduled_time;
		
		init();
		do_scheduling();
		
		max_scheduled_time = 0;
		max_income = get_max_income(max_scheduled_time);
		
		printf("Problem %d: %d seconds scheduled for $%.02f\n",t,max_scheduled_time,max_income);
	}
	
	return	0;
}
