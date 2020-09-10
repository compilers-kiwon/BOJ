#include	<iostream>
#include	<deque>

using namespace	std;

#define	MAX_SIZE		(5000000+1)

typedef	pair<int,int>	Number;	// first:value,second:index

#define	value	first
#define	index	second

int	A[MAX_SIZE];

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N,L;
	deque<Number>	dq;
	
	cin>>N>>L;
	
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		
		if( !dq.empty() && dq.front().index<i-L+1 )
		{
			dq.pop_front();
		}
		
		for(;!dq.empty()&&dq.back().value>A[i];dq.pop_back());
		dq.push_back(make_pair(A[i],i));
		
		cout<<dq.front().value<<' ';
	}
	
	return	0;
}
