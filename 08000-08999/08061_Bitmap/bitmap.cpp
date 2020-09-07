#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(182+1)

typedef	pair<int,int>	Pos;

#define	WHITE	1
#define	BLACK	0

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	input(int* row_size,int* col_size,
			  queue<Pos>& pos_q,vector<int>* distance_table)
{
	scanf("%d %d",row_size,col_size);
	
	for(int row=1;row<=*row_size;row++)
	{
		distance_table[row].resize(*col_size+1,-1);
		
		for(int col=1;col<=*col_size;col++)
		{
			int	n;
			
			scanf("%1d",&n);
			
			if( n == WHITE )
			{
				pos_q.push(make_pair(row,col));
				distance_table[row][col] = 0;
			}
		}
	}
}

void	build_distance_table(int row_size,int col_size,
							 queue<Pos>& pos_q,vector<int>* distance_table)
{
	for(int i=1;!pos_q.empty();i++)
	{
		for(int j=1,size=pos_q.size();j<=size;j++)
		{
			int	current_row,current_col;
			
			current_row = pos_q.front().first;
			current_col = pos_q.front().second;
			
			pos_q.pop();
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( IN_RANGE(1,adj_row,row_size) && IN_RANGE(1,adj_col,col_size) )
				{
					if( distance_table[adj_row][adj_col] == -1 )
					{
						distance_table[adj_row][adj_col] = i;
						pos_q.push(make_pair(adj_row,adj_col));
					}
				}
			}
		}
	}
}

int		main(void)
{
	int			n,m;
	vector<int>	distance_table[MAX_SIZE];
	queue<Pos>	pos_q;
	
	input(&n,&m,pos_q,distance_table);
	build_distance_table(n,m,pos_q,distance_table);
	
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=m;col++)
		{
			printf("%d ",distance_table[row][col]);
		}
		puts("");
	}
	
	return	0;
}
