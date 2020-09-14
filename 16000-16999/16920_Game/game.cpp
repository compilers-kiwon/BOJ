#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_PLAYER	(9+1)

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	char2int(c)			((int)((c)-'0'))

#define	WALL	'#'
#define	EMPTY	'.'

typedef	pair<int,int>	Pos;	// first:row,second:col

typedef	struct	_PLAYER_INFO	Player;
struct	_PLAYER_INFO
{
	int			num_of_castle,step_size;
	queue<Pos>	pos_q;
};

int		M,N,P;
char	grid[MAX_SIZE][MAX_SIZE+1];
Player	player[MAX_PLAYER];

void	bfs(Player& p)
{
	for(int s=1;s<=p.step_size&&!p.pos_q.empty();s++)
	{
		for(int i=1,size=p.pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = p.pos_q.front().first;
			current_col = p.pos_q.front().second;
			
			p.pos_q.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( !in_range(1,adj_row,M) || !in_range(1,adj_col,N) )
				{
					continue;
				}
				
				if( grid[adj_row][adj_col] == EMPTY )
				{
					grid[adj_row][adj_col] = WALL;
					p.num_of_castle++;
					p.pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

bool	will_be_updated(void)
{
	for(int i=1;i<=P;i++)
	{
		if( player[i].pos_q.size() != 0 )
		{
			return	true;
		}
	}
	
	return	false;
}

void	play_game(void)
{
	for(bool flag=true;flag==true;)
	{
		for(int i=1;i<=P;i++)
		{
			bfs(player[i]);
		}
		
		flag = will_be_updated();
	}
}

void	input(void)
{
	cin>>M>>N>>P;
	
	for(int i=1;i<=P;i++)
	{
		cin>>player[i].step_size;
	}
	
	for(int row=1;row<=M;row++)
	{
		cin>>&grid[row][1];
		
		for(int col=1;col<=N;col++)
		{
			char&	c = grid[row][col];
			
			if( in_range('1',c,'9') == true )
			{
				Player&	p = player[char2int(c)];
				
				p.num_of_castle++;
				p.pos_q.push(make_pair(row,col));
				grid[row][col] = WALL;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	play_game();
	
	for(int i=1;i<=P;i++)
	{
		cout<<player[i].num_of_castle<<' ';
	}
	cout<<'\n';
	
	return	0;
}
