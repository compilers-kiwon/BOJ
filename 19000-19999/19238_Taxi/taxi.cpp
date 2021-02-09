#include	<iostream>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_SIZE		(20+1)
#define	EMPTY			0
#define	BLOCKED			-1

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	pair<int,Pos>	State;	// first:distance,second:Pos
	
typedef	struct	_PASSENGER_INFO	Passenger;
struct	_PASSENGER_INFO
{
	int	e_row,e_col,distance;
};

int					N,M,taxi_row,taxi_col,fuel;
int					grid[MAX_SIZE][MAX_SIZE];
map<int,Passenger>	passenger;

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		get_distance(int s_row,int s_col,int e_row,int e_col)
{
	int				ret;
	bool			visited[MAX_SIZE][MAX_SIZE];
	queue<State>	state_q;
	
	for(int row=1;row<=N;row++)
	{
		fill(&visited[row][1],&visited[row][N+1],false);
	}
	
	visited[s_row][s_col] = true;
	state_q.push(make_pair(0,make_pair(s_row,s_col)));
	
	for(ret=-1;!state_q.empty();)
	{
		int	current_row,current_col,current_distance;
		
		current_distance = state_q.front().first;
		current_row = state_q.front().second.first;
		current_col = state_q.front().second.second;
		
		state_q.pop();
		
		if( current_row==e_row && current_col==e_col )
		{
			ret = current_distance;
			break;
		}
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) || grid[adj_row][adj_col]==BLOCKED )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == false )
			{
				visited[adj_row][adj_col] = true;
				state_q.push(make_pair(current_distance+1,make_pair(adj_row,adj_col)));
			}
		}
	}
	
	return	ret;
}

void	input(void)
{
	cin>>N>>M>>fuel;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
			grid[row][col] *= -1;
		}
	}
	
	cin>>taxi_row>>taxi_col;
	
	for(int i=1;i<=M;i++)
	{
		int	s_row,s_col,e_row,e_col;
		
		cin>>s_row>>s_col>>e_row>>e_col;
		grid[s_row][s_col] = i;
		
		passenger[i].e_row = e_row;
		passenger[i].e_col = e_col;
		passenger[i].distance = get_distance(s_row,s_col,e_row,e_col);
	}
}

int		find_nearest_passenger(int& row,int& col,int& distance)
{
	if( grid[taxi_row][taxi_col] != EMPTY )
	{
		row = taxi_row;
		col = taxi_col;
		distance = 0;
		
		return	grid[taxi_row][taxi_col];
	}
	
	queue<Pos>	pos_q;
	int			dp[MAX_SIZE][MAX_SIZE],ret;
	
	for(row=1;row<=N;row++)
	{
		fill(&dp[row][1],&dp[row][N+1],MAX_SIZE*MAX_SIZE);
	}
	
	dp[taxi_row][taxi_col] = 0;
	pos_q.push(make_pair(taxi_row,taxi_col));
	
	for(ret=EMPTY,distance=1;!pos_q.empty();distance++)
	{
		priority_queue<Pos>	pq;
		
		for(int i=1,size=pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,N) || grid[adj_row][adj_col]==BLOCKED )
				{
					continue;
				}
				
				if( distance < dp[adj_row][adj_col] )
				{
					dp[adj_row][adj_col] = distance;
					pos_q.push(make_pair(adj_row,adj_col));
					
					if( grid[adj_row][adj_col] > EMPTY )
					{
						pq.push(make_pair(-adj_row,-adj_col));
					}
				}
			}
		}
		
		if( !pq.empty() )
		{
			row = -pq.top().first;
			col = -pq.top().second;
			
			ret = grid[row][col];
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;M!=0;M--,i++)
	{
		int	p_row,p_col,p_distance,p_idx;
		
		p_idx = find_nearest_passenger(p_row,p_col,p_distance);
		
		if( p_idx==EMPTY || passenger[p_idx].distance==-1 )
		{
			break;
		}
		
		if( fuel < p_distance+passenger[p_idx].distance )
		{
			break;
		}
		
		taxi_row = passenger[p_idx].e_row;
		taxi_col = passenger[p_idx].e_col;
		
		fuel += passenger[p_idx].distance-p_distance;
		grid[p_row][p_col] = EMPTY;
	}
	
	if( M != 0 )
	{
		cout<<"-1\n";
	}
	else
	{
		cout<<fuel<<'\n';
	}
	
	return	0;
}
