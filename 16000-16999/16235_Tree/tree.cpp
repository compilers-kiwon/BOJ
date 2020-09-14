#include	<iostream>
#include	<deque>

using namespace	std;

#define	MAX_SIZE	(10+1)

#define	UP			0
#define	UP_RIGHT	1
#define	RIGHT		2
#define	DOWN_RIGHT	3
#define	DOWN		4
#define	DOWN_LEFT	5
#define	LEFT		6
#define	UP_LEFT		7
#define	MAX_DIR		8

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_FARM_INFO	Farm;
struct	_FARM_INFO
{
	int			nu;
	deque<int>	alive_tree;
	deque<int>	dead_tree;
};

const	struct{
	int	d_row,d_col;
} adj[MAX_DIR] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int		N,M,K,A[MAX_SIZE][MAX_SIZE];
Farm	farm[MAX_SIZE][MAX_SIZE];

void	do_spring(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			deque<int>&	tree = farm[row][col].alive_tree;
			int&		nu_of_cell = farm[row][col].nu;
			
			for(int i=1,to=tree.size();i<=to;i++)
			{
				int	age_of_current_tree;
				
				age_of_current_tree = tree.front();
				tree.pop_front();
				
				if( nu_of_cell >= age_of_current_tree )
				{
					nu_of_cell -= age_of_current_tree;
					tree.push_back(age_of_current_tree+1);
				}
				else
				{
					farm[row][col].dead_tree.push_back(age_of_current_tree);
				}
			}
		}
	}
}

void	do_summer(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			deque<int>&	tree = farm[row][col].dead_tree;
			int&		nu_of_cell = farm[row][col].nu;
			
			while( !tree.empty() )
			{
				int	age;
				
				age = tree.front();
				tree.pop_front();
				nu_of_cell += age/2;
			}
		}
	}
}

void	do_fall(void)
{
	int	num_of_new_tree[MAX_SIZE][MAX_SIZE];
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			num_of_new_tree[row][col] = 0;
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			deque<int>&	tree = farm[row][col].alive_tree;
			
			for(int i=1,to=tree.size();i<=to;i++)
			{
				int	age;
				
				age = tree.front();
				tree.pop_front();
				tree.push_back(age);
				
				if( age%5 != 0 )
				{
					continue;
				}
				
				for(int d=UP;d<=UP_LEFT;d++)
				{
					int	adj_row,adj_col;
					
					adj_row = row+adj[d].d_row;
					adj_col = col+adj[d].d_col;
					
					if( IN_RANGE(1,adj_row,N) && IN_RANGE(1,adj_col,N) )
					{
						num_of_new_tree[adj_row][adj_col]++;
					}
				}
			}
		}
	}
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			if( num_of_new_tree[row][col] != 0 )
			{
				deque<int>&	tree = farm[row][col].alive_tree;
				
				for(int i=1;i<=num_of_new_tree[row][col];i++)
				{
					tree.push_front(1);
				}
			}
		}
	}
}

void	do_winter(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			farm[row][col].nu += A[row][col];
		}
	}	
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>M>>K;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>A[row][col];
			farm[row][col].nu = 5;
		}
	}
	
	for(int i=1;i<=M;i++)
	{
		int	x,y,z;
		
		cin>>y>>x>>z;
		farm[y][x].alive_tree.push_back(z);
	}
	
	for(int i=1;i<=K;i++)
	{
		do_spring();
		do_summer();
		do_fall();
		do_winter();
	}
	
	int	cnt;
	
	cnt = 0;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cnt += farm[row][col].alive_tree.size();
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}
