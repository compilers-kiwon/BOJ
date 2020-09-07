#include	<iostream>
#include	<queue>

using namespace	std;

#define	NUM_OF_PROBLEMS			8
#define	NUM_OF_COUNTED_PROBLEMS	5

typedef	pair<int,int>	Score;

int	main(void)
{
	priority_queue<Score>	score;
	
	for(int i=1;i<=NUM_OF_PROBLEMS;i++)
	{
		int	s;
		
		cin>>s;
		score.push(make_pair(s,i));
	}
	
	int	sum = 0;
	priority_queue<int> problem;
	
	for(int i=1;i<=NUM_OF_COUNTED_PROBLEMS;i++)
	{
		int	s,o;
		
		s = score.top().first;
		o = score.top().second;
		score.pop();
		
		sum += s;
		problem.push(-o);
	}
	
	cout<<sum<<endl;
	
	for(int i=1;i<=NUM_OF_COUNTED_PROBLEMS;i++)
	{
		cout<<-(problem.top())<<' ';
		problem.pop();
	}
	cout<<endl;
	
	return	0;
}
