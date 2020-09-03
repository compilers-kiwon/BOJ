#include	<iostream>
#include	<queue>

using namespace	std;

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	cnt,row,col;
};

#define	MAX_NUM_OF_POINT	10
#define	MAX_SIZE			(1000+1)

typedef	pair<int,int>	RowCol;

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	WALL	'X'
#define	EMPTY	'.'

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
#define	char2int(c)			((int)((c)-'0'))

char	map[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];
int		H,W,N;
RowCol	point_info[MAX_NUM_OF_POINT];

int	find_min_cnt(RowCol& from,RowCol& to)
{
	State			s;
	queue<State>	state_q;
	int				min_cnt;
	
	s.cnt = 0;
	s.row = from.first;
	s.col = from.second;
	visited[s.row][s.col] = true;
	
	state_q.push(s);
	
	while( state_q.size() != 0 )
	{
		State current,next;
		
		current = state_q.front();
		state_q.pop();
		
		if( current.row == to.first && current.col == to.second )
		{
			min_cnt = current.cnt;
			break;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col;
			
			next_row = current.row+adj[i].d_row;
			next_col = current.col+adj[i].d_col;
			
			if( IN_RANGE(1,next_row,H) && IN_RANGE(1,next_col,W) )
			{
				if( map[next_row][next_col] != WALL && visited[next_row][next_col] == false )
				{
					visited[next_row][next_col] = true;
					
					next.cnt = current.cnt+1;
					next.row = next_row;
					next.col = next_col;
					
					state_q.push(next);
				}
			}
		}
	}
	
	return	min_cnt;
}

void	input(void)
{
	scanf("%d %d %d",&H,&W,&N);
	
	for(int i=1;i<=H;i++)
	{
		scanf("%s",&map[i][1]);
		
		for(int j=1;j<=W;j++)
		{
			if( map[i][j] != EMPTY && map[i][j] != WALL )
			{
				if( IN_RANGE('1',map[i][j],'9') )
				{
					point_info[char2int(map[i][j])].first = i;
					point_info[char2int(map[i][j])].second = j;
				}
				else
				{
					point_info[0].first = i;
					point_info[0].second = j;
				}
			}
		}
	}
}

int		main(void)
{
	input();
	
	int	cnt,i;
	
	for(cnt=0,i=1;i<=N;i++)
	{
		for(int row=1;row<=H;row++)
		{
			for(int col=1;col<=W;col++)
			{
				visited[row][col] = false;
			}
		}
		
		cnt += find_min_cnt(point_info[i-1],point_info[i]);
	}
	
	printf("%d\n",cnt);
	
	return	0;
}
