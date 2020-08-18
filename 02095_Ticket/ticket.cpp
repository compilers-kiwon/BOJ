#include	<iostream>
#include	<algorithm>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100000+1)
	
typedef	pair<int,int>	Seat;	// first:begin,second:end
typedef	pair<int,Seat>	State;	// first:end-begin+1,second:Seat

int		N,L,M;
bool	visited[MAX_SIZE],empty[MAX_SIZE];
Seat	preferred[MAX_SIZE+1];

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>L>>M;
	
	for(int i=1;i<=M;i++)
	{
		cin>>preferred[i].first;
		preferred[i].second = preferred[i].first+L-1;
	}
	preferred[M+1].first = preferred[M+1].second = MAX_SIZE;
	
	fill(&empty[1],&empty[N+1],true);
	sort(&preferred[1],&preferred[M+1]);
	
	int		profit;
	Seat	prev_seat;
	
	profit = 0;
	prev_seat = make_pair(1,N);
	
	for(int i=1;i<=M+1;i++)
	{
		int&	prev_begin = prev_seat.first;
		int&	prev_end = prev_seat.second;
		
		if( !IN_RANGE(prev_begin,preferred[i].first,prev_end) )
		{
			profit += 2;
			visited[i-1] = true;
			fill(&empty[prev_begin],&empty[prev_end+1],false);
			//cout<<"("<<prev_begin<<","<<prev_end<<"):2\n";
		}
		
		prev_seat = preferred[i];
	}
	
	priority_queue<State>	pq;
	
	for(int i=1;i<=N;)
	{
		if( empty[i] == false )
		{
			i++;
			continue;
		}
		
		int	s,e;
		
		s = i;
		for(;i<=N&&empty[i]==true;i++);
		e = i;
		
		pq.push(make_pair(e-s,make_pair(s,e-1)));	
	}
	
	for(int f=1;f<=M&&!pq.empty()&&pq.top().first>=L;f++)
	{
		if( visited[f] == true )
		{
			continue;
		}
		
		int	size,s,e;
		
		size = pq.top().first;
		s = pq.top().second.first;
		e = pq.top().second.second;
		
		pq.pop();
		
		size -= L;
		s += L;
		
		if( size >= L )
		{
			pq.push(make_pair(size,make_pair(s,e)));
		}
		//cout<<f<<":1\n";
		profit++;
	}
	
	cout<<profit<<'\n';
	
	return	0;
}
