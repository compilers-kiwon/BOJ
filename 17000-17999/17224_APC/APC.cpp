#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Problem;	// first:-sub2, second:-sub1

#define	SUB1_SCORE	100
#define	SUB2_SCORE	40

void	input(int& num_of_problems,int& capability,
			  int& max_num_of_solved_problems,queue<Problem>& problem_q)
{
	cin>>num_of_problems>>capability>>max_num_of_solved_problems;
	
	for(int i=1;i<=num_of_problems;i++)
	{
		int	sub1,sub2;
		
		cin>>sub1>>sub2;
		problem_q.push(make_pair(sub1,sub2));
	}
}

int		solve(int capability,int max_num_of_solved_problems,
			  queue<Problem>& problem_q)
{
	int	num_of_solved_problems,score;
	
	num_of_solved_problems = score = 0;
	
	for(int i=1,n=problem_q.size();i<=n&&num_of_solved_problems!=max_num_of_solved_problems;i++)
	{
		int	current_sub1,current_sub2;
		
		current_sub1 = problem_q.front().first;
		current_sub2 = problem_q.front().second;
		
		problem_q.pop();
		
		if( current_sub2 <= capability )
		{
			score += SUB1_SCORE+SUB2_SCORE;
			num_of_solved_problems++;
		}
		else
		{
			problem_q.push(make_pair(current_sub1,current_sub2));
		}
	}
	
	for(int i=1,n=problem_q.size();i<=n&&num_of_solved_problems!=max_num_of_solved_problems;i++)
	{
		int	current_sub1,current_sub2;
		
		current_sub1 = problem_q.front().first;
		current_sub2 = problem_q.front().second;
		
		problem_q.pop();
		
		if( current_sub1 <= capability )
		{
			score += SUB1_SCORE;
			num_of_solved_problems++;
		}
		else
		{
			problem_q.push(make_pair(current_sub1,current_sub2));
		}
	}
	
	return	score;
}

int		main(void)
{
	int				N,L,K;
	queue<Problem>	pq;
	
	input(N,L,K,pq);
	cout<<solve(L,K,pq)<<'\n';
	
	return	0;
}
