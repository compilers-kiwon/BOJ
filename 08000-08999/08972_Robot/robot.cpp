#include	<iostream>
#include	<queue>
#include	<cmath>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_DIR		9
#define	INF			0x7FFFFFFF

#define	PLAYER		'I'
#define	ROBOT		'R'
#define	EMPTY		'.'

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	get_distance(p1,p2)	(abs((p1).first-(p2).first)+abs((p1).second-(p2).second))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	char2int(c)			((int)((c)-'0'))

const struct{
	int d_row,d_col;
} adj[MAX_DIR+1] = {{},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};

int		R,C;
char	grid[MAX_SIZE][MAX_SIZE+1];
string	player_move;

void	get_next_robot_pos(const Pos& player,const Pos& robot,Pos& next)
{
	int	min_distance,d;
	
	for(min_distance=INF,d=1;d<=MAX_DIR;d++)
	{
		Pos	t;
		int	distance;
		
		t.first = robot.first+adj[d].d_row;
		t.second = robot.second+adj[d].d_col;
		distance = get_distance(player,t);
		
		if( distance < min_distance )
		{
			next = t;
			min_distance = distance;
		}
		
	}
}

void	screen_out_collision(queue<Pos>& robot_q,map<Pos,int>& n)
{
	map<Pos,int>::iterator	it;
	
	for(it=n.begin();it!=n.end();it++)
	{
		if( it->second == 1 )
		{
			robot_q.push(it->first);
		}
	}
}

bool	is_player_catched(const Pos& player,map<Pos,int>& n)
{
	map<Pos,int>::iterator	it;
	
	for(it=n.begin();it!=n.end();it++)
	{
		if( player == it->first )
		{
			return	true;
		}
	}
	
	return	false;
}

void	print_grid(const Pos& player,queue<Pos>& robot_q)
{
	for(int row=1;row<=R;row++)
	{
		fill(&grid[row][1],&grid[row][C+1],EMPTY);
	}
	
	grid[player.first][player.second] = PLAYER;
	
	for(;!robot_q.empty();)
	{
		Pos	r;
		
		r = robot_q.front();
		robot_q.pop();
		
		grid[r.first][r.second] = ROBOT;
	}
	
	for(int row=1;row<=R;row++)
	{
		cout<<&grid[row][1]<<'\n';
	}
}

void	get_pos(Pos& p,queue<Pos>& r)
{
	for(int row=1;row<=R;row++)
	{
		for(int col=1;col<=C;col++)
		{
			char&	c = grid[row][col];
			
			switch(c)
			{
				case	PLAYER:
					p = make_pair(row,col);
					break;
				case	ROBOT:
					r.push(make_pair(row,col));
					break;
				case	EMPTY:
				default :
					// do nothing
					break;
			}
		}
	}
}

void	simulate(const string& player_move)
{
	Pos			p;
	queue<Pos>	robot_q;
	
	get_pos(p,robot_q);
		
	for(int i=0;i<player_move.length();i++)
	{
		// 1. player moves
		int&	player_row = p.first;
		int&	player_col = p.second;
		
		p.first += adj[char2int(player_move[i])].d_row;
		p.second += adj[char2int(player_move[i])].d_col;
		
		// 2. Robot moves
		map<Pos,int>	next_robot_pos;
		
		for(;!robot_q.empty();)
		{
			Pos	r,n;
			
			r = robot_q.front();
			robot_q.pop();
			
			if( p == r )
			{
				cout<<"kraj "<<i+1<<'\n';
				return;
			}
			
			get_next_robot_pos(p,r,n);
			next_robot_pos[n]++;
		}
		
		// 3. catch player?
		if( is_player_catched(p,next_robot_pos) == true )
		{
			cout<<"kraj "<<i+1<<'\n';
			return;
		}
		
		// 4.check robot collision
		screen_out_collision(robot_q,next_robot_pos);
	}
	
	print_grid(p,robot_q);
}

void	input(string& str)
{
	cin>>R>>C;
	
	for(int row=1;row<=R;row++)
	{
		cin>>&grid[row][1];
	}
	
	cin>>str;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string	move;
	
	input(move);
	simulate(move);
	
	return	0;	
}
