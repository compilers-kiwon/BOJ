#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Wall;	// first:-from, second:-to

int	N,M,room[MAX_SIZE];

void	init(priority_queue<Wall>& pq)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		room[i] = i;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		pq.push(make_pair(-x,-y));
	}
}

void	pull_down(priority_queue<Wall>& pq)
{
	int	from,to,cnt;
	
	for(from=to=0,cnt=N+1;!pq.empty();pq.pop())
	{
		int	current_from,current_to;
		
		current_from = -pq.top().first;
		current_to = -pq.top().second;
		
		if( IN_RANGE(from,current_from,to) == true )
		{
			to = max(to,current_to);
		}
		else
		{
			for(int i=from;i<=to;i++)
			{
				room[i] = cnt;
			}
			
			from = current_from;
			to = current_to;
			
			cnt++;
		}
	}
	
	for(int i=from;i<=to;i++)
	{
		room[i] = cnt;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Wall>	pq;
	
	init(pq);
	pull_down(pq);
	
	int	cnt,prev;
	
	cnt = 1;
	prev = room[1];
	
	for(int i=2;i<=N;i++)
	{
		if( room[i] != prev )
		{
			prev = room[i];
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
