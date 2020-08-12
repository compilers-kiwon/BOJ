#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PROBLEM	(32000+1)

priority_queue<int>	problem_pq;
vector<int>			num_of_predecessor(MAX_NUM_OF_PROBLEM,0);
vector<int>			successor[MAX_NUM_OF_PROBLEM];

void	get_order_of_problems(int num_of_problem)
{
	for(int i=1;i<=num_of_problem;i++)
	{
		if( num_of_predecessor[i] == 0 )
		{
			problem_pq.push(-i);
		}
	}
	
	while( problem_pq.size() != 0 )
	{
		int	current_problem;
		
		current_problem = -problem_pq.top();
		problem_pq.pop();
		
		cout<<current_problem<<' ';
		
		for(int i=0;i<successor[current_problem].size();i++)
		{
			int	next_problem;
			
			next_problem = successor[current_problem][i];
			num_of_predecessor[next_problem]--;
			
			if( num_of_predecessor[next_problem] == 0 )
			{
				problem_pq.push(-next_problem);
			}
				
		}	
	}	
}

int		main(void)
{
	int	N,M;
	
	cin>>N>>M;

	for(int i=1;i<=M;i++)
	{
		int	A,B;
		
		cin>>A>>B;
		num_of_predecessor[B]++;
		successor[A].push_back(B);
	}
	
	get_order_of_problems(N);
	
	return	0;	
}
