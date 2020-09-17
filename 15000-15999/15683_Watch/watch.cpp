#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(8+1)

#define	CCTV_1		1
#define	CCTV_2		2
#define	CCTV_3		3
#define	CCTV_4		4
#define	CCTV_5		5
#define	MAX_CCTV	6

#define	UP		0
#define	RIGHT	1
#define	DOWN	2
#define	LEFT	3
#define	MAX_DIR	4

#define	ROTATE(d,r)	(((d)+(r))%MAX_DIR)

#define	EMPTY	0
#define	WALL	6
#define	WATCHED	7

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	is_cctv(n)			IN_RANGE(CCTV_1,n,CCTV_5)

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{0,1},{1,0},{0,-1}};

typedef	pair<int,int>	Pos;

int			N,M,grid[MAX_SIZE][MAX_SIZE],available_rotate[MAX_CCTV];
vector<int>	covered[MAX_CCTV];
vector<Pos>	cctv;

void	watch(int cctv_type,int num_of_rotate,vector<Pos>& w,int row,int col)
{
	vector<int>	rotated_cctv;
	
	for(int i=0;i<covered[cctv_type].size();i++)
	{
		int&	current = covered[cctv_type][i];
		
		rotated_cctv.push_back(ROTATE(current,num_of_rotate));
	}
	
	for(int i=0;i<rotated_cctv.size();i++)
	{
		for(int d=1;;d++)
		{
			int adj_row,adj_col;
			
			adj_row = row+adj[rotated_cctv[i]].d_row*d;
			adj_col = col+adj[rotated_cctv[i]].d_col*d;
		
			if( !IN_RANGE(1,adj_row,N) || !IN_RANGE(1,adj_col,M) )
			{
				break;
			}
			
			if( grid[adj_row][adj_col] == WALL )
			{
				break;
			}
			
			if( is_cctv(grid[adj_row][adj_col]) == true )
			{
				continue;
			}
			
			grid[adj_row][adj_col] += WATCHED;
			w.push_back(make_pair(adj_row,adj_col));
		}
	}
}

int		count_unwatched(void)
{
	int	ret;
	
	ret = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			if( grid[row][col] == EMPTY )
			{
				ret++;
			}
		}
	}
	
	return	ret;
}

void	place_cctv(int cctv_idx,int& min_num_of_unwatched)
{
	if( cctv_idx == cctv.size() )
	{
		min_num_of_unwatched = min(min_num_of_unwatched,count_unwatched());
		
		return;
	}
	
	int&	current_cctv_row = cctv[cctv_idx].first;
	int&	current_cctv_col = cctv[cctv_idx].second;
	int&	current_cctv_type = grid[current_cctv_row][current_cctv_col];
	
	for(int r=0;r<=available_rotate[current_cctv_type];r++)
	{
		vector<Pos>	current_watched;
		
		watch(current_cctv_type,r,current_watched,
			  current_cctv_row,current_cctv_col);
		
		place_cctv(cctv_idx+1,min_num_of_unwatched);
		
		for(int i=0;i<current_watched.size();i++)
		{
			int&	row = current_watched[i].first;
			int&	col = current_watched[i].second;
			
			grid[row][col] -= WATCHED;
		}
	}
}

void	input(void)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int&	cell = grid[row][col];
			
			cin>>cell;
			
			if( is_cctv(cell) == true )
			{
				cctv.push_back(make_pair(row,col));
			}
		}
	}
}

void	init(void)
{
	covered[CCTV_1].push_back(RIGHT);
	
	covered[CCTV_2].push_back(LEFT);
	covered[CCTV_2].push_back(RIGHT);
	
	covered[CCTV_3].push_back(UP);
	covered[CCTV_3].push_back(RIGHT);
	
	covered[CCTV_4].push_back(UP);
	covered[CCTV_4].push_back(LEFT);
	covered[CCTV_4].push_back(RIGHT);
	
	covered[CCTV_5].push_back(UP);
	covered[CCTV_5].push_back(LEFT);
	covered[CCTV_5].push_back(RIGHT);
	covered[CCTV_5].push_back(DOWN);
	
	available_rotate[CCTV_1] = 3;
	available_rotate[CCTV_2] = 1;
	available_rotate[CCTV_3] = 3;
	available_rotate[CCTV_4] = 3;
	available_rotate[CCTV_5] = 0;
}

int		main(void)
{
	init();
	input();
	
	int	min_num_of_unwatched;
	
	min_num_of_unwatched = 0x7FFFFFFF;
	place_cctv(0,min_num_of_unwatched);
	
	cout<<min_num_of_unwatched<<'\n';
	
	return	0;
}
