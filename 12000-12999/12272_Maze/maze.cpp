#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	100
#define	DANGEROUS	-1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	dx,dy;
} adj[MAX_DIR] = {{0,-1},{0,1},{-1,0},{1,0}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

#define	FALSE			0
#define	TRUE			1
#define	INTERMEDIATE	2

typedef	pair<int,int>	Pos;	// first:x, second:y

int	T,N,M;
Pos	e1,e2;
int	maze[MAX_SIZE][MAX_SIZE];
int	visited[MAX_SIZE][MAX_SIZE];
int	power_map[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	cin>>e1.first>>e1.second>>e2.first>>e2.second;
	
	for(int y=0;y<N;y++)
	{
		for(int x=0;x<M;x++)
		{
			cin>>maze[y][x];
			visited[y][x] = FALSE;
			power_map[y][x] = 0;
		}
	}
}
	
int		get_optimal_path(void)
{
	int			ret;
	queue<Pos>	pos_q;
	
	ret = 0;
	
	if( !IN_RANGE(0,e1.first,N) || !IN_RANGE(0,e1.second,M)
		|| !IN_RANGE(0,e2.first,N) || !IN_RANGE(0,e2.second,M) )
	{
		return	ret;		
	}

	if( maze[e1.first][e1.second]==DANGEROUS || maze[e2.first][e2.second]==DANGEROUS )
	{
		return	ret;
	}
	
	pos_q.push(e1);
	visited[e1.first][e1.second] = TRUE;
	power_map[e1.first][e1.second] = maze[e1.first][e1.second];
	
	for(;!pos_q.empty();)
	{
		queue<Pos>	visited_at_this_time;
		
		for(int i=1,to=pos_q.size();i<=to;i++)
		{
			int	current_power,current_x,current_y;
			
			current_y = pos_q.front().first;
			current_x = pos_q.front().second;
			current_power = power_map[current_y][current_x];
			
			pos_q.pop();
			
			if( current_y==e2.first && current_x==e2.second )
			{
				ret = current_power;
				break;
			}
		
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_power,adj_x,adj_y;
				
				adj_x = current_x+adj[d].dx;
				adj_y = current_y+adj[d].dy;
				
				if( !IN_RANGE(0,adj_x,M) || !IN_RANGE(0,adj_y,N) )
				{
					continue;
				}
				
				if( maze[adj_y][adj_x] == DANGEROUS )
				{
					continue;
				}
				
				adj_power = current_power+maze[adj_y][adj_x];
				
				if( visited[adj_y][adj_x] != TRUE )
				{
					if( visited[adj_y][adj_x] == FALSE )
					{
						visited_at_this_time.push(make_pair(adj_y,adj_x));
						visited[adj_y][adj_x] = INTERMEDIATE;
					}
					power_map[adj_y][adj_x] = max(power_map[adj_y][adj_x],adj_power);
				}
			}
		}
		
		if( ret != 0 )
		{
			break;
		}
		
		for(;!visited_at_this_time.empty();visited_at_this_time.pop())
		{
			Pos	p;
			
			p = visited_at_this_time.front();
			visited[p.first][p.second] = TRUE;
			pos_q.push(p);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	max_power;
		
		input();
		max_power = get_optimal_path();
		
		cout<<"Case #"<<t<<": ";
		
		if( max_power == 0 )
		{
			cout<<"Mission Impossible.\n";
		}
		else
		{
			cout<<max_power<<'\n';
		}
	}
	
	return	0;
}
