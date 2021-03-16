#include	<iostream>
#include	<queue>

using namespace	std;

typedef	long long int		int64;
typedef	pair<int64,int64>	Value;		// first:Alice,second:Bob
typedef	pair<int64,Value>	Treasure;	// first:sum of value,second:value

void	input(priority_queue<Treasure>& tq)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int64	A,B;
		
		cin>>A>>B;
		tq.push(make_pair(A+B,make_pair(A,B)));
	}
}

void	get_score(int64* score,priority_queue<Treasure>& tq)
{
	score[0] = score[1] = 0;
	
	for(int ptr=0;!tq.empty();ptr=(ptr+1)%2,tq.pop())
	{
		int64	s[2];
		
		s[0] = tq.top().second.first;
		s[1] = tq.top().second.second;
		
		score[ptr] += s[ptr];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int64	score[2] = {0,0};
		priority_queue<Treasure>	treasure_q;
		
		input(treasure_q);
		get_score(score,treasure_q);
		
		cout<<score[0]-score[1]<<'\n';
	}
	
	return	0;
}
