#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_JOB		(1000+1)
#define	MAX_NUM_OF_EMPLOYEE	(1000+1)
#define	EMPLOYEE_BANDWIDTH	2

#define	NONE	0

int	employee_to_be_assigned_to_job[MAX_NUM_OF_JOB];
int	visited[MAX_NUM_OF_EMPLOYEE];

vector<int>	doable[MAX_NUM_OF_EMPLOYEE];

bool	dfs(int current_employee,int level)
{
	if( visited[current_employee] == level )
	{
		return	false;
	}
	
	visited[current_employee] = level;
	
	vector<int>&	candidate_job = doable[current_employee];
	
	for(int i=0;i<candidate_job.size();i++)
	{
		int&	job = candidate_job[i];
		
		if( employee_to_be_assigned_to_job[job]==NONE || dfs(employee_to_be_assigned_to_job[job],level) )
		{
			employee_to_be_assigned_to_job[job] = current_employee;
			
			return	true;
		}
	}
	
	return	false;
}

int		main(void)
{
	int	N,M,K,cnt,level;
	
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>K;
	
	for(int i=1;i<=N;i++)
	{
		int	num_of_job;
		
		cin>>num_of_job;
		
		for(int j=1;j<=num_of_job;j++)
		{
			int	job;
			
			cin>>job;
			doable[i].push_back(job);
		}
	}
	
	cnt = 0;
	level = 1;
	
	for(int b=1;b<=EMPLOYEE_BANDWIDTH;b++)
	{
		for(int employee=1;employee<=N;employee++)
		{
			if( dfs(employee,level++) == true )
			{
				cnt++;
				
				if( b == EMPLOYEE_BANDWIDTH )
				{
					K--;
					
					if( K == 0 )
					{
						break;
					}
				}
			}
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;	
}	
