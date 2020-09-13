#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,min_score,max_score;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	min_score = 1001;
	max_score = -1;
	
	for(int i=1;i<=N;i++)
	{
		int	s;
		
		cin>>s;
		min_score = min(min_score,s);
		max_score = max(max_score,s);
	}
	
	cout<<max_score-min_score<<'\n';
	
	return	0;
}
