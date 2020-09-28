#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int					N,cnt;
	priority_queue<int>	card_q;

	cin>>N;
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	c;
		
		cin>>c;
		card_q.push(-c);
	}
	
	if( N == 1 )
	{
		cout<<"0\n";
		return	0;
	}
	
	for(;card_q.size()!=1;)
	{
		int	c1,c2,m;
		
		c1 = -card_q.top();
		card_q.pop();
		
		c2 = -card_q.top();
		card_q.pop();
		
		m = c1+c2;
		cnt += m;
		
		card_q.push(-m);
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
