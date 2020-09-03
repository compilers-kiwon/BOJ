#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	NORTH	0
#define	SOUTH	1
#define	WEST	2
#define	EAST	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	MAX_SIZE			(100+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	get_dir(c)			(((c)=='N')?NORTH:((c)=='S')?SOUTH:((c)=='W')?WEST:EAST)
#define	char2int(c)			((int)((c)-'0'))

typedef	pair<int,int>	Pos;	// first:y,second:x
typedef	pair<int,int>	Oil;	// first:strength,second:direction

int		x,y,x0,y0,t;
Oil		map[MAX_SIZE][MAX_SIZE];
char	grid[MAX_SIZE][MAX_SIZE+1];

void	input(void)
{
	cin>>x>>y>>x0>>y0>>t;
	
	for(int row=1;row<=y;row++)
	{
		string	str;
		
		cin>>str;
		
		for(int col=1,i=0;i<str.length();i+=2,col++)
		{
			char&	s = str[i];
			char&	d = str[i+1];
			
			map[row][col].first = char2int(s);
			map[row][col].second = get_dir(d);
		}
	}
}

void	bfs(void)
{
	queue<Pos>	pos_q;
	
	grid[y0][x0] = 'X';
	pos_q.push(make_pair(y0,x0));
	
	for(int time=1;time<=t;time++)
	{
		for(int i=1,size=pos_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			int&	strength = map[current_row][current_col].first;
			int&	direction = map[current_row][current_col].second;
			
			for(int s=1;s<=strength;s++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[direction].d_row*s;
				adj_col = current_col+adj[direction].d_col*s;
				
				if( !IN_RANGE(1,adj_row,y) || !IN_RANGE(1,adj_col,x) )
				{
					break;
				}
				
				if( grid[adj_row][adj_col] == 'X' )
				{
					continue;
				}
				
				grid[adj_row][adj_col] = 'X';
				pos_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		
		for(int row=1;row<=y;row++)
		{
			fill(&grid[row][1],&grid[row][x+1],'.');
			grid[row][x+1] = '\0';
		}
		
		bfs();
		cout<<"Data Set "<<k<<":\n";
		
		for(int row=1;row<=y;row++)
		{
			cout<<&grid[row][1]<<'\n';
		}
		cout<<'\n';
	}
	
	return	0;
}
