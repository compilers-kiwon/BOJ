#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

typedef	pair<int,int>	RowCol;
typedef	long long int	int64;

typedef	struct	_CELL_INFO	Cell;
struct	_CELL_INFO
{
	bool	visited,blocked[MAX_DIR];
	int64	num_of_cow;
};

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N,K,R;
Cell	cell[MAX_SIZE][MAX_SIZE];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>K>>R;
	
	for(int i=1;i<=R;i++)
	{
		int	r1,c1,r2,c2,big,small;
		
		cin>>r1>>c1>>r2>>c2;
		
		if( r1 == r2 )
		{
			big = max(c1,c2);
			small = min(c1,c2);
			
			cell[r1][small].blocked[RIGHT] = cell[r1][big].blocked[LEFT] = true;
		}
		else
		{
			big = max(r1,r2);
			small = min(r1,r2);
			
			cell[small][c1].blocked[DOWN] = cell[big][c1].blocked[UP] = true;
		}
	}
	
	for(int i=1;i<=K;i++)
	{
		int	r,c;
		
		cin>>r>>c;
		cell[r][c].num_of_cow = 1;
	}
}

int64	cnt_num_of_cow(int s_row,int s_col)
{
	queue<RowCol>	state;
	int64			cnt;
	
	state.push(make_pair(s_row,s_col));
	cnt = 0;
	cell[s_row][s_col].visited = true;
	
	while( !state.empty() )
	{
		int	current_row,current_col;
		
		current_row = state.front().first;
		current_col = state.front().second;
		
		state.pop();
		
		cnt += cell[current_row][current_col].num_of_cow;
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			if( cell[current_row][current_col].blocked[d] == true )
			{
				continue;
			}
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) && cell[adj_row][adj_col].visited==false )
			{
				cell[adj_row][adj_col].visited = true;
				state.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	init();
	
	vector<int64>	v;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			if( cell[row][col].visited == false )
			{
				v.push_back(cnt_num_of_cow(row,col));
			}
		}
	}
	
	int64	cnt;
	
	cnt = 0;
	
	for(int i=0;i<v.size()-1;i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			cnt += v[i]*v[j];
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
