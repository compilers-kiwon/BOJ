#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CITY		(1000+1)

typedef	pair<int,int>	Cable;	// first:cost, second:from
typedef	pair<int,int>	Path;	// frist:to, second:cost

int						N,M,K;
bool					is_plant[MAX_NUM_OF_CITY];
vector<Path>			connected[MAX_NUM_OF_CITY];
priority_queue<Cable>	pq;

void	input(void)
{
	cin>>N>>M>>K;
	
	for(int i=1;i<=K;i++)
	{
		int	n;
		
		cin>>n;
		is_plant[n] = true;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	u,v,w;
		
		cin>>u>>v>>w;
		
		connected[u].push_back(make_pair(v,w));
		connected[v].push_back(make_pair(u,w));
		
		if( is_plant[u] == true && is_plant[v] == false )
		{
			pq.push(make_pair(-w,v));
		}
		
		if( is_plant[u] == false && is_plant[v] == true )
		{
			pq.push(make_pair(-w,u));
		}
	}
}

int		place_cable(void)
{
	int	cnt;
	
	for(cnt=0;!pq.empty();)
	{
		int	next_cost,next_city;
		
		next_cost = -pq.top().first;
		next_city = pq.top().second;
		
		pq.pop();
		
		if( is_plant[next_city] == true )
		{
			continue;
		}
		
		is_plant[next_city] = true;
		cnt += next_cost;
		
		for(int i=0;i<connected[next_city].size();i++)
		{
			if( is_plant[connected[next_city][i].first] == false )
			{
				pq.push(make_pair(-connected[next_city][i].second,connected[next_city][i].first));
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	input();
	cout<<place_cable()<<endl;
	
	return	0;
}
