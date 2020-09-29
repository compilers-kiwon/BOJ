#include	<iostream>
#include	<stack>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			N,cnt,visible;
	stack<int>	stick;
	
	cin>>N;
	cnt = visible = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	h;
		
		cin>>h;
		stick.push(h);
	}
	
	for(;!stick.empty();stick.pop())
	{
		if( stick.top() > visible )
		{
			visible = stick.top();
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
