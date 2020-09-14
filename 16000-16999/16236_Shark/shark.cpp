#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_GRID_SIZE	(20+1)
#define	MAX_FISH_SIZE	6
#define	BABY_SHARK		9

#define	INF		0x7FFFFFFF

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Pos;
typedef	pair<int,Pos>	State;

typedef	struct	_SHARK_INFO	Shark;
struct	_SHARK_INFO
{
	Pos	p;
	int	size,time,num_of_fish_to_eat;
};

int			N,grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
queue<Pos>	fish_q[MAX_FISH_SIZE+1];
Shark		baby;

void	init(void)
{
	cin>>N;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			int&	g = grid[row][col];
			
			cin>>g;
			
			if( g == BABY_SHARK )
			{
				baby.p = make_pair(row,col);
				baby.size = 2;
				g = baby.time = baby.num_of_fish_to_eat = 0;
			}
			else
			{
				if( g != 0 )
				{
					fish_q[g].push(make_pair(row,col));
				}
			}
		}
	}
}

int		get_min_distance(Pos& fish)
{
	priority_queue<State>	pq;
	int						min_distance,dp[MAX_GRID_SIZE][MAX_GRID_SIZE];
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			dp[row][col] = INF;
		}
	}
	
	min_distance = INF;
	dp[baby.p.first][baby.p.second] = 0;
	pq.push(make_pair(0,baby.p));
	
	for(;!pq.empty();)
	{
		int	current_distance,current_row,current_col;
		
		current_distance = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==fish.first && current_col==fish.second )
		{
			min_distance = current_distance;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
			{
				if( grid[adj_row][adj_col]<=baby.size && current_distance+1<dp[adj_row][adj_col] )
				{
					dp[adj_row][adj_col] = current_distance+1;
					pq.push(make_pair(-(current_distance+1),make_pair(adj_row,adj_col)));
				}
			}
		}
	}
	
	return	min_distance;
}

Pos		get_candidate(int& d)
{
	int	candidate_row,candidate_col,candidate_size,candidate_distance;
	
	candidate_row = candidate_col = candidate_size = candidate_distance = INF;
	
	for(int fish_size=1;fish_size<baby.size&&fish_size<=MAX_FISH_SIZE;fish_size++)
	{
		queue<Pos>&	fq = fish_q[fish_size];
		
		for(int i=1,to=fq.size();i<=to;i++)
		{
			Pos	candidate;
			int	min_distance;
			
			candidate = fq.front();
			fq.pop();
			
			min_distance = get_min_distance(candidate);
			
			if( min_distance == INF )
			{
				fq.push(candidate);
				continue;
			}
			
			if( min_distance < candidate_distance )
			{
				if( IN_RANGE(1,candidate_size,MAX_FISH_SIZE) )
				{
					fish_q[candidate_size].push(make_pair(candidate_row,candidate_col));
				}
				
				candidate_row = candidate.first;
				candidate_col = candidate.second;
				candidate_size = fish_size;
				candidate_distance = min_distance; 
			}
			else if( min_distance == candidate_distance )
			{
				if( (candidate.first<candidate_row) || 
					(candidate.first==candidate_row && candidate.second<candidate_col) )
				{
					fish_q[candidate_size].push(make_pair(candidate_row,candidate_col));
					
					candidate_row = candidate.first;
					candidate_col = candidate.second;
					candidate_size = fish_size;
					candidate_distance = min_distance; 
				}
				else
				{
					fq.push(candidate);
				}
			}
			else
			{
				fq.push(candidate);
			}
		}
	}
	
	d = candidate_distance;
	
	return	make_pair(candidate_row,candidate_col);
}

int		simulate(void)
{
	for(;;)
	{
		Pos	candidate;
		int	min_distance;
		
		candidate = get_candidate(min_distance);
		
		if( candidate.first==INF && candidate.second==INF )
		{
			break;
		}
		
		baby.p = candidate;
		baby.time += min_distance;
		baby.num_of_fish_to_eat++;
		
		if( baby.num_of_fish_to_eat == baby.size )
		{
			baby.num_of_fish_to_eat = 0;
			baby.size++;
		}

		grid[baby.p.first][baby.p.second] = 0;
	}
	
	return	baby.time;
}

int		main(void)
{
	init();
	cout<<simulate()<<'\n';
	
	return	0;
}
