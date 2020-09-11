#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	1000

#define	ALEX_BOOK	0	// odd,increasing
#define	BOB_BOOK	1	// even, decreasing
#define	MAX_BOOK	2

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int					N,worth[MAX_SIZE];
		priority_queue<int>	book[MAX_BOOK];
		
		cin>>N;
		
		for(int i=0;i<N;i++)
		{
			int	w;
			
			cin>>w;
			
			if( w%2 == 0 )
			{
				worth[i] = BOB_BOOK;
				book[BOB_BOOK].push(w);
			}
			else
			{
				worth[i] = ALEX_BOOK;
				book[ALEX_BOOK].push(-w);
			}
		}
		
		cout<<"Case #"<<t<<":";
		
		for(int i=0;i<N;i++)
		{
			priority_queue<int>&	pq = book[worth[i]];
			
			if( worth[i] == ALEX_BOOK )
			{
				cout<<' '<<-pq.top();
			}
			else
			{
				cout<<' '<<pq.top();
			}
			
			pq.pop();
		}
		
		cout<<'\n';
	}
	
	return	0;
}
