#include	<iostream>
#include	<queue>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	50
#define	INF			0x7FFFFFFF

typedef	pair<int,int>	Pos;	// first:row, second:col

int		N,M;
char	grid[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	input(void)
{
	cin>>N>>M;
	
	for(int row=0;row<N;row++)
	{
		cin>>&grid[row][0];
	}
}
int		get_min_distance(vector<Pos>& s1,vector<Pos>& s2)
{
	int	min_distance;
	
	min_distance = INF;
	
	for(int i=0;i<s1.size();i++)
	{
		for(int j=0;j<s2.size();j++)
		{
			Pos&	p1 = s1[i];
			Pos&	p2 = s2[j];
			int		d;
			
			d = abs(p1.first-p2.first)+abs(p1.second-p2.second);
			min_distance = min(min_distance,d);
		}
	}
	
	return	min_distance-1;
}

void	find_spot(int s_row,int s_col,vector<Pos>& spot)
{
	queue<Pos>	pos_q;
	
	visited[s_row][s_col] = true;
	pos_q.push(make_pair(s_row,s_col));
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col,cnt;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;
		
		pos_q.pop();
		cnt = 0;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(0,adj_row,N-1) && IN_RANGE(0,adj_col,M-1) )
			{
				if( grid[adj_row][adj_col]=='X' && visited[adj_row][adj_col]==false )
				{
					visited[adj_row][adj_col] = true;
					pos_q.push(make_pair(adj_row,adj_col));
					cnt++;
				}
			}
		}
		
		if( cnt != MAX_DIR )
		{
			spot.push_back(make_pair(current_row,current_col));
		}
	}
}

int		main(void)
{
	vector<Pos>	spot[2];
	int			spot_ptr;
	
	input();
	spot_ptr = 0;
	
	for(int row=0;row<N&&spot_ptr!=2;row++)
	{
		for(int col=0;col<M&&spot_ptr!=2;col++)
		{
			if( grid[row][col]=='X' && visited[row][col]==false )
			{
				find_spot(row,col,spot[spot_ptr]);
				spot_ptr++;
			}
		}
	}
	
	cout<<get_min_distance(spot[0],spot[1])<<'\n';
	
	return	0;
}
