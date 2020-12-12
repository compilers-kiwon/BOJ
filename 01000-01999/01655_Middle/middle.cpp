#include	<iostream>
#include	<queue>

using namespace	std;

typedef	priority_queue<int>	pq;

int	N;
pq	left_q,right_q;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n,tmp;
		
		cin>>n;
		
		if( left_q.empty() || right_q.empty() )
		{
			if( left_q.empty() )
			{
				left_q.push(n);
			}
			else // right_q.empty()
			{
				if( n < left_q.top() )
				{
					tmp = left_q.top();
					left_q.pop();
					
					left_q.push(n);
					right_q.push(-tmp);
				}
				else
				{
					right_q.push(-n);
				}
			}
			
			cout<<left_q.top()<<'\n';
			continue;
		}
		
		if( left_q.size() == right_q.size() )
		{
			if( n<=left_q.top() || n<=-right_q.top() )
			{
				left_q.push(n);
			}
			else
			{
				tmp = -right_q.top();
				right_q.pop();
				
				left_q.push(tmp);
				right_q.push(-n);
			}
		}
		else
		{
			if( n>=-right_q.top() || n>=left_q.top() )
			{
				right_q.push(-n);
			}
			else
			{
				tmp = left_q.top();
				left_q.pop();
				
				right_q.push(-tmp);
				left_q.push(n);
			}
		}
		
		cout<<left_q.top()<<'\n';
	}
	
	return	0;
}
