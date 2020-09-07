#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	125

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

const	struct{
	int	d_row,d_col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>		RowCol;
typedef	pair<int,RowCol>	State;	// first:current_ruppe

int	cave[MAX_SIZE][MAX_SIZE],dp[MAX_SIZE][MAX_SIZE];

void	find_min_rupee(int size)
{
	priority_queue<State>	pq;
	
	State	s;
	
	s.first = -dp[0][0];
	s.second = make_pair(0,0);
	
	pq.push(s);
	
	while( !pq.empty() )
	{
		int	current_rupee,current_row,current_col;
		
		current_rupee = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		if( current_row == size && current_col == size )
		{
			continue;
		}
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	next_row,next_col,next_dp;
			
			next_row = current_row+move_dir[i].d_row;
			next_col = current_col+move_dir[i].d_col;
			
			if( IN_RANGE(0,next_row,size) && IN_RANGE(0,next_col,size) )
			{
				next_dp = current_rupee+cave[next_row][next_col];
				
				if( next_dp < dp[next_row][next_col] )
				{
					dp[next_row][next_col] = next_dp;
					
					s.first = -next_dp;
					s.second.first = next_row;
					s.second.second = next_col;
					
					pq.push(s);
				}
			}
		}
	}
}

int		main(void)
{	
	for(int i=1;;i++)
	{
		int	N;
		
		scanf("%d",&N);
		
		if( N == 0 )
		{
			break;
		}
		
		for(int row=0;row<N;row++)
		{
			for(int col=0;col<N;col++)
			{
				scanf("%d",&cave[row][col]);
				dp[row][col] = 0x7FFFFFFF;
			}
		}
		
		dp[0][0] = cave[0][0];
		find_min_rupee(N-1);
		printf("Problem %d: %d\n",i,dp[N-1][N-1]);
	}
	
	return	0;
}
