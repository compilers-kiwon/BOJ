#include	<iostream>
#include	<queue>
#include	<vector>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(50+1)

#define	LAND		'x'
#define	WATER		'.'
#define	INIT_HEIGHT	-1

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	// first:row,second:col
typedef	vector<Pos>		Island;

int		N,M,cnt[MAX_SIZE*MAX_SIZE];
char	grid[MAX_SIZE+1][MAX_SIZE+1];
bool	visited[MAX_SIZE+1][MAX_SIZE+1];


void	find_island(int s_row,int s_col,Island& island)
{
	queue<Pos>	q;
	
	visited[s_row][s_col] = true;
	q.push(make_pair(s_row,s_col));	
	
	for(;!q.empty();)
	{
		int	current_row,current_col;
		
		current_row = q.front().first;
		current_col = q.front().second;
		
		q.pop();
		
		for(int d_row=-1;d_row<=1;d_row++)
		{
			for(int d_col=-1;d_col<=1;d_col++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+d_row;
				adj_col = current_col+d_col;
				
				if( visited[adj_row][adj_col]==true || grid[adj_row][adj_col]==WATER )
				{
					continue;
				}
				
				q.push(make_pair(adj_row,adj_col));
				island.push_back(make_pair(adj_row,adj_col));
	
				visited[adj_row][adj_col] = true;
			}
		}
	}
}

int		get_height(Island& p)
{
	int				ret;
	queue<Pos>		pos_q;
	vector<Island>	island;
	
	for(int i=0;i<p.size();i++)
	{
		pos_q.push(p[i]);
	}
	
	for(;!pos_q.empty();)
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
			
			if( !IN_RANGE(0,adj_row,N+1) || !IN_RANGE(0,adj_col,M+1) )
			{
				continue;
			}
			
			if( visited[adj_row][adj_col] == true )
			{
				continue;
			}
			
			if( grid[adj_row][adj_col] == WATER )
			{
				visited[adj_row][adj_col] = true;
				pos_q.push(make_pair(adj_row,adj_col));
			}
			else
			{
				Island	i;
				
				find_island(adj_row,adj_col,i);
				island.push_back(i);
			}
		}
	}
	
	ret = 0;
	
	for(int i=0;i<island.size();i++)
	{
		ret = max(ret,get_height(island[i])+1);
	}

	cnt[ret]++;
	
	return	ret;
}

void	input(Island& p)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		cin>>&grid[row][1];
	}
	
	for(int col=0;col<=M+1;col++)
	{
		p.push_back(make_pair(0,col));
		p.push_back(make_pair(N+1,col));
		
		visited[0][col] = visited[N+1][col] = true;
	}
	
	for(int row=1;row<=N;row++)
	{
		p.push_back(make_pair(row,0));
		p.push_back(make_pair(row,M+1));
		
		visited[row][0] = visited[row][M+1] = true;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	Island		init;
	vector<int>	result;
	
	input(init);
	get_height(init);
	
	for(int h=0;cnt[h]!=0;h++)
	{
		result.push_back(cnt[h]);
	}
	
	result.pop_back();
	
	if( result.empty() )
	{
		cout<<"-1\n";
	}
	else
	{
		for(int i=0;i<result.size();i++)
		{
			cout<<result[i]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}
