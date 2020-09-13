#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_PROBLEMS	(100+1)
#define	is_right(c)			(((c)=='O')?1:0)

int	main(void)
{
	int	score_of_student,score_of_problem[MAX_NUM_OF_PROBLEMS];
	int	N,M,max_score,max_score_student;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>score_of_problem[i];
	}
	
	max_score = -1;
	
	for(int i=1;i<=M;i++)
	{
		int	s;
		
		cin>>s;
		score_of_student = 0;
		
		for(int j=1;j<=N;j++)
		{
			char	c;
			
			cin>>c;
			score_of_student += score_of_problem[j]*is_right(c);
		}
		
		if( max_score < score_of_student )
		{
			max_score = score_of_student;
			max_score_student = s;
		}
		else if( max_score == score_of_student && s < max_score_student )
		{
			max_score_student = s;
		}
	}
	
	cout<<max_score_student<<" "<<max_score<<endl;
	
	return	0;
}
