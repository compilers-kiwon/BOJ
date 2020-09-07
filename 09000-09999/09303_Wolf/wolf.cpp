#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

double	safe[MAX_SIZE][MAX_SIZE];

typedef	pair<double,int>	State;	// first:safe, second:intersection

double	get_safe_path(vector<int>* connected,int from,int to)
{
	vector<double>			dp(MAX_SIZE,0.0);
	priority_queue<State>	pq;
	
	dp[from] = 1.0;
	pq.push(make_pair(1.0,from));
	
	while( !pq.empty() )
	{
		int		current_inter;
		double	current_safe;
		
		current_safe = pq.top().first;
		current_inter = pq.top().second;
		
		pq.pop();
		
		if( current_inter == to )
		{
			break;
		}
		
		vector<int>&	adj = connected[current_inter];
		
		for(int i=0;i<adj.size();i++)
		{
			int&	next = adj[i];
			double	tmp_safe;
			
			tmp_safe = current_safe*safe[current_inter][next];
			
			if( tmp_safe > dp[next] )
			{
				dp[next] = tmp_safe;
				pq.push(make_pair(tmp_safe,next));
			}
		}
	}
	
	return	dp[to];
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int t=1;t<=T;t++)
	{
		vector<int>	prev[MAX_SIZE];
		int			N,X,Y,M;
		
		scanf("%d %d %d %d",&N,&X,&Y,&M);
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				safe[i][j] = 0.0;
			}
		}
		
		for(int i=1;i<=M;i++)
		{
			int		A,B;
			double	p;
			
			scanf("%d %d %lf",&A,&B,&p);
			
			prev[A].push_back(B);
			safe[A][B] = max(safe[A][B],p);
		}
	
		printf("Case %d: %.16g\n",t,get_safe_path(prev,X,Y));
	}
	
	return	0;
}
