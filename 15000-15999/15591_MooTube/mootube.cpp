#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(5000+1)

typedef	pair<int,int>	Edge;	// first:to, second:USADO
typedef	pair<int,int>	Query;	// first:K, second:V

int				N,Q;
Query			query[MAX_SIZE];
vector<Edge>	connected[MAX_SIZE];

void	init(void)
{
	cin>>N>>Q;
	
	for(int i=1;i<N;i++)
	{
		int	p,q,r;
		
		cin>>p>>q>>r;
		
		connected[p].push_back(make_pair(q,r));
		connected[q].push_back(make_pair(p,r));
	}
	
	for(int i=1;i<=Q;i++)
	{
		cin>>query[i].first>>query[i].second;
	}
}

int		get_cnt_of_recommendation(int k,int v)
{
	queue<int>		video_q;
	vector<bool>	visited(N+1,false);
	int				cnt;
	
	video_q.push(v);
	visited[v] = true;
	cnt = 0;
	
	while( !video_q.empty() )
	{
		int	current_video;
		
		current_video = video_q.front();
		video_q.pop();
		
		vector<Edge>&	adj_video_vec = connected[current_video];
		
		for(int i=0;i<adj_video_vec.size();i++)
		{
			int&	adj_video = adj_video_vec[i].first;
			int&	adj_USADO = adj_video_vec[i].second;
			
			if( visited[adj_video]==false && adj_USADO>=k )
			{
				visited[adj_video] = true;
				video_q.push(adj_video);
				cnt++;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	for(int i=1;i<=Q;i++)
	{
		cout<<get_cnt_of_recommendation(query[i].first,query[i].second)<<'\n';
	}
	
	return	0;
}
