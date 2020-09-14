#include	<iostream>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	(1000000+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Number;	// first:value,second:index

int				N,NGE[MAX_SIZE];
stack<Number>	st;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	st.push(make_pair(INF,0));
	
	for(int i=1;i<=N;i++)
	{
		int	A;
		
		cin>>A;
		
		for(;A>st.top().first;)
		{
			NGE[st.top().second] = A;
			st.pop();
		}
		st.push(make_pair(A,i));
	}
	
	for(;!st.empty();)
	{
		NGE[st.top().second] = -1;
		st.pop();
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<NGE[i]<<' ';
	}
	
	return	0;
}
