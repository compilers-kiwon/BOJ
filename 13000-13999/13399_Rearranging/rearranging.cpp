#include	<iostream>
#include	<stack>

using namespace	std;

#define	MAX_NUM	200000

int			n,m;
bool		visited[MAX_NUM+1];
stack<int>	st;

int	main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int	e;
		
		cin>>e;
		st.push(e);
	}
	
	int	cnt;
	
	for(cnt=0;!st.empty();)
	{
		int	e;
		
		e = st.top();
		st.pop();
		
		if( visited[e] == false )
		{
			visited[e] = true;
			cout<<e<<'\n';
			cnt++;
		}
	}
	
	if( cnt != n )
	{
		for(int i=1;cnt!=n;i++)
		{
			if( visited[i] == false )
			{
				cout<<i<<'\n';
				cnt++;
			}
		}
	}
	
	return	0;
}
