#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)
#define	MAX_DIR		8

#define	EMPTY		'.'

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))
#define	char2int(c)			((int)((c)-'0'))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef	pair<int,int>	Wall;

int			H,W;
char		castle[MAX_SIZE][MAX_SIZE+1];
int			num_of_adj_empty[MAX_SIZE][MAX_SIZE];
queue<Wall>	wall_queue;
int			current_queue;

int	get_cnt_of_adj_empty(int row,int col)
{
	int	cnt,i;
	
	for(i=cnt=0;i<MAX_DIR;i++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[i].d_row;
		adj_col = col+adj[i].d_col;
		
		if( 	castle[adj_row][adj_col] == EMPTY )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int	get_cnt_of_wave(void)
{
	int	cnt;
		
	for(cnt=0;!wall_queue.empty();cnt++)
	{
		for(int queue_size=wall_queue.size(),i=1;i<=queue_size;i++)
		{
			Wall	wall_to_be_removed;
			
			wall_to_be_removed = wall_queue.front();
			wall_queue.pop();
			
			
			int&	row = wall_to_be_removed.first;
			int&	col = wall_to_be_removed.second;
			
			for(int j=0;j<MAX_DIR;j++)
			{
				int		adj_row,adj_col;
				
				adj_row = row+adj[j].d_row;
				adj_col = col+adj[j].d_col;
				
				num_of_adj_empty[adj_row][adj_col]++;
					
				if( castle[adj_row][adj_col] != EMPTY && num_of_adj_empty[adj_row][adj_col] == char2int(castle[adj_row][adj_col]) )
				{
					wall_queue.push(make_pair(adj_row,adj_col));
				}
			}
		}
	}
	
	return	cnt;
}

int	main(void)
{
	cin>>H>>W;
	
	for(int row=1;row<=H;row++)
	{
		scanf("%s",&castle[row][1]);
	}
	
	for(int row=2;row<H;row++)
	{
		for(int col=2;col<W;col++)
		{
			num_of_adj_empty[row][col] = get_cnt_of_adj_empty(row,col);
				
			if( castle[row][col] != EMPTY && num_of_adj_empty[row][col] >= char2int(castle[row][col]) )
			{
				wall_queue.push(make_pair(row,col));
			} 
		}
	}
	
	cout<<get_cnt_of_wave()<<endl;
	
	return	0;
}
