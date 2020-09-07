#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_KEYS	26

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	EMPTY	'.'
#define	WALL	'*'
#define	DOC		'$'

#define	is_key(k)	IN_RANGE('a',(k),'z')
#define	is_door(d)	IN_RANGE('A',(d),'Z')

#define	get_key_index(k)	((int)((k)-'a'))
#define	get_door_index(d)	((int)((d)-'A'))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;

int		h,w;
char	grid[MAX_SIZE+1][MAX_SIZE+1];
bool	visited[MAX_SIZE+1][MAX_SIZE+1];

void	input(string& key)
{
	cin>>h>>w;
	
	for(int row=0;row<=h+1;row++)
	{
		for(int col=0;col<=w+1;col++)
		{
			visited[row][col] = false;
		}
	}
	
	for(int row=1;row<=h;row++)
	{
		cin>>&grid[row][1];
	}
	
	for(int row=1;row<=h;row++)
	{
		grid[row][0] = grid[row][w+1] = EMPTY;
	}
	
	for(int col=0;col<=w+1;col++)
	{
		grid[0][col] = grid[h+1][col] = EMPTY;
	}
	
	cin>>key;
}

void	parse_key(string& str,bool* key)
{
	fill(key,key+MAX_KEYS,false);
	
	if( str == "0" )
	{
		return;
	}
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		key[get_key_index(c)] = true;
	}
}

int		get_document(queue<Pos>& q,bool* my_key)
{
	int			ret;
	queue<Pos>	door_q[MAX_KEYS];
	
	visited[0][0] = true;
	q.push(make_pair(0,0));
	
	for(ret=0;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(0,adj_row,h+1) || !IN_RANGE(0,adj_col,w+1) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == true )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col] == EMPTY )
			{
				q.push(make_pair(adj_row,adj_col));
				visited[adj_row][adj_col] = true;
				
				continue;
			}
			
			if( grid[adj_row][adj_col] == DOC )
			{
				q.push(make_pair(adj_row,adj_col));
				visited[adj_row][adj_col] = true;
				
				ret++;
				continue;
			}
			
			if( grid[adj_row][adj_col] == WALL )
			{
				continue;
			}
			
			if( is_key(grid[adj_row][adj_col]) == true )
			{
				int	key_idx;
				
				key_idx = get_key_index(grid[adj_row][adj_col]);
				
				if( my_key[key_idx] == false )
				{
					my_key[key_idx] = true;
					
					queue<Pos>&	opened_door = door_q[key_idx];
					
					for(;!opened_door.empty();)
					{
						int	door_row,door_col;
						
						door_row = opened_door.front().first;
						door_col = opened_door.front().second;
						
						opened_door.pop();
						
						q.push(make_pair(door_row,door_col));
						visited[door_row][door_col] = true;
					}
				}
				
				q.push(make_pair(adj_row,adj_col));
				visited[adj_row][adj_col] = true;
				
				continue;
			}
			
			if( is_door(grid[adj_row][adj_col]) == true )
			{
				int	door_idx;
				
				door_idx = get_door_index(grid[adj_row][adj_col]);
				
				if( my_key[door_idx] == true )
				{
					q.push(make_pair(adj_row,adj_col));
					visited[adj_row][adj_col] = true;
				}
				else
				{
					door_q[door_idx].push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	t;
	
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		string		s;
		queue<Pos>	q;
		bool		k[MAX_KEYS];
		
		input(s);
		parse_key(s,k);
		
		cout<<get_document(q,k)<<'\n';
	}
	
	return	0;
}
