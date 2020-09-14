#include	<iostream>
#include	<queue>

using namespace	std;

#define	ROW_SIZE	9
#define	COL_SIZE	8

#define	UP			{-1,0}
#define	UP_RIGHT	{-1,1}
#define	RIGHT		{0,1}
#define	DOWN_RIGHT	{1,1}
#define	DOWN		{1,0}
#define	DOWN_LEFT	{1,-1}
#define	LEFT		{0,-1}
#define	UP_LEFT		{-1,-1}

#define	STEP_LEN	3
#define	MAX_DIR		8

typedef	pair<int,int>	State;

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR][STEP_LEN] = {{UP,UP_LEFT,UP_LEFT},
				  {UP,UP_RIGHT,UP_RIGHT},
				  {RIGHT,UP_RIGHT,UP_RIGHT},
				  {RIGHT,DOWN_RIGHT,DOWN_RIGHT},
				  {DOWN,DOWN_RIGHT,DOWN_RIGHT},
				  {DOWN,DOWN_LEFT,DOWN_LEFT},
				  {LEFT,UP_LEFT,UP_LEFT},
				  {LEFT,DOWN_LEFT,DOWN_LEFT}};

int		R1,C1,R2,C2;
bool	visited[ROW_SIZE+1][COL_SIZE+1];

#define	IN_RANGE(MIN,n,MAX)				((MIN)<=(n)&&(n)<=(MAX))
#define	IS_SAME(row1,col1,row2,col2)	((row1)==(row2)&&(col1)==(col2))

int		move(void)
{
	int				cnt;
	queue<State>	state_q;
	
	state_q.push(make_pair(R1,C1));
	visited[R1][C1] = true;
	
	for(cnt=0;!state_q.empty();cnt++)
	{
		for(int i=1,to=state_q.size();i<=to;i++)
		{
			int	current_row,current_col;
			
			current_row = state_q.front().first;
			current_col = state_q.front().second;
			
			state_q.pop();
			
			if( current_row==R2 && current_col==C2 )
			{
				return	cnt;
			}
			
			for(int d=0;d<MAX_DIR;d++)
			{
				bool	flag;
				int		adj_row,adj_col;
				
				flag = true;
				adj_row = current_row;
				adj_col = current_col;
				
				// step 1
				adj_row += adj[d][0].d_row;
				adj_col += adj[d][0].d_col;
				
				if( IN_RANGE(0,adj_row,ROW_SIZE) && IN_RANGE(0,adj_col,COL_SIZE) 
					&& IS_SAME(adj_row,adj_col,R2,C2)==false )
				{
					// step 2
					{
						adj_row += adj[d][1].d_row;
						adj_col += adj[d][1].d_col;
						
						if( IN_RANGE(0,adj_row,ROW_SIZE) && IN_RANGE(0,adj_col,COL_SIZE)
							&& IS_SAME(adj_row,adj_col,R2,C2)==false )
						{
							// step 3
							adj_row += adj[d][2].d_row;
							adj_col += adj[d][2].d_col;
							
							if( IN_RANGE(0,adj_row,ROW_SIZE) && IN_RANGE(0,adj_col,COL_SIZE)
								&& visited[adj_row][adj_col]==false )
							{
								visited[adj_row][adj_col] = true;
								state_q.push(make_pair(adj_row,adj_col));
							}
						}
					}
				}
			}
		}
	}
	
	return	-1;
}

int	main(void)
{
	cin>>R1>>C1>>R2>>C2;
	cout<<move()<<'\n';
	
	return	0;
}
