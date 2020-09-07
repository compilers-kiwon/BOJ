#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	int	score[N+1];
	
	for(int i=1;i<=N;i++)
	{
		cin>>score[i];
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int i=N-1;i>=1;i--)
	{
		if( score[i] >= score[i+1] )
		{
			int	new_score;
			
			new_score = score[i+1]-1;
			cnt += new_score-score[i];
			score[i] = new_score;
		}
	}
	cout<<-cnt<<endl;
	
	return	0;
}
