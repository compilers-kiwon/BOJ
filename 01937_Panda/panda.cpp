#include	<cstdio>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(500+1)

#define	UP		0
#define	DWON	1
#define	LEFT	2
#define	RIGHT	3
#define	MAX_DIR	4

#define	IN_RANGE(MIN,V,MAX)	(((MIN)<=(V))&&((V)<=(MAX)))

struct	_MOVE{
	int	row,col;
} move_dir[MAX_DIR] = {{-1,0},{1,0},{0,-1},{0,1}};

int	bamboo_map[MAX_SIZE][MAX_SIZE];
int	day[MAX_SIZE][MAX_SIZE];
int	n,K;

priority_queue< pair< int,pair<int,int> > >	bq;

void	update_day_info(int current_row,int current_col,int current_day,int current_bamboo)
{
	for(int i=UP;i<=RIGHT;i++)
	{
		int	next_row,next_col,next_day;
		
		next_row = current_row+move_dir[i].row;
		next_col = current_col+move_dir[i].col;
		
		if( IN_RANGE(1,next_row,n) == true && IN_RANGE(1,next_col,n) == true )
		{
			if( current_bamboo < bamboo_map[next_row][next_col] )
			{
				if( current_day+1 > day[next_row][next_col] )
				{
					day[next_row][next_col] = current_day+1;
				}
			}
		}
	}
}

int		main(void)
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&bamboo_map[i][j]);
			
			pair<int,int> tmp = make_pair(i,j);
			bq.push(make_pair(-bamboo_map[i][j],tmp));
		}
	}
	
	for(K=0;bq.size()!=0;)
	{
		int	current_row,current_col,current_day,current_bamboo;
		
		current_bamboo = -bq.top().first;
		current_row = bq.top().second.first;
		current_col = bq.top().second.second;
		bq.pop();
		
		if( day[current_row][current_col] == 0 )
		{
			current_day = 1;
		}
		else
		{
			current_day = day[current_row][current_col];
		}
		
		K = max(K,current_day);
		
		update_day_info(current_row,current_col,current_day,current_bamboo);
	}
	printf("%d\n",K);
		
	return	0;
}
