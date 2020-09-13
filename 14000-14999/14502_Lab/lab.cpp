#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(8+1)

#define	EMPTY		0
#define	WALL		1
#define	VIRUS		2
#define	INFECTED	3

#define	UP		0
#define	DOWN	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef	pair<int,int>		RowCol;

int	lab[MAX_SIZE][MAX_SIZE];
int	N,M;

vector<RowCol>	virus;
vector<RowCol>	empty;

int	count_infection(void)
{
	int	cnt = 0;
	
	for(int i=0;i<virus.size();i++)
	{
		queue<RowCol>	infection_q;
		
		infection_q.push(virus[i]);
		
		while( infection_q.size() != 0 )
		{
			int current_virus_row,current_virus_col;
			
			current_virus_row = infection_q.front().first;
			current_virus_col = infection_q.front().second;
			infection_q.pop();
			
			for(int i=UP;i<=RIGHT;i++)
			{
				int	next_virus_row,next_virus_col;
				
				next_virus_row = current_virus_row+move_dir[i].row;
				next_virus_col = current_virus_col+move_dir[i].col;
				
				if( IN_RANGE(1,next_virus_row,N) && IN_RANGE(1,next_virus_col,M) )
				{
					if( lab[next_virus_row][next_virus_col] == EMPTY )
					{
						lab[next_virus_row][next_virus_col] = INFECTED;
						infection_q.push(make_pair(next_virus_row,next_virus_col));
						++cnt;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if( lab[i][j] == INFECTED )
			{
				lab[i][j] = EMPTY;
			} 
		}
	}
	
	return	cnt;
}

int	main(void)
{
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&lab[i][j]);
			
			if( lab[i][j] == EMPTY )
			{
				empty.push_back(make_pair(i,j));
			}
			else if( lab[i][j] == VIRUS )
			{
				virus.push_back(make_pair(i,j));
			}
		}
	}
	
	int		max_empty = 0;
	int		num_of_empty = empty.size();
	RowCol	e1,e2,e3;
		
	for(int i=0;i<num_of_empty-2;i++)
	{
		e1 = empty[i];
		lab[e1.first][e1.second] = WALL;
		
		for(int j=i+1;j<num_of_empty-1;j++)
		{
			e2 = empty[j];
			lab[e2.first][e2.second] = WALL;
			
			for(int k=j+1;k<num_of_empty;k++)
			{
				e3 = empty[k];
				lab[e3.first][e3.second] = WALL;
				
				int	infected = count_infection();
				
				if( num_of_empty-3-infected > max_empty )
				{
					max_empty = num_of_empty-3-infected;
				}
				
				lab[e3.first][e3.second] = EMPTY; 
			}
			
			lab[e2.first][e2.second] = EMPTY;
		}
		
		lab[e1.first][e1.second] = EMPTY;
	}
	printf("%d\n",max_empty);
	
	return	0;
}
