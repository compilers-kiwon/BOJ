#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(50+1)

int			N,M,shark_distance[MAX_SIZE][MAX_SIZE];

typedef	pair<int,int>	Shark;	// first:row, second:col

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

const struct{
	int d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	init(queue<Shark>& shark_q)
{
	cin>>N>>M;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			int	s;
			
			cin>>s;
			
			if( s == 1 )
			{
				shark_distance[row][col] = 0;
				shark_q.push(make_pair(row,col));
			}
			else
			{
				shark_distance[row][col] = 0x7FFFFFFF;
			}
		}
	}
}

void	update_distance(queue<Shark>& shark_q)
{
	for(int size=shark_q.size();size!=0;size=shark_q.size())
	{
		for(int i=1;i<=size;i++)
		{
			int	current_row,current_col,current_distance;
			
			current_row = shark_q.front().first;
			current_col = shark_q.front().second;
			current_distance = shark_distance[current_row][current_col];
			
			shark_q.pop();
			
			for(int d=UP;d<=UP_LEFT;d++)
			{
				int	adj_row,adj_col;
				
				adj_row = current_row+adj[d].d_row;
				adj_col = current_col+adj[d].d_col;
				
				if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,M) )
				{
					int&	adj_distance = shark_distance[adj_row][adj_col];
					
					if( current_distance+1 < adj_distance )
					{
						adj_distance = current_distance+1;
						shark_q.push(make_pair(adj_row,adj_col));
					}
				}
			}
		}
	}
}

int		get_max_safe_distance(void)
{
	int	ret,row,col;
	
	for(ret=0,row=1;row<=N;row++)
	{
		for(col=1;col<=M;col++)
		{
			ret = max(ret,shark_distance[row][col]);
		}
	}
	
	return	ret;
}

int		main(void)
{
	queue<Shark>	shark_q;
	
	init(shark_q);
	update_distance(shark_q);
	
	cout<<get_max_safe_distance()<<'\n';
	
	return	0;
}
