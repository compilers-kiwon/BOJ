#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Pos;	// first:row,second:col

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int			N,M,num_of_empty,visited_cnt;
int			grid[MAX_SIZE][MAX_SIZE];
int			visited[MAX_SIZE][MAX_SIZE];
vector<Pos>	virus_pos;

#define	EMPTY	0
#define	WALL	1
#define	VIRUS	2

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>grid[row][col];
			
			switch(grid[row][col])
			{
				case	VIRUS:
					grid[row][col] = EMPTY;
					virus_pos.push_back(make_pair(row,col));
				case	EMPTY:
					num_of_empty++;
					break;
				case	WALL:
				default:
					// do nothing
					break;
			}
		}
	}
}

int		bfs(vector<int>& virus)
{
	queue<Pos>	virus_q;
	int			num_of_inspected,t;
	
	visited_cnt++;
	
	for(int i=0;i<M;i++)
	{
		virus_q.push(virus_pos[virus[i]]);
		
		int&	row = virus_pos[virus[i]].first;
		int&	col = virus_pos[virus[i]].second;
		
		visited[row][col] = visited_cnt;
	}
	
	num_of_inspected = M;
	
	for(t=0;num_of_inspected!=num_of_empty&&!virus_q.empty();t++)
	{
		for(int i=1,size=virus_q.size();i<=size;i++)
		{
			int	current_virus_row,current_virus_col;
			
			current_virus_row = virus_q.front().first;
			current_virus_col = virus_q.front().second;
			
			virus_q.pop();
			
			for(int d=UP;d<MAX_DIR;d++)
			{
				int	adj_virus_row,adj_virus_col;
				
				adj_virus_row = current_virus_row+adj[d].d_row;
				adj_virus_col = current_virus_col+adj[d].d_col;
				
				if( !IN_RANGE(1,adj_virus_row,N) || !IN_RANGE(1,adj_virus_col,N)
					|| grid[adj_virus_row][adj_virus_col] == WALL
					|| visited[adj_virus_row][adj_virus_col] == visited_cnt )
				{
					continue;
				}
				
				num_of_inspected++;
				visited[adj_virus_row][adj_virus_col] = visited_cnt;				
				virus_q.push(make_pair(adj_virus_row,adj_virus_col));
			}
		}
	}
	
	return	((num_of_inspected==num_of_empty)?t:INF);
}

void	select_virus(vector<int>& selected_virus,int current_virus,int& min_time)
{
	if( selected_virus.size()==M || current_virus==virus_pos.size() )
	{
		if( selected_virus.size() == M )
		{
			min_time = min(min_time,bfs(selected_virus));
		}
		
		return;
	}
	
	selected_virus.push_back(current_virus);
	select_virus(selected_virus,current_virus+1,min_time);
	selected_virus.pop_back();
	
	select_virus(selected_virus,current_virus+1,min_time);
}

int		simulate(void)
{
	int			ret;
	vector<int>	selected_virus;
	
	ret = INF;
	select_virus(selected_virus,0,ret);
	
	return	((ret==INF)?-1:ret);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	cout<<simulate()<<'\n';
	
	return	0;
}
