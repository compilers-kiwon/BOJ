#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

#define	IN_AIR	0
#define	CHEESE	1
#define	AIR		2

typedef	pair<int,int>		RowCol;

int		N,M,c[MAX_SIZE][MAX_SIZE],num_of_adj_air[MAX_SIZE][MAX_SIZE];

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

const struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

void	init(queue<RowCol>& cq)
{
	//cin.sync_with_stdio(false);
	
	cin>>N>>M;
	
	queue<RowCol>	cheese_q;
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>c[i][j];
			
			if( c[i][j] == CHEESE )
			{
				cheese_q.push(make_pair(i,j));
			}
		}
	}
	
	queue<RowCol>	air_q;
	
	air_q.push(make_pair(1,1));
	c[1][1] = AIR;
	
	while( !air_q.empty() )
	{
		int	current_air_row,current_air_col;
		
		current_air_row = air_q.front().first;
		current_air_col = air_q.front().second;
		
		air_q.pop();
		
		for(int i=UP;i<=RIGHT;i++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_air_row+adj[i].d_row;
			adj_col = current_air_col+adj[i].d_col;
			
			if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) && c[adj_row][adj_col]==0 )
			{
				c[adj_row][adj_col] = AIR;
				air_q.push(make_pair(adj_row,adj_col));
			}
		}
	}
	
	while( !cheese_q.empty() )
	{
		int	current_cheese_row,current_cheese_col;
		
		current_cheese_row = cheese_q.front().first;
		current_cheese_col = cheese_q.front().second;
		
		cheese_q.pop();
		
		int	cnt,d;
		
		for(cnt=0,d=UP;d<=RIGHT;d++)
		{
			int	adj_row,adj_col;
			
			adj_row = current_cheese_row+adj[d].d_row;
			adj_col = current_cheese_col+adj[d].d_col;
			
			if( c[adj_row][adj_col] == AIR )
			{
				cnt++;
			}
		}
		num_of_adj_air[current_cheese_row][current_cheese_col] = cnt;
		cq.push(make_pair(current_cheese_row,current_cheese_col));
	}
}

void	make_air(int row,int col)
{
	c[row][col] = AIR;
	
	for(int d=UP;d<=RIGHT;d++)
	{
		int	adj_row,adj_col;
		
		adj_row = row+adj[d].d_row;
		adj_col = col+adj[d].d_col;
		
		if( c[adj_row][adj_col] == CHEESE )
		{
			num_of_adj_air[adj_row][adj_col]++;
		}
		else if( c[adj_row][adj_col] == IN_AIR )
		{
			make_air(adj_row,adj_col);
		}
	}
}

int		melt(queue<RowCol>& cq)
{
	int	time;
	
	for(time=0;!cq.empty();time++)
	{
		queue<RowCol>	will_melt;
		
		for(int i=1,to=cq.size();i<=to;i++)
		{
			int		row,col;
			
			row = cq.front().first;
			col = cq.front().second;
			
			cq.pop();
			
			int&	num_of_air = num_of_adj_air[row][col];
			
			if( num_of_air >= 2 )
			{
				will_melt.push(make_pair(row,col));
			}
			else
			{
				cq.push(make_pair(row,col));
			}
		}
		
		while( !will_melt.empty() )
		{
			int				row,col;
			queue<RowCol>	in_air;
			
			row = will_melt.front().first;
			col = will_melt.front().second;
			
			will_melt.pop();
			
			c[row][col] = AIR;
			
			for(int d=UP;d<=RIGHT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = row+adj[d].d_row;
				adj_col = col+adj[d].d_col;
				
				num_of_adj_air[adj_row][adj_col]++;
				
				if( c[adj_row][adj_col] == IN_AIR )
				{
					make_air(adj_row,adj_col);
				}
			}
		}
/*		
		cout<<'\n';
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cout<<c[i][j]<<' ';
			}
			cout<<'\n';
		}
		getchar();
*/
	}
	
	return	time;
}

int		main(void)
{
	queue<RowCol>	cq;
	
	init(cq);
	cout<<melt(cq)<<'\n';
	
	return	0;
}
