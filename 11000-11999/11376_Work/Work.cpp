#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_EMPLOYEE	(1000+1)
#define	MAX_NUM_OF_TASK		(1000+1)
#define	NOT_ASSIGNED		0

int	N,M;
int	TASK_ASSIGNED_TO_EMPLOYEE[MAX_NUM_OF_EMPLOYEE][2];
int	EMPLOYEE_ASSIGNED_TO_TASK[MAX_NUM_OF_TASK];
int	visited[MAX_NUM_OF_EMPLOYEE];

vector<int>	doable[MAX_NUM_OF_EMPLOYEE];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		int	num_of_task;
		
		cin>>num_of_task;
		
		for(int j=1;j<=num_of_task;j++)
		{
			int	t;
			
			cin>>t;
			doable[i].push_back(t);
		}
	}
}

bool	dfs(int employee,int depth)
{
	visited[employee] = depth;
	
	for(int i=0;i<doable[employee].size();i++)
	{
		int&	candidate_task = doable[employee][i];
		
		for(int j=0;j<2;j++)
		{
			if( EMPLOYEE_ASSIGNED_TO_TASK[candidate_task] == NOT_ASSIGNED ||
				(visited[EMPLOYEE_ASSIGNED_TO_TASK[candidate_task]]!=depth 
					&& dfs(EMPLOYEE_ASSIGNED_TO_TASK[candidate_task],depth)) )
			{
				EMPLOYEE_ASSIGNED_TO_TASK[candidate_task] = employee;
				TASK_ASSIGNED_TO_EMPLOYEE[employee][j] = candidate_task;
				
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	init();
	
	int	cnt,i,depth;
	
	for(i=depth=1;i<=N;i++)
	{
		if( TASK_ASSIGNED_TO_EMPLOYEE[i][0] == NOT_ASSIGNED )
		{
			dfs(i,depth++);
		}
		
		if( TASK_ASSIGNED_TO_EMPLOYEE[i][1] == NOT_ASSIGNED )
		{
			dfs(i,depth++);
		}
	}
	
	for(i=1,cnt=0;i<=M;i++)
	{
		if( EMPLOYEE_ASSIGNED_TO_TASK[i] != NOT_ASSIGNED )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	
	return	0;
}
