#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_PLACE	(1000+1)
#define	MAX_NUM_OF_MEMBER	(100+1)

typedef	pair<int,int>	Path;	// first:to, second:len
typedef	pair<int,int>	State;	// fisrt:-total_len, second:place

int				N,V,E,A,B,H[MAX_NUM_OF_MEMBER];
vector<Path>	connected[MAX_NUM_OF_PLACE];

void	init(void)
{
	scanf("%d %d %d %d %d",&N,&V,&E,&A,&B);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&H[i]);
	}
	
	for(int i=1;i<=E;i++)
	{
		int	a,b,l;
		
		scanf("%d %d %d",&a,&b,&l);
		
		connected[a].push_back(make_pair(b,l));
		connected[b].push_back(make_pair(a,l));
	}
}

int		find_shortest_path(int from,int to)
{
	priority_queue<State>	pq;
	vector<int>				dp(V+1,0x7FFFFFFF);
	
	pq.push(make_pair(0,from));
	dp[from] = 0;
	
	while( !pq.empty() )
	{
		int	current_place,current_len;
		
		current_place = pq.top().second;
		current_len = -pq.top().first;
		
		pq.pop();
		
		if( current_place == to )
		{
			break;
		}
		
		vector<Path>&	current_path = connected[current_place];
		
		for(int i=0;i<current_path.size();i++)
		{
			int&	adj_place = current_path[i].first;
			int&	adj_len = current_path[i].second;
			int		tmp;
			
			tmp = current_len+adj_len;
			
			if( tmp < dp[adj_place] )
			{
				dp[adj_place] = tmp;
				pq.push(make_pair(-tmp,adj_place));
			}
		}
	}
	
	if( dp[to] == 0x7FFFFFFF )
	{
		dp[to] = -1;
	}
	
	return	dp[to];
}

int		main(void)
{
	init();
	
	int	d,i;
	
	for(i=1,d=0;i<=N;i++)
	{
		d += find_shortest_path(H[i],A)+find_shortest_path(H[i],B);
	}
	
	printf("%d\n",d);
	
	return	0;
}
