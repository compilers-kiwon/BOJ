#include	<iostream>
#include	<stack>
#include	<deque>

using namespace	std;

int	main(void)
{
	int			N;
	stack<int>	st;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		st.push(n);
	}
	
	deque<int>	d;
	
	for(int i=1;!st.empty();i++)
	{
		int	current,tmp;
		
		current = st.top();
		st.pop();
		
		switch(current)
		{
			case	1:
				d.push_back(i);
				break;
			case	2:
				tmp = d.back();d.pop_back();
				d.push_back(i),d.push_back(tmp);
				break;
			case	3:
				d.push_front(i);
				break;
			default:
				// do nothing
				break;
		}
	}
	
	for(;!d.empty();)
	{
		cout<<d.back()<<' ';
		d.pop_back();
	}
	
	return	0;
}
