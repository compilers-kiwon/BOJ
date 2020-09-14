#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>		Keyboard;	// first:-time, second:-keyboard_no
typedef	pair<Keyboard,char>	Input;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int						N,M;
	priority_queue<Input>	pq;
	
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int		a,b;
		char	c;
		
		cin>>a>>b>>c;
		pq.push(make_pair(make_pair(-b,-a),c));
	}
	
	for(;!pq.empty();pq.pop())
	{
		cout<<pq.top().second;
	}
	cout<<'\n';
	
	return	0;
}
