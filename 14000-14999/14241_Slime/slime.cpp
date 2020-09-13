#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	priority_queue<int>	slime;
	int					N,score;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	s;
		
		cin>>s;
		slime.push(s);
	}
	
	score = 0;
	
	while( slime.size() != 1 )
	{
		int	s1,s2;
		
		s1=slime.top();slime.pop();
		s2=slime.top();slime.pop();
		
		score += s1*s2;
		slime.push(s1+s2);
	}
	
	cout<<score<<'\n';
	
	return	0;
}
