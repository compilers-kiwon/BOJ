#include	<iostream>
#include	<queue>

using namespace	std;

int	K,N;

void	init(queue<int>& input,priority_queue<int>& sorted)
{
	cin>>K>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		input.push(n);
		sorted.push(-n);
	}
}

int		get_num_of_operations(queue<int>& input,priority_queue<int>& sorted)
{
	int			ret;

	for(ret=0;!input.empty();input.pop())
	{
		int	expected;
		
		expected = -sorted.top();
		
		if( expected == input.front() )
		{
			sorted.pop();
		}
		else
		{
			ret++;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		queue<int>			input;
		priority_queue<int>	sorted;
		
		init(input,sorted);
		cout<<K<<' '<<get_num_of_operations(input,sorted)<<'\n';
	}
	
	return	0;
}
