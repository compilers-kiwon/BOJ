#include	<iostream>
#include	<vector>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	NUM_OF_LOCATIONS	8

#define	START	0
#define	END		1
#define	TELE1	2
#define	TELE2	3
#define	TELE3	4

#define	TELE_TIME	10

typedef	long long int				int64;
typedef	pair<pair<int64,int64>,int>	Pos;	// <first:x,second:y>,second:type
typedef	pair<int,int64>				Path;	// first:to,second:time
typedef	Path						State;	// first:-time,second:current_pos

void		init(Pos* p)
{
	cin>>p[0].first.first>>p[0].first.second;
	p[0].second = START;
	
	cin>>p[1].first.first>>p[1].first.second;
	p[1].second = END;
	
	cin>>p[2].first.first>>p[2].first.second;
	cin>>p[3].first.first>>p[3].first.second;
	p[2].second = p[3].second = TELE1;
	
	cin>>p[4].first.first>>p[4].first.second;
	cin>>p[5].first.first>>p[5].first.second;
	p[4].second = p[5].second = TELE2;
	
	cin>>p[6].first.first>>p[6].first.second;
	cin>>p[7].first.first>>p[7].first.second;
	p[6].second = p[7].second = TELE3;
}

void		build_graph(vector<Path>* connected,Pos* p)
{
	for(int i=0;i<NUM_OF_LOCATIONS-1;i++)
	{
		for(int j=i+1;j<NUM_OF_LOCATIONS;j++)
		{
			int64	t;
			
			if( p[i].second == p[j].second )
			{
				t = TELE_TIME;
			}
			else
			{
				t = abs(p[i].first.first-p[j].first.first)
					+ abs(p[i].first.second-p[j].first.second);
			}
			
			connected[i].push_back(make_pair(j,t));
			connected[j].push_back(make_pair(i,t));
		}
	}
}

int64		find_shortest_path(vector<Path>* connected)
{
	priority_queue<State>	pq;
	vector<int64>			dp(NUM_OF_LOCATIONS,0x7FFFFFFFFFFFFFFF);
	
	pq.push(make_pair(0,START));
	dp[START] = 0;
	
	for(;!pq.empty();)
	{
		int		current_pos;
		int64	current_time;
		
		current_time = -pq.top().first;
		current_pos = pq.top().second;
		
		pq.pop();
		
		if( current_pos == END )
		{
			break;
		}
		
		vector<Path>&	adj_pos = connected[current_pos];
		
		for(int i=0;i<adj_pos.size();i++)
		{
			int&	adj_p = adj_pos[i].first;
			int64&	adj_t = adj_pos[i].second;
			
			if( current_time+adj_t < dp[adj_p] )
			{
				dp[adj_p] = current_time+adj_t;
				pq.push(make_pair(-dp[adj_p],adj_p));
			}
		}
	}
	
	return	dp[END];
}

int		main(void)
{
	Pos				p[NUM_OF_LOCATIONS];
	vector<Path>	connected[NUM_OF_LOCATIONS];
	
	init(p);
	build_graph(connected,p);
	
	cout<<find_shortest_path(connected)<<'\n';
	
	return	0;
}
