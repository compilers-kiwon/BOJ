#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	ROW_SIZE	12
#define	COL_SIZE	6

#define	NUM_OF_PUYO_TO_BE_CRASHED	4

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	RED		'R'
#define	GREEN	'G'
#define	BLUE	'B'
#define	PURPLE	'P'
#define	YELLOW	'Y'
#define	EMPTY	'.'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	RowCol;

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

char	map[ROW_SIZE+1][COL_SIZE+2];
bool	visited[ROW_SIZE+1][COL_SIZE+1];

bool	remove(int row,int col,char color)
{
	queue<RowCol>	puyo_q;
	vector<RowCol>	to_be_removed;
	
	visited[row][col] = true;
	puyo_q.push(make_pair(row,col));
	to_be_removed.push_back(make_pair(row,col));
	
	while( !puyo_q.empty() )
	{
		int	current_row,current_col;
		
		current_row = puyo_q.front().first;
		current_col = puyo_q.front().second;
		
		puyo_q.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( IN_RANGE(1,adj_row,ROW_SIZE) && IN_RANGE(1,adj_col,COL_SIZE) )
			{
				if( visited[adj_row][adj_col]==false && map[adj_row][adj_col]==color )
				{
					visited[adj_row][adj_col] = true;
					to_be_removed.push_back(make_pair(adj_row,adj_col));
					puyo_q.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
	
	bool	result;
	
	if( to_be_removed.size() >= NUM_OF_PUYO_TO_BE_CRASHED )
	{
		for(int i=0;i<to_be_removed.size();i++)
		{
			int&	r = to_be_removed[i].first;
			int&	c = to_be_removed[i].second;
			
			map[r][c] = EMPTY;
		}
		
		result = true;
	}
	else
	{
		result = false;
	}
	
	return	result;
}

void	fill_visited(bool flag)
{
	for(int row=1;row<=ROW_SIZE;row++)
	{
		for(int col=1;col<=COL_SIZE;col++)
		{
			visited[row][col] = flag;
		}
	}
}

void	update(void)
{
	for(int col=1;col<=COL_SIZE;col++)
	{
		for(int row=ROW_SIZE;row>=1;row--)
		{
			if( map[row][col] == EMPTY )
			{
				int	not_empty_row;
				
				for(not_empty_row=row-1;not_empty_row>=1&&map[not_empty_row][col]==EMPTY;not_empty_row--);
				
				if( not_empty_row == 0 )
				{
					break;
				}
				else
				{
					swap(map[row][col],map[not_empty_row][col]);
				}
			}
		}
	}
}

int		play_game(void)
{
	int		cnt,row,col;

	for(cnt=0;;cnt++)
	{
		bool	flag;
		
		fill_visited(false);
		flag = false;
		
		for(row=1;row<=ROW_SIZE;row++)
		{
			for(col=1;col<=COL_SIZE;col++)
			{
				if( map[row][col]!=EMPTY && visited[row][col]==false )
				{
					flag |= remove(row,col,map[row][col]);
				}
			}
		}
		
		if( flag == false )
		{
			break;
		}
		
		update();
	}
	
	return	cnt;
}

int		main(void)
{
	for(int row=1;row<=ROW_SIZE;row++)
	{
		scanf("%s",&map[row][1]);
	}
	
	printf("%d\n",play_game());
	
	return	0;
}
