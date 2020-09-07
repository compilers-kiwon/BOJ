#include	<iostream>
#include	<vector>
#include	<stack>

using namespace	std;

#define	MAX_SIZE	(666+1)
#define	MAX_DIR		8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

int		N;
bool	visited[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;
typedef	pair<int,Pos>	State;

void	dfs(int row,int col,vector<Pos>& p)
{
	for(int d=0;d<MAX_DIR;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
		{
			if( visited[adj_row][adj_col] == false )
			{
				visited[adj_row][adj_col] = true;
				p.push_back(make_pair(adj_row,adj_col));
				dfs(adj_row,adj_col,p);
			}
		}
	}
}

int		main(void)
{
	int				row,col;
	vector<Pos>		p;
	stack<State>	st;
	
	cin>>N>>row>>col;
	
	visited[row][col] = true;
	st.push(make_pair(-1,make_pair(row,col)));
	
	for(;!st.empty();)
	{
		int	d,row,col;
		int	adj_row,adj_col;
			
		d = st.top().first+1;
		row = st.top().second.first;
		col = st.top().second.second;
		
		st.pop();
		
		for(;d<MAX_DIR;d++)
		{
			adj_row = row+adj[d].d_row;
			adj_col = col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
			{
				if( visited[adj_row][adj_col] == false )
				{
					visited[adj_row][adj_col] = true;
					p.push_back(make_pair(adj_row,adj_col));
					
					break;
				}
			}
		}
		
		if( d != MAX_DIR )
		{
			st.push(make_pair(d,make_pair(row,col)));
			st.push(make_pair(-1,make_pair(adj_row,adj_col)));
		}
	}
	
	if( p.size() != N*N-1 )
	{
		cout<<"-1 -1\n";
	}
	else
	{
	/*	cout<<row<<' '<<col<<'\n';
		
		for(int i=0;i<p.size();i++)
		{
			cout<<p[i].first<<' '<<p[i].second<<'\n';
		}*/
	}
	cout<<"N*N="<<N*N<<",visited="<<p.size()<<'\n';
	return	0;
}
