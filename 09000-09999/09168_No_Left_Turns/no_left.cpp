#include	<iostream>
#include	<queue>
#include	<string>

using namespace	std;

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	START	'S'
#define	FINISH	'F'
#define	WALL	'X'
#define	EMPTY	' '

#define	INF		0x7FFFFFFF

#define	TURN_RIGHT(d)	(((d)+1)%MAX_DIR)
#define	MAX_SIZE		(20+1)

#define	row	first
#define	col	second

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

typedef	pair<int,int>		Pos;	// first:row, second:col
typedef	pair<int,int>		Knight;	// first:-num_of_step, second:direction
typedef	pair<Knight,Pos>	State;

string	maze[MAX_SIZE];
int		dp[MAX_SIZE][MAX_SIZE][MAX_DIR];

void	input(Pos& start,Pos& finish)
{
	int	r,c;
	
	cin>>r>>c;getchar();getchar();
	
	for(int row=1;row<=r;row++)
	{
		getline(cin,maze[row]);
		maze[row].insert(maze[row].begin(),' ');
		
		for(int col=1;col<=c;col++)
		{
			dp[row][col][UP] = dp[row][col][RIGHT] =
			dp[row][col][DOWN] = dp[row][col][LEFT] = INF;
			
			if( maze[row][col] == START )
			{
				start.row = row;
				start.col = col;
				maze[row][col] = EMPTY;
				
				dp[row][col][UP] = dp[row][col][RIGHT] =
				dp[row][col][DOWN] = dp[row][col][LEFT] = 0;
			}
			
			if( maze[row][col] == FINISH )
			{
				finish.row = row;
				finish.col = col;
				maze[row][col] = EMPTY;
			}
		}
	}
}

int		find_shortest_path(Pos& start,Pos& finish)
{
	priority_queue<State>	pq;
	
	pq.push(make_pair(make_pair(0,UP),start));
	pq.push(make_pair(make_pair(0,RIGHT),start));
	pq.push(make_pair(make_pair(0,DOWN),start));
	pq.push(make_pair(make_pair(0,LEFT),start));
	
	int	ret;
	
	for(ret=INF;!pq.empty();)
	{
		int	current_num_of_steps,current_direction,current_row,current_col;
		int	adj_row,adj_col;
		
		current_num_of_steps = -pq.top().first.first;
		current_direction = pq.top().first.second;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row==finish.row && current_col==finish.col )
		{
			ret = current_num_of_steps;
			break;
		}
		
		Knight	k;
		Pos		p;
		
		// forward
		adj_row = current_row+adj[current_direction].d_row;
		adj_col = current_col+adj[current_direction].d_col;
		
		if( maze[adj_row][adj_col]!=WALL &&
			current_num_of_steps+1<dp[adj_row][adj_col][current_direction] )
		{
			dp[adj_row][adj_col][current_direction] = current_num_of_steps+1;
			
			k = make_pair(-(current_num_of_steps+1),current_direction);
			p = make_pair(adj_row,adj_col);
			
			pq.push(make_pair(k,p)); 
		}
		
		// right
		adj_row = current_row+adj[TURN_RIGHT(current_direction)].d_row;
		adj_col = current_col+adj[TURN_RIGHT(current_direction)].d_col;
		
		if( maze[adj_row][adj_col]!=WALL &&
			current_num_of_steps+1<dp[adj_row][adj_col][TURN_RIGHT(current_direction)] )
		{
			dp[adj_row][adj_col][TURN_RIGHT(current_direction)] = current_num_of_steps+1;
			
			k = make_pair(-(current_num_of_steps+1),TURN_RIGHT(current_direction));
			p = make_pair(adj_row,adj_col);
			
			pq.push(make_pair(k,p)); 
		}
	}
	
	return	ret;	
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		Pos	s,f;
		
		input(s,f);
		cout<<find_shortest_path(s,f)<<'\n';
	}
	
	return	0;
}
