#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Homework;	// first:deadline, second:cup

int	main(void)
{
	int	N;
	priority_queue<Homework>	hq;
	priority_queue<int>			selected_hw;
	
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	deadline,cup;
		
		cin>>deadline>>cup;
		hq.push(make_pair(-deadline,cup));
	}
	
	for(;!hq.empty();)
	{
		int	deadline,cup;
		
		deadline = -hq.top().first;
		cup = hq.top().second;
		
		hq.pop();
		
		selected_hw.push(-cup);
		
		while( deadline < selected_hw.size() )
		{
			selected_hw.pop();
		}
	}
	
	int	num_of_cup_to_get;
	
	for(num_of_cup_to_get = 0;!selected_hw.empty();selected_hw.pop())
	{
		num_of_cup_to_get += -selected_hw.top();
	}
	
	cout<<num_of_cup_to_get<<'\n';
	
	return	0;
}
