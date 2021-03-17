#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_PLAYER	26
#define	NONE		0

#define	BLOCK	'X'
#define	MONSTER	'B'
#define	EMPTY	'.'

int		M,N,P,visited[MAX_SIZE][MAX_SIZE],distance_from_monster[MAX_PLAYER];
int		monster_row,monster_col,dps[MAX_PLAYER],monster_hp;
char	grid[MAX_SIZE][MAX_SIZE+1];

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&(n)<=(MAX))
#define	get_player_idx(p)	((int)((p)-'a'))

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>	Battle;	// first:-arrive_time,second:player

void	input(void)
{
	cin>>M>>N>>P;
	
	for(int row=1;row<=M;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=N;col++)
		{
			char&	c = grid[row][col];
			
			if( c == MONSTER )
			{
				monster_row = row;
				monster_col = col;
				
				grid[row][col] = EMPTY;
			}
		}
	}
	
	for(int i=1;i<=P;i++)
	{
		char	c;
		int		n;
		
		cin>>c>>n;
		dps[get_player_idx(c)] = n;
	}
	
	cin>>monster_hp;
}

void	bfs(void)
{
	queue<Pos>	pos_q;
	int			cnt_of_player;
	
	visited[monster_row][monster_col] = 1;
	pos_q.push(make_pair(monster_row,monster_col));
	
	for(cnt_of_player=0;cnt_of_player!=P&&!pos_q.empty();pos_q.pop())
	{
		int	current_row,current_col;
				
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,M) || !IN_RANGE(1,adj_col,N) )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col]==BLOCK || visited[adj_row][adj_col]!=NONE )
			{
				continue;
			}
			
			char&	c = grid[adj_row][adj_col];
			
			if( IN_RANGE('a',c,'z') )
			{
				distance_from_monster[get_player_idx(c)] = visited[current_row][current_col];
				cnt_of_player++;
			}
			
			pos_q.push(make_pair(adj_row,adj_col));
			visited[adj_row][adj_col] = visited[current_row][current_col]+1;
		}
	}
}

int		get_num_of_booty(void)
{
	int	ret = 0;
	priority_queue<Battle>	pq;
	
	for(int i=0;i<MAX_PLAYER;i++)
	{
		int&	t = distance_from_monster[i];
		
		if( t != NONE )
		{
			pq.push(make_pair(-t,i));
		}
	}
	
	for(int current_dps=0;monster_hp>0&&!pq.empty();ret++)
	{
		int	current_time,current_player,next_time;
		
		current_time = -pq.top().first;
		current_player = pq.top().second;
		
		pq.pop();
		current_dps += dps[current_player];
		
		if( pq.empty() )
		{
			monster_hp = 0;
		}
		else
		{
			next_time = -pq.top().first;
			monster_hp -= current_dps*(next_time-current_time);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();
	bfs();
	
	cout<<get_num_of_booty()<<'\n';
	
	return	0;
}
