#include	<iostream>
#include	<vector>
#include	<queue>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(100+1)

char	picture[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int		N;

#define	IN_RANGE(MIN,N,MAX)	((MIN)<=(N) && (N)<=(MAX))

#define	RED		'R'
#define	GREEN	'G'
#define	BLUE	'B'

vector< pair<int,int> >	greens,reds;

void	check_adj_color(char color,int row,int col)
{
	queue< pair<int,int> > cq;
	
	visited[row][col] = true;
	cq.push(make_pair(row,col));
	
	while( cq.size() != 0 )
	{
		int	current_row,current_col;
		
		current_row = cq.front().first;
		current_col = cq.front().second;
		cq.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+move_dir[i].row;
			adj_col = current_col+move_dir[i].col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
			{
				if( picture[adj_row][adj_col] == color && visited[adj_row][adj_col] == false )
				{
					visited[adj_row][adj_col] = true;
					cq.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
}

int		main(void)
{
	map<char,int>	cnt;
	
	cnt[RED] = cnt[GREEN] = cnt[BLUE] = 0;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&picture[i][1]);
		
		for(int j=1;j<=N;j++)
		{
			if( picture[i][j] == GREEN )
			{
				greens.push_back(make_pair(i,j));				
			}
			else if( picture[i][j] == RED )
			{
				reds.push_back(make_pair(i,j));
			}
			visited[i][j] = false;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if( visited[i][j] == false )
			{
				++cnt[picture[i][j]];
				check_adj_color(picture[i][j],i,j);
			}
		}
	}
	
	printf("%d ",cnt[RED]+cnt[GREEN]+cnt[BLUE]);
	
	for(int i=0;i<reds.size();i++)
	{
		visited[reds[i].first][reds[i].second] = false;
	}
	
	for(int i=0;i<greens.size();i++)
	{
		visited[greens[i].first][greens[i].second] = false;
		picture[greens[i].first][greens[i].second] = RED;
	}
	
	cnt[RED] = 0;
	
	for(int i=0;i<reds.size();i++)
	{
		if( visited[reds[i].first][reds[i].second] == false )
		{
			++cnt[RED];
			check_adj_color(RED,reds[i].first,reds[i].second);
		}
	}
	
	for(int i=0;i<greens.size();i++)
	{
		if( visited[greens[i].first][greens[i].second] == false )
		{
			++cnt[RED];
			check_adj_color(RED,greens[i].first,greens[i].second);
		}
	}
	printf("%d\n",cnt[RED]+cnt[BLUE]);
	
	return	0;
}
