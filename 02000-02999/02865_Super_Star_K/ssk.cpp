#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_PEOPLE	(100+1)

priority_queue<double>	personal_score[MAX_NUM_OF_PEOPLE];
priority_queue<double>	high_score;

int	main(void)
{
	int	N,M,K;
	
	cin>>N>>M>>K;
	
	for(int j=1;j<=M;j++)
	{
		for(int i=1;i<=N;i++)
		{
			int		p;
			double	s;
			
			cin>>p>>s;
			personal_score[p].push(s);
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		high_score.push(personal_score[i].top());
	}
	
	double	sum;
	
	sum = 0.0;
	
	for(int i=1;i<=K;i++)
	{
		sum += high_score.top();
		high_score.pop();
	}
	
	printf("%.1f\n",sum);
	
	return	0;
}
