#include	<iostream>
#include	<vector>
#include	<string>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	10

#define	UP		0
#define	LEFT	1
#define	DOWN	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	REVERSE_DIR(d)	(((d)+2)%MAX_DIR)
#define	GET_DIR(c)		(((c)=='N')?UP:((c)=='S')?DOWN:((c)=='W')?LEFT:RIGHT)

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{1,0},{0,-1},{-1,0},{0,1}};

typedef	struct	_PLAYER_INFO	Player;
struct	_PLAYER_INFO
{
	string	name;
	int		row,col,direction;
};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<(MAX))

queue<int>	grid[MAX_SIZE][MAX_SIZE];
int			cnt_of_players[MAX_SIZE][MAX_SIZE];

void	input(int& w,int& h,int& num_of_players,int& num_of_rounds,vector<Player>& p)
{
	cin>>w>>h>>num_of_players;
	
	for(int i=1;i<=num_of_players;i++)
	{
		Player	tmp;
		char	c;
		
		cin>>tmp.name>>tmp.col>>tmp.row;
		cin>>c;
		tmp.direction = GET_DIR(c);
		
		p.push_back(tmp);
	}
	
	cin>>num_of_rounds;
}

void	init(int w,int h,vector<Player>& p)
{
	for(int row=0;row<h;row++)
	{
		for(int col=0;col<w;col++)
		{
			while( grid[row][col].size() != 0 )
			{
				grid[row][col].pop();
			}
			
			cnt_of_players[row][col] = 0;
		}
	}
	
	for(int i=0;i<p.size();i++)
	{
		Player& current = p[i];
		int&	row = current.row;
		int&	col = current.col;
		
		grid[row][col].push(i);
		cnt_of_players[row][col]++;
	}
}

void	move_player(Player& p,int w,int h)
{
	int	adj_row,adj_col;
	
	adj_row = p.row+adj[p.direction].d_row;
	adj_col = p.col+adj[p.direction].d_col;
	
	if( IN_RANGE(0,adj_row,h) && IN_RANGE(0,adj_col,w) )
	{
		// do nothing
	}
	else
	{
		p.direction = REVERSE_DIR(p.direction);
		
		adj_row = p.row+adj[p.direction].d_row;
		adj_col = p.col+adj[p.direction].d_col;
	}
	
	p.row = adj_row;
	p.col = adj_col;
}

void	change_dir(Player& p1,Player& p2)
{
	if( p1.name.length() > p2.name.length() )
	{
		int	longer_name_dir,shorter_name_dir;
		
		longer_name_dir = p1.direction;
		shorter_name_dir = p2.direction;
		
		p1.direction = shorter_name_dir;
		p2.direction = REVERSE_DIR(longer_name_dir);
	}
	else
	{
		int	longer_name_dir,shorter_name_dir;
		
		longer_name_dir = p2.direction;
		shorter_name_dir = p1.direction;
		
		p2.direction = shorter_name_dir;
		p1.direction = REVERSE_DIR(longer_name_dir);
	}
}

void	play(int w,int h,int num_of_rounds,vector<Player>& p)
{
	for(int r=1;r<=num_of_rounds;r++)
	{
		for(int row=0;row<h;row++)
		{
			for(int col=0;col<w;col++)
			{
				queue<int>& player_list = grid[row][col];
				int&		num_of_players_at_current = cnt_of_players[row][col];
				
				for(int i=1;i<=num_of_players_at_current;i++)
				{
					int&	player_index = player_list.front();
					Player&	current = p[player_index];
					
					player_list.pop();
					
					move_player(current,w,h);
					grid[current.row][current.col].push(player_index);
				}
			}
		}
	
		for(int row=0;row<h;row++)
		{
			for(int col=0;col<w;col++)
			{
				queue<int>& player_list = grid[row][col];
				
				cnt_of_players[row][col] = player_list.size();
				
				if( cnt_of_players[row][col] == 2 )
				{
					int&	p1_index = player_list.front();
					Player&	p1 = p[p1_index];
					
					player_list.pop();
					
					int&	p2_index = player_list.front();
					Player&	p2 = p[p2_index];
					
					player_list.pop();
					
					change_dir(p1,p2);
					
					player_list.push(p1_index);
					player_list.push(p2_index);
				}
				else if( cnt_of_players[row][col] > 2 )
				{
					for(int i=0;i<cnt_of_players[row][col];i++)
					{
						int&	current_player_index = player_list.front();
						Player&	current = p[current_player_index];
						
						player_list.pop();
						current.direction = REVERSE_DIR(current.direction);
						player_list.push(current_player_index);
					}
				}
			}
		}
	}
}

void	find_winner(vector<Player>& p,int c)
{
	int&	it_row = p[0].row;
	int&	it_col = p[0].col;
	
	int		min_distance,winner;
	
	min_distance = 1000000;
	
	for(int i=1;i<p.size();i++)
	{
		int	distance;
		
		distance = (it_row-p[i].row)*(it_row-p[i].row)+(it_col-p[i].col)*(it_col-p[i].col);
		
		if( distance <= min_distance )
		{
			if( distance < min_distance )
			{
				winner = i;
				min_distance = distance;
			}
			else
			{
				if( p[i].name.length() < p[winner].name.length() )
				{
					winner = i;
				}
			}
		}	
	}
	
	cout<<"Case "<<c<<": "<<p[winner].name<<'\n';	
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int				M,N,P,R;
		vector<Player>	players;
		
		input(M,N,P,R,players);
		init(M,N,players);
		play(M,N,R,players);
		find_winner(players,i);
	}
	
	return	0;
}
