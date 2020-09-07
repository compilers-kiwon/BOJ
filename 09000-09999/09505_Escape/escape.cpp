#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(1000+1)

int		K,W,H,dp[MAX_SIZE][MAX_SIZE];
int		battleship[0x100];
char	map[MAX_SIZE][MAX_SIZE+1];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>		RowCol;
typedef	pair<int,RowCol>	Ship;

int		escape(int& s_row,int& s_col)
{
	priority_queue<Ship>	pq;
	
	for(int row=1;row<=H;row++)
	{
		for(int	col=1;col<=W;col++)
		{
			dp[row][col] = 0x7FFFFFFF;
		}
	}
	
	pq.push(make_pair(0,make_pair(s_row,s_col)));
	dp[s_row][s_col] = 0;
	
	while( !pq.empty() )
	{
		int	current_time,current_row,current_col;
		
		current_time = -pq.top().first;
		current_row = pq.top().second.first;
		current_col = pq.top().second.second;
		
		pq.pop();
		
		for(int d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_row+adj[d].d_row;
			adj_col = current_col+adj[d].d_col;
			
			if( !IN_RANGE(1,adj_row,H) || !IN_RANGE(1,adj_col,W) )
			{
				return	current_time;
			}
			
			char&	b = map[adj_row][adj_col];
			int		battle_end_time;
			
			battle_end_time = battleship[b]+current_time;
			
			if( battle_end_time < dp[adj_row][adj_col] )
			{
				dp[adj_row][adj_col] = battle_end_time;
				pq.push(make_pair(-battle_end_time,make_pair(adj_row,adj_col)));
			}
		}
	}
	
	return	0;
}
		
int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{	
		int		E_row,E_col;
		bool	found;
				
		scanf("%d %d %d",&K,&W,&H);
		getchar();
		
		for(int i=1;i<=K;i++)
		{
			char	n;
			int		a;
			
			scanf("%c %d",&n,&a);getchar();
			battleship[n] = a;
		}
		
		found = false;
		
		for(int i=1;i<=H;i++)
		{
			scanf("%s",&map[i][1]);
			
			if( found == false )
			{
				for(int j=1;j<=W;j++)
				{
					if( map[i][j] == 'E' )
					{
						E_row = i;
						E_col = j;
						found = true;
						
						break;
					}
				}
			}
		}
		
		printf("%d\n",escape(E_row,E_col));
		
		T--;
	}
	
	return	0;
}
