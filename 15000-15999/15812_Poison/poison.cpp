#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(20+1)

#define	VILLAGE	'1'
#define	EMPTY	'0'

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

#define	row		first
#define	col		second
	
char	map[MAX_SIZE][MAX_SIZE+1];
bool	visited[MAX_SIZE][MAX_SIZE];
int		N,M,num_of_village;

typedef	pair<int,int>	RowCol;

const struct{
	int	row,col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	poison(RowCol& s1,RowCol& s2)
{
	int				t,cnt_of_poisoned_village;
	queue<RowCol>	poison_q;
	
	visited[s1.row][s1.col] = visited[s2.row][s2.col] = true;
	
	poison_q.push(s1);
	poison_q.push(s2);
	
	for(t=cnt_of_poisoned_village=0;!poison_q.empty()&&cnt_of_poisoned_village!=num_of_village;t++)
	{
		for(int i=1,size=poison_q.size();i<=size;i++)
		{
			int	current_row,current_col;
			
			current_row = poison_q.front().row;
			current_col = poison_q.front().col;
			
			poison_q.pop();
			
			for(int j=UP;j<=RIGHT;j++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[j].row;
				adj_col = current_col+adj[j].col;
				
				if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) && visited[adj_row][adj_col] == false )
				{
					visited[adj_row][adj_col] = true;
					poison_q.push(make_pair(adj_row,adj_col));
					
					if( map[adj_row][adj_col] == VILLAGE )
					{
						++cnt_of_poisoned_village;
					}
				}
			}
			
			if( cnt_of_poisoned_village == num_of_village )
			{
				break;
			}
		}
	}
	
	return	t;
}

int	main(void)
{
	vector<RowCol>	empty;
	int				min_time;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&map[i][1]);
		
		for(int j=1;j<=M;j++)
		{
			if( map[i][j] == VILLAGE )
			{
				++num_of_village;
			}
			else
			{
				empty.push_back(make_pair(i,j));
			}
		}
	}
	
	min_time = 0x7FFFFFFF;
	
	for(int i=0;i<empty.size()-1;i++)
	{
		for(int j=i+1;j<empty.size();j++)
		{
			for(int row=1;row<=N;row++)
			{
				for(int col=1;col<=M;col++)
				{
					visited[row][col] = false;
				}
			}
			
			min_time = min(min_time,poison(empty[i],empty[j]));
		}
	}
	
	printf("%d\n",min_time);
	
	return	0;
}
