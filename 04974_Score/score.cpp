#include	<iostream>

using namespace	std;

#define	MAX_SCORE	1000
#define	MIN_SCORE	0

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		int	max_score,min_score,total_score;
		
		max_score = MIN_SCORE;
		min_score = MAX_SCORE;
		total_score = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	s;
			
			cin>>s;
			
			total_score +=s;
			max_score = max(max_score,s);
			min_score = min(min_score,s);
		}
		
		cout<<(total_score-max_score-min_score)/(N-2)<<'\n';
	}
	
	return	0;
}
