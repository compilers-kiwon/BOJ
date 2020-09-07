#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE			(700+1)
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		N,M,grid[MAX_SIZE][MAX_SIZE];
bool	visited[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Pos;		// first:row,second:col
typedef	pair<int,Pos>	Element;	// first:altitude,second:Pos

void	input(priority_queue<Element>& pq)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int&	altitude = grid[row][col];
			
			cin>>altitude;
			
			if( altitude != 0 )
			{
				pq.push(make_pair(altitude,make_pair(row,col)));
			}
			else
			{
				visited[row][col] = true;
			}
		}
	}
}

void	bfs(int s_row,int s_col)
{
	queue<Pos>	pos_q;
	
	visited[s_row][s_col] = true;
	pos_q.push(make_pair(s_row,s_col));
	
	for(;!pos_q.empty();)
	{
		int	current_row,current_col;
		
		current_row = pos_q.front().first;
		current_col = pos_q.front().second;

		pos_q.pop();
		
		for(int dy=-1;dy<=1;dy++)
		{
			for(int dx=-1;dx<=1;dx++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+dy;
				adj_col = current_col+dx;
				
				if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) 
					|| visited[adj_row][adj_col]==true )
				{
					continue;
				}
				
				int&	current_altitude = grid[current_row][current_col];
				int&	adj_altitude = grid[adj_row][adj_col];
				
				if( adj_altitude <= current_altitude )
				{
					visited[adj_row][adj_col] = true;
					pos_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

int		find_hilltop(priority_queue<Element>& pq)
{
	int	ret;
	
	for(ret=0;!pq.empty();)
	{
		int	row,col;
		
		row = pq.top().second.first;
		col = pq.top().second.second;
		
		pq.pop();
		
		if( visited[row][col] == false )
		{
			ret++;
			bfs(row,col);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	priority_queue<Element>	pq;
	
	input(pq);
	cout<<find_hilltop(pq)<<'\n';
	
	return	0;
}
