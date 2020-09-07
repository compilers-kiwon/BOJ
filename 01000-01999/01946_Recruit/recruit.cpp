#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Score;	// first:paper, second:interview

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		priority_queue<Score>	candidate_pq;
		
		int	N;
		
		scanf("%d",&N);
		
		for(int i=1;i<=N;i++)
		{
			int	paper,interview;
			
			scanf("%d %d",&paper,&interview);
			candidate_pq.push(make_pair(-paper,interview));
		}
		
		int	min_interview_score = 0x7FFFFFFF;
		int	cnt = 0;
		
		while( candidate_pq.size() != 0 )
		{
			int	current_candidate_interview_score;
			
			current_candidate_interview_score = candidate_pq.top().second;
			candidate_pq.pop();
			
			if( current_candidate_interview_score < min_interview_score )
			{
				++cnt;
				
				if( current_candidate_interview_score == 1 )
				{
					break;
				}
				else
				{
					min_interview_score = current_candidate_interview_score; 
				}
			}
		}
		printf("%d\n",cnt);
		
		T--;
	}
	return	0;
}
