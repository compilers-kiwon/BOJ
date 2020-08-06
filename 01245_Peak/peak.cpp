#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_DIR		8

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Pos;	
typedef	vector<Pos>		Peak;

#define	row	first
#define	col	second

int				N,M,map[MAX_SIZE][MAX_SIZE],peak_group[MAX_SIZE][MAX_SIZE];
bool			visited[MAX_SIZE][MAX_SIZE];
vector<Peak>	peak_vec;

void	find_peak(int s_row,int s_col)
{
	queue<Pos>	peak_q;
	Peak		p;
	int&		peak_height = map[s_row][s_col];
	
	visited[s_row][s_col] = true;
	peak_q.push(make_pair(s_row,s_col));
	p.push_back(make_pair(s_row,s_col));
	
	for(;!peak_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = peak_q.front().row;
		current_col = peak_q.front().col;
		
		peak_q.pop();
		
		for(int d=0;d<MAX_DIR;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) )
			{
				if( visited[adj_row][adj_col]==false && peak_height==map[adj_row][adj_col] )
				{
					visited[adj_row][adj_col] = true;
					peak_q.push(make_pair(adj_row,adj_col));
					p.push_back(make_pair(adj_row,adj_col));
				}
			}	
		}	
	}
	
	peak_vec.push_back(p);	
}

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>map[i][j];
			peak_group[i][j] = -1;
		}
	}	
}

void	mark_peak_group(void)
{
	for(int i=0;i<peak_vec.size();i++)
	{
		Peak&	p = peak_vec[i];
		
		for(int j=0;j<p.size();j++)
		{
			int&	r = p[j].row;
			int&	c = p[j].col;
			
			peak_group[r][c] = i;
		}
	}
}

int		count_higher_peak(void)
{
	int	cnt;
	
	cnt = 0;
	
	for(int i=0;i<peak_vec.size();i++)
	{
		Peak&	p = peak_vec[i];
		bool	higher_flag;
		
		higher_flag = true;
		
		for(int j=0;j<p.size()&&higher_flag==true;j++)
		{
			int&	r = p[j].row;
			int&	c = p[j].col;
			
			for(int d=0;d<MAX_DIR&&higher_flag==true;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = r+adj[d].d_row;
				adj_col = c+adj[d].d_col;
				
				if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) &&
					peak_group[r][c]!=peak_group[adj_row][adj_col] )
				{
					if( map[r][c] < map[adj_row][adj_col] )
					{
						higher_flag = false;
					}
				}
			}
		}
		
		if( higher_flag == true )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if( map[i][j]>0 && visited[i][j]==false )
			{
				find_peak(i,j);
			}
		}
	}
	
	mark_peak_group();
	cout<<count_higher_peak()<<'\n';
	
	return	0;
}
